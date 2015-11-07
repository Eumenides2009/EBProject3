@Pengcheng Sun <pengches@andrew.cmu.edu>

#include <bits/swi.h>

#define user_stack_top 0xa3000000
#define user_entry 0xa2000000

	.file "setup.S"
	.text

	.global setup

setup:
	stmfd sp!,{r4-r12,lr} @save callee saved registers

	mrs r2,cpsr			  @change cpsr to get into user mode
	stmfd sp!,{r2}		  @store cpsr
	stmfd sp!,{r8}        @store r8
	orr r2,r2,#0xd0
	bic r2,r2,#0x0f
	msr cpsr,r2

	ldr sp,=user_stack_top @set user stack

	ldr r5,=user_entry     @load user function entry address
	mov lr,pc			   @set return address
	mov pc,r5

	swi EXIT_SWI




