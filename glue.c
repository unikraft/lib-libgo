/* SPDX-License-Identifier: BSD-3-Clause */
/*
 *
 * Authors: Charalampos Mainas <charalampos.mainas@neclab.eu>
 *
 *
 * Copyright (c) 2019, NEC Europe Ltd., NEC Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * THIS HEADER MAY NOT BE EXTRACTED OR MODIFIED IN ANY WAY.
 */

/*
 * stubs
 */

#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <sys/mman.h>
#include <sys/statfs.h>
#include <sys/stat.h>
#include <uk/essentials.h>
#include <pte_types.h>

int epoll_create(int size __unused)
{
	return 0;
}

int epoll_ctl(int epfd __unused, int op __unused, int fd __unused, struct epoll_event *event __unused)
{
	return 0;
}

int epoll_wait(int epfd __unused, struct epoll_event *events __unused, int maxevents __unused, int timeout __unused)
{
	return 0;
}

int madvise(void *addr __unused, size_t length __unused, int advice __unused)
{
	return 0;
}

int mincore(void *addr __unused, size_t length __unused, unsigned char *vec __unused)
{
	return 0;
}

int prctl(int option __unused, unsigned long arg2 __unused, unsigned long arg3 __unused, unsigned long arg4 __unused, unsigned long arg5 __unused)
{
	return 0;
}

int pthread_sigmask(int how __unused, const sigset_t *set __unused, sigset_t *oldset __unused)
{
	return 0;
}

long ptrace(void)
{
	return 0;
}

int reboot(int magic __unused, int magic2 __unused, int cmd __unused, void *arg __unused)
{
	return 0;
}

int sched_getaffinity(void)
{
	return 0;
}

int setitimer(int which __unused, const struct itimerval *new_value __unused, struct itimerval *old_value __unused)
{
	return 0;
}

int settimeofday(const struct timeval *tv __unused, const struct timezone *tz __unused)
{
	return 0;
}

#undef sigaddset
int sigaddset(sigset_t *set __unused, int signum __unused)
{
	return 0;
}

int sigaltstack(const stack_t *ss __unused, stack_t *old_ss __unused)
{
	return 0;
}

#undef sigdelset
int sigdelset(sigset_t *set __unused, int signum __unused)
{
	return 0;
}

#undef sigemptyset
int sigemptyset(sigset_t *set __unused)
{
	return 0;
}

#undef sigfillset
int sigfillset(sigset_t *set __unused)
{
	return 0;
}

long syscall(long number __unused, ...)
{
	return 0;
}

ssize_t sendfile64(int out_fd __unused, int in_fd __unused, off_t *offset  __unused, size_t  count __unused)
{
	return 1;
}

int getgrouplist(const char *user __unused, gid_t group __unused, gid_t *groups __unused, int *ngroups __unused)
{
	return 0;
}

int getgrnam_r(const char *name __unused, struct group *grp __unused,
		char *buf __unused, size_t buflen __unused, struct group **result __unused)
{
	return 0;
}
int getgrgid_r(gid_t gid __unused, struct group *grp __unused,
		char *buf __unused, size_t buflen __unused, struct group **result __unused)
{
	return 0;
}

void uk_syscall_fn___NR_clone(void)
{
}

/*
 * Glue code
 */

#include <ucontext.h>
#include <uk/sched.h>
#include <uk/thread.h>
#include <uk/asm/limits.h>

#define __errno_location __errno

void makecontext1 (ucontext_t *__ucp, void (*__func) (void), int __argc, ...)
{
	struct uk_thread *current = uk_thread_current();
	*((unsigned long *) __ucp->uc_stack.ss_sp) = (unsigned long) current;
	makecontext(__ucp, __func, __argc);
}

void *alloc_stack()
{
	struct uk_sched *sched = uk_sched_get_default();
	void *stack;

	uk_posix_memalign(sched->allocator,
			  &stack, __STACK_SIZE, __STACK_SIZE);
	if (stack == NULL)
		printf("error allocating stack\n");
	return stack;
}

size_t get_stack_size(void)
{
	return __STACK_SIZE;
}

