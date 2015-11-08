@Pengcheng Sun <pengches@andrew.cmu.edu>

#include <bits/swi.h>

#include "constant.h"

	.file "setup.S"
	.text

	.comm SVC_R8 4,4
	.comm SVC_SP 4,4
	.global setup

setup:
	stmfd sp!,{r4-r7,r9-r12,lr} @save callee saved registers
	ldr r2, =SVC_R8
	str r8, [r2]
	ldr r2, =SVC_SP
	str sp, [r2]

	mrs r2,cpsr
	bic r2,r2, #0x1
	msr cpsr,r2
	ldr sp, =irq_stack_top
	orr r2,r2, #0x1
	msr cpsr, r2

	mrs r2,cpsr			  @change cpsr to get into user mode
	stmfd sp!,{r2}		  @store cpsr
	stmfd sp!,{r8}        @store r8
	orr r2,r2,#0x50
	bic r2,r2,#0x8f
	msr cpsr,r2

	ldr sp,=user_stack_top @set user stack

	ldr r5,=user_entry     @load user function entry address
	mov lr,pc			   @set return address
	mov pc,r5

	swi EXIT_SWI




