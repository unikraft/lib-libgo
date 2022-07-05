#!/usr/bin/env python3
#  SPDX-License-Identifier: BSD-3-Clause
#
#  Authors: Marc Rittinghaus <marc.rittinghaus@kit.edu>
#
#  Copyright (c) 2022, Karlsruhe Institute of Technology (KIT)
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions
#  are met:
#
#  1. Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer.
#  2. Redistributions in binary form must reproduce the above copyright
#     notice, this list of conditions and the following disclaimer in the
#     documentation and/or other materials provided with the distribution.
#  3. Neither the name of the copyright holder nor the names of its
#     contributors may be used to endorse or promote products derived from
#     this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
#  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
#  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
#  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
#  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
#  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
#  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
#  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
#  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
#  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
#  POSSIBILITY OF SUCH DAMAGE.
#

import re
import os
import shutil
from collections import OrderedDict
import logging

def extract_version_from_buildcfg(path):
	with open(path, 'r') as f:
		for line in f.readlines():
			if line.startswith('const version = '):
				return line[17:-2]

def vgolib(libname):
	return libname.replace('.','_').replace('/','_').replace('-','_').upper()

RE_GCCGO	= re.compile(r'^libtool: compile:.*gccgo\s')
RE_GCC		= re.compile(r'^libtool: compile:.*xgcc.*/libgo/')
RE_GOSRC	= re.compile(r'\s([a-z0-9_\/\-\.]+\.go)')
RE_CSRC		= re.compile(r'-c\s([a-z0-9_\/\-\.]+\.(?:S|c))')
RE_OUT		= re.compile(r'\s-o\s([a-z0-9_\/\-\.]+)')
RE_FLAGS	= re.compile(r'\s(-fgo-[a-z0-9_\/\-\.=]+)')

MK_RT_HDR	= \
"""# This file has been auto-generated for {}.
# To re-generate navigate to Unikraft application folder
# $ make prepare
# $ cd build/libgo/origin
# $ mkdir gccbuild
# $ cd gccbuild
# $ ../gcc-<GCC_VERSION>/configure --disable-multilib --enable-languages=c,c++,go
# $ make V=1 -j`nproc`| tee build.log
# $ $(LIBGO_BASE)/{}
#
"""

MK_ADDGOLIB	= '$(eval $(call _addgolib,{},{}))\n'
MK_SRCS		= '{}_SRCS += {}\n'
MK_DEPS		= '{}_DEPS += {}\n'
MK_LIBGO_SRCS	= 'LIBGO_SRCS-y += $(LIBGO_EXTRACTED)/{}\n'

BUILD_LOG	= './build.log'
BUILD_DIR	= './x86_64-pc-linux-gnu/' # TODO: Adapt to other architectures as well
BASE_DIR	= os.path.dirname(__file__) + '/..'
LIBGO_DIR	= BASE_DIR + '/libgo'
MK_RT_UK	= LIBGO_DIR + '/Makefile.runtime.uk'
MK_NT_UK	= LIBGO_DIR + '/Makefile.native.uk'
PACKAGES_IDX	= LIBGO_DIR + '/packages.idx'

logging.basicConfig(level=logging.INFO)

print('Build directory: {}'.format(BUILD_DIR))
print('Target: {}'.format(BASE_DIR))

pkgs = {}
srcs = []
out = ''
gcc_version = 'unknown'

lines = []
with open(BUILD_LOG, 'r') as bl:
	lines = bl.readlines()

for line in lines:
	# Check if this is a *.c file needed for libgo
	matches = RE_GCC.findall(line)
	if len(matches) > 0:
		if line.find('-fPIC') >= 0:
			continue

		matches = RE_CSRC.findall(line)
		if len(matches) != 1:
			continue

		source_file = matches[0]
		p = source_file.find('/libgo/')
		if p < 0:
			continue

		source_file = source_file[p + len('/libgo/'):]

		# Sometimes we have the same base name twice.
		# This leads to overriding recipes in the Makefile.
		base_name = os.path.basename(source_file)
		for cfile in srcs:
			c = os.path.basename(cfile)
			if c == base_name:
				source_file += '|libgo'
				break

		srcs.append(source_file)
		continue

	# Check if this is a GO package needed for libgo
	matches = RE_GCCGO.findall(line)
	if len(matches) == 0:
		continue

	# We do not take the build command line for the dynamic library
	if line.find('-fPIC') >= 0:
		continue

	line = line[len(matches[0]):]

	# Extract object file name
	matches = RE_OUT.findall(line)
	if len(matches) != 1:
		continue

	obj = matches[0]

	# We do not need to build the cmd objs for libgo
	if obj.startswith('cmd/'):
		continue

	# Ensure that we have an object (*.o) file here
	if not obj.endswith('.o'):
		continue

	pkgs[obj] = []
	pkg = obj[:-2]
	libprefix = vgolib(pkg)

	# Start constructing the build rule for the package
	out_lib = ''

	# Extract dependency and source file information
	# We parse the *.lo.dep file from the build for this
	# To make sure, we do a sanity check by also parsing the
	# build log
	src_files = RE_GOSRC.findall(line)

	dep_line = ''
	dep_path = BUILD_DIR + 'libgo/' + obj[:-1] + 'lo.dep'
	with open(dep_path, 'r') as depf:
		dep_line = depf.readline().strip()

	for dep in dep_line.split(' ')[1:]:
		if dep.endswith('.gox'):
			pkgs[obj].append(dep[:-3] + 'o')
			out_lib += MK_DEPS.format(libprefix, dep[:-4])
			continue

		if not dep in src_files:
			logging.warn('{} not found in log for {}'.format(dep, pkg))

		src_files.remove(dep)

		p = dep.find('/libgo/')
		if p >= 0:
			# A regular source file
			out_lib += MK_SRCS.format(libprefix, '$(LIBGO_EXTRACTED)/' + dep[p + 7:])
			continue

		# This is probably one of the files that are generated.
		# We copy these files to the libgo folder in lib-libgo
		if dep.find('/') == -1:
			logging.info('Importing generated file "{}"'.format(dep))
			path = BUILD_DIR + '/libgo/' + dep

			# This file contains version information. Extract them.
			if dep == 'buildcfg.go':
				gcc_version = extract_version_from_buildcfg(path)

			# Copy the generated file to the library
			#shutil.copy(path, LIBGO_DIR + '/' + dep)

			out_lib += MK_SRCS.format(libprefix, '$(LIBGO_BASE)/libgo/' + dep)
			continue

		logging.warn('{} has unknown path. Ignoring.'.format(dep))

	if len(src_files) > 0:
		logging.warn('Additional sources in log for {}'.format(pkg))

	# Check for additional flags
	flags = ''
	matches = RE_FLAGS.findall(line)
	for flag in matches:
		if flag.startswith('-fgo-pkgpath'):
			continue

		flags += ' ' + flag
		logging.info('Additional flag for {}:{}'.format(pkg, flag))

	out += MK_ADDGOLIB.format(pkg, flags.strip()) + out_lib

out = MK_RT_HDR.format(gcc_version, os.path.basename(__file__)) + out

# Write Makefile.runtime.uk
with open(MK_RT_UK, 'w') as pf:
	pf.write(out)

# Write packages.idx
pidx_text = ''
for (obj, deps) in OrderedDict(sorted(pkgs.items())).items():
	pidx_text += obj[:-2]
	for dep in deps:
		pidx_text += ' ' + dep[:-2]
	pidx_text += '\n'

with open(PACKAGES_IDX, 'w') as spf:
	spf.write(pidx_text)

# Write Makefile.native.uk
srcs.sort()
with open(MK_NT_UK, 'w') as sf:
	for cfile in srcs:
		sf.write(MK_LIBGO_SRCS.format(cfile))
