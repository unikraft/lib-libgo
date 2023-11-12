// SPDX-License-Identifier: BSD-3-Clause
/*
 * Goroutine context switch for AArch64
 *
 * Authors: Eduard Vintilă <eduard.vintila47@gmail.com>
 *
 * Copyright (c) 2023, University of Bucharest. All rights reserved.
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
 */



#if defined(__ARM_64__)

/*
 * We save the following registers for each Goroutine context switch:
 *
 * x18 -> platform register
 * x19-x28 -> callee saved registers
 * x29 -> frame pointer
 * x30 -> link register (i.e. return PC)
 * sp -> stack pointer
 *
 * Total: 14 regs
 */

#define PC_OFF (12*8)
#define SP_OFF (13*8)

// int __go_getcontext(__go_context_t* context);
//					    x0
.globl __go_getcontext
.text
__go_getcontext:

	/* Save GP-regs */
	stp x19, x20, [x0], #0x10
	stp x21, x22, [x0], #0x10
	stp x23, x24, [x0], #0x10
	stp x25, x26, [x0], #0x10
	stp x27, x28, [x0], #0x10

	/* Save PR and FP */
	stp x18, x29, [x0], #0x10

	/* Save Return PC and SP */
	mov x1, sp
	stp x30, x1, [x0], #0x10

	ret

// int __go_setcontext(__go_context_t* context);
//				    	    x0
.globl __go_setcontext
.text
__go_setcontext:
	/* Set GP-regs */
	ldp x19, x20, [x0], #0x10
	ldp x21, x22, [x0], #0x10
	ldp x23, x24, [x0], #0x10
	ldp x25, x26, [x0], #0x10
	ldp x27, x28, [x0], #0x10

	/* Set PR and FP */
	ldp x18, x29, [x0], #0x10

	/* Set Return PC and SP */
	ldp x30, x1, [x0], #0x10
	mov sp, x1

	ret

//void __go_makecontext(__go_context_t* context, void (*)() fn, void* sp, size_t size);
//                                          x0,             x1,       x2,         x3
.globl __go_makecontext
.text
__go_makecontext:
	/* Allocate space for the stack */
	add x4, x2, x3

	/* Align the stack pointer */
	and x4, x4, #0xfffffffffffffff0

	/* Store SP and PC in the context structure */
	str x4, [x0, #SP_OFF]
	str x1, [x0, #PC_OFF]

	ret

	.section	.note.GNU-split-stack,"",@progbits
	.section	.note.GNU-no-split-stack,"",@progbits

#endif

	.section	.note.GNU-stack,"",@progbits
