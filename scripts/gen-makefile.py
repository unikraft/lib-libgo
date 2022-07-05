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

import argparse
import os
import json
import logging
import subprocess
import errno
import sys

def go_list(lib_dir, files):
	args = ['go', 'list', '--json', '-a', '--compiler=gccgo', '--deps']
	for file in files:
		if file.endswith('.go'):
			args.append(file)

	logging.debug(' '.join(args))

	env = os.environ.copy()
	env['LD_LIBRARY_PATH'] = '/usr/lib64/'
	#env['GOPATH'] = opt.build_dir

	p = subprocess.run(args, stdout=subprocess.PIPE,
			   stderr=subprocess.PIPE, cwd=lib_dir, env=env)
	if p.returncode != 0:
		raise Exception('go list failed ({}):\n{}'.format(p.returncode,
			p.stderr.decode('UTF-8')))

	# The output from go list produces only valid json for each package but
	# otherwise just concatenates the output. We wrap these individual
	# json outputs with a top json structures that creates an array
	json_text = '{ "packages" : ['\
		+ p.stdout.decode('UTF-8').replace('}\n{','},{')\
		+ '] }'

	return json_text

def vgolib(libname):
	libname = libname.replace('.','_')
	libname = libname.replace('/','_')
	libname = libname.replace('-','_')
	return libname.upper()

def vgosymv3(symbol):
	symbol = symbol.replace('_', '__')
	symbol = symbol.replace('.', '_0')
	symbol = symbol.replace('/', '_1')
	symbol = symbol.replace('*', '_2')
	symbol = symbol.replace(',', '_3')
	symbol = symbol.replace('{', '_4')
	symbol = symbol.replace('}', '_5')
	symbol = symbol.replace('[', '_6')
	symbol = symbol.replace(']', '_7')
	symbol = symbol.replace('(', '_8')
	symbol = symbol.replace(')', '_9')
	symbol = symbol.replace('"', '_a')
	symbol = symbol.replace(' ', '_b')
	symbol = symbol.replace(';', '_c')
	return symbol

# Format string constants
MK_LINKGOLIB	= '$(eval $(call _linkgolib,{}))\n'
MK_ADDGOLIB	= '$(eval $(call _addgolib,{},,y))\n'
MK_SRCS		= '{}_SRCS += {}\n'
MK_DEPS		= '{}_DEPS += {}\n'
MK_CFLAGS	= '{}_CFLAGS += {}\n'

# Directory constants
BASE_DIR	= os.path.dirname(__file__) + '/..'
LIBGO_DIR	= BASE_DIR + '/libgo'
PACKAGES_IDX	= LIBGO_DIR + '/packages.idx'

# Standard package reference
SPR_DEF		= 0 # Regular reference to std pkg
SPR_FORCE	= 1 # Project overrides std pkg but we force it anyways
SPR_OVERRIDE	= 2 # Project overrides std pkg
SPR_INDIRECT	= 3 # Referenced indirectly by other standard package

parser = argparse.ArgumentParser(description='Generates a makefile ')
parser.add_argument('-v', default=False, action='store_true',
		    help='Print executed commands')
parser.add_argument('-o', dest='out', default=None,
		    help='Output path')
parser.add_argument('-b', dest='prefer_builtin', default=None, action='store_true',
		    help='Prefer builtin standard packages over external versions')
egroup = parser.add_mutually_exclusive_group(required=False)
egroup.add_argument('-j', dest='json', default=False, action='store_true',
		    help='Dump JSON from go list instead of generating a Makefile')
egroup.add_argument('-s', dest='std', default=False, action='store_true',
		    help='Dump dependencies on standard packages instead of generating a Makefile')
parser.add_argument('lib_name',
		    help='Name of the library')
parser.add_argument('lib_dir',
		    help='Source directory of the library')
parser.add_argument('files', nargs='+',
		    help='Entrance *.go files of the library')
opt = parser.parse_args()

if opt.v:
	logging.basicConfig(level=logging.DEBUG)
else:
	logging.basicConfig(level=logging.INFO)

lib_dir = os.path.abspath(opt.lib_dir)
if not os.path.exists(lib_dir):
	parser.error('{} not found'.format(lib_dir))

libprefix = vgolib(opt.lib_name)

# Load index of std packages
std_pkgs = {}
with open(PACKAGES_IDX, 'r') as f:
	lines = f.readlines()
	for line in lines:
		pkgs = line.rstrip().split(' ')
		std_pkgs[pkgs[0]] = pkgs[1:] if len(pkgs) > 1 else []

std_pkgs['unsafe'] = []
ignore_pkgs = ['unsafe']

# We start with the entrance file(s) and request information on all
# dependencies for these files using `go list`. This will implicitly download
# all dependencies and we receive lists of files necessary to build the
# respective packages
out = ''

try:
	build_info = go_list(opt.lib_dir, opt.files)
	if opt.json:
		out = build_info
	else:
		build_info = json.loads(build_info)

		std_deps = {}
		for pkg in build_info['packages']:
			if pkg['ImportPath'] in std_pkgs:
				if not ('GoFiles' in pkg or 'CFiles' in pkg):
					std_deps[pkg['ImportPath']] = SPR_DEF
					continue

				# This is package path of a standard library
				# but we have source files specified for this.
				# So this overrides the standard package.
				if opt.prefer_builtin:
					std_deps[pkg['ImportPath']] = SPR_FORCE
					continue

				std_deps[pkg['ImportPath']] = SPR_OVERRIDE

			if opt.std:
				continue

			# Check if this is the package that was specified with
			# the entrance files. In that case, add all dependencies
			if ('Target' in pkg or
			   (pkg['ImportPath'] == opt.lib_name or
			    pkg['ImportPath'] == 'command-line-arguments')):
				if not 'Deps' in pkg:
					continue

				for dep in pkg['Deps']:
					if dep in ignore_pkgs:
						continue

					out += MK_DEPS.format(libprefix, dep)

				continue

			# This is a some dependency package. Create a new GO
			# library registration for the package and add the
			# source files to it
			pkglibprefix = vgolib(pkg['ImportPath'])
			out += MK_ADDGOLIB.format(pkg['ImportPath'])

			files = pkg['GoFiles'] if 'GoFiles' in pkg else []

			# There are C files in this package. Then also define
			# GOPKGPATH
			if 'CFiles' in pkg:
				files.extend(pkg['CFiles'])
				out += MK_CFLAGS.format(pkglibprefix,
					'-D "GOPKGPATH=\\"' +
					vgosymv3(pkg['ImportPath']) + '\\""')

			for f in files:
				path = pkg['Dir'] + '/' + f
				if not os.path.exists(path):
					raise FileNotFoundError(errno.ENOENT,
						os.strerror(errno.ENOENT), path)

				out += MK_SRCS.format(pkglibprefix, path)

			# Add the package's dependencies
			if 'Deps' in pkg:
				for dep in pkg['Deps']:
					if dep in ignore_pkgs:
						continue

					out += MK_DEPS.format(pkglibprefix, dep)

		# Resolve dependencies on standard packages
		while True:
			l = len(std_deps.items())

			# Iterate over dependencies and add indirect
			# dependencies
			for (pkg, flag) in std_deps.copy().items():
				if flag == SPR_OVERRIDE:
					continue

				for dep in std_pkgs[pkg]:
					if dep in std_deps:
						continue

					std_deps[dep] = SPR_INDIRECT

			# If we did not add anything during this round
			# we have fully resolved dependencies
			if l == len(std_deps.items()):
				break

		# Add standard package dependencies to link
		for (pkg, flag) in std_deps.items():
			if opt.std:
				ext = ''

				if flag == SPR_FORCE:
					ext = ' [FORCE]'
				elif flag == SPR_OVERRIDE:
					ext = ' [OVERRIDE]'
				elif flag == SPR_INDIRECT:
					ext = ' [INDIRECT]'

				out += pkg + ext + '\n'
				continue

			if flag == SPR_OVERRIDE:
				continue

			if pkg in ignore_pkgs:
				continue

			out += MK_LINKGOLIB.format(pkg)

except Exception as e:
	logging.fatal(e.args[0])
	sys.exit()

# Write the output either to stdout or the specified output file
if opt.out == None:
	print(out)
else:
	with open(opt.out, 'w') as f:
		f.write(out)
