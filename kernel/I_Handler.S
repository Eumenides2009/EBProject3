

	.file "I_Handler.S"
	.text
	.global I_Handler


start:

	stmfd sp!,{r1-r12,lr}
	bl irq_handler
	ldmfd sp!,{r1-r12,lr}
	subs pc,lr,#4

I_Handler:
	.word start











	
