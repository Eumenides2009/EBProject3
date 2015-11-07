@Pengcheng Sun <pengches@andrew.cmu.edu>

	.file "S_Handler.S"
	.text

	.global S_Handler



start:
	stmfd sp!,{r0-r12,lr}  @store non-banked registers
	ldr r0,[lr,#-4]		   @get swi number
	ldr r8,[sp,#56]	   @restore r8
	bl swi_handler         @judge swi type
	cmp r0,#0
	ldmfd sp!,{r0-r12,lr}  @recover non-banked registers

	stmfd sp!,{r1-r12,lr}  @save non-banker registers again 
	beq .read
	blt .write
	bgt .exit

.read:
	bl read_handler
	b .normal_exit

.write:
	bl write_handler
	b .normal_exit

.exit:
	ldmfd sp!,{r1-r12,lr}  @recover non-banked registers
	b exit_handler

.normal_exit:
	ldmfd sp!,{r1-r12,lr}  @recover non-banked registers
	movs pc,lr             @return to user mode

S_Handler:
	.word start

