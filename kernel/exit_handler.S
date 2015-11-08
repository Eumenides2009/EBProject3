@ Pengcheng Sun <pengches@andrew.cmu.edu>
	
	.file "exit_handler.S"
	.text

	.global exit_handler

exit_handler:
 	
 	ldr r4, =SVC_SP
 	ldr sp, [r4]
    
	@ldmfd sp!,{r4}         @restore cpsr
	@msr cpsr,r4
	
	ldmfd sp!,{r4-r7,r9-r12,lr}  @restore callee saved registers which are saved in setup
	mov  pc,lr			   @ return to main function in kernel.c



