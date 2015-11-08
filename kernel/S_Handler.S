@Pengcheng Sun <pengches@andrew.cmu.edu>

#include "constant.h"

	.file "S_Handler.S"
	.text

	.global S_Handler



start:
	stmfd sp!,{r0-r12,lr}  @store non-banked registers
	
	mrs r1,cpsr
	and r1,r1, #0xffffff7f
	msr cpsr,r1



	ldr r0,[lr, #-4]		   @get swi number
	
	bl swi_handler         @judge swi type
	cmp r0, #exit_swi_return
	beq .exit
	cmp r0, #read_swi_return
	beq .read
	cmp r0, #write_swi_return
	beq .write
	cmp r0, #time_swi_return
	beq .time

.sleep:
	ldmfd sp!,{r0-r12,lr}  @recover non-banked registers
	stmfd sp!,{r1-r12,lr}  @save non-banker registers again 
	ldr r8, =SVC_R8
	ldr r8,[r8]
	bl sleep_handler	
    b .normal_exit

.time:
	ldmfd sp!,{r0-r12,lr}  @recover non-banked registers
	stmfd sp!,{r1-r12,lr}  @save non-banker registers again 
	ldr r8, =SVC_R8
	ldr r8,[r8]
	bl time_handler
	b .normal_exit

.read:
	ldmfd sp!,{r0-r12,lr}  @recover non-banked registers
	stmfd sp!,{r1-r12,lr}  @save non-banker registers again 
	ldr r8, =SVC_R8
	ldr r8,[r8]
	bl read_handler
	b .normal_exit

.write:
	ldmfd sp!,{r0-r12,lr}  @recover non-banked registers
	stmfd sp!,{r1-r12,lr}  @save non-banker registers again 
	ldr r8, =SVC_R8
	ldr r8,[r8]
	bl write_handler
	b .normal_exit

.exit:
	ldmfd sp!,{r0-r12,lr}  @recover non-banked registers
	ldr r8, =SVC_R8
	ldr r8,[r8]
	b exit_handler

.normal_exit:
	ldmfd sp!,{r1-r12,lr}  @recover non-banked registers
	movs pc,lr             @return to user mode

S_Handler:
	.word start

