@ crt0.S: Execution startup routine
@
@ Authors: Group Member 1 <email address>
@          Group Member 2 <email address>
@ Date:    The current time & date
#include <bits/swi.h>
	.file	"crt0.S"
	.text

	.global	_start
	.extern main
_start:
	@ Needs more code.

	
	stmfd sp!,{r1-r3}	
	bl main                 @jump to main
	ldmfd sp!, {r1-r3}        @restore r1,r2,r3
	b exit           @exit
