@ write.S: write sycall wrapper
@
@ Authors: Group Member 1 <email address>
@          Group Member 2 <email address>
@ Date:    The current time & date
#include <bits/swi.h>


	.file	"write.S"
	.text

	.global	write

write:
	@ Needs more code.
	swi WRITE_SWI 
	cmp r0, #0	             @check the return value of write
	bge .exit	             @if greater of equal than 0, exit normally with this return value
	stmfd sp!,{r6}
    ldr r6, =_errno          @if less than 0, load the address of errno into r6
    rsb r0,r0,#0			 @ get errno = -return
	str r0, [r6]             @ then load the error value into errno
	ldmfd sp!, {r6}          @ restore the value of r6
	mov r0, #-1	             @ exit with -1
.exit:
	mov pc,lr	
_errno:
	.word errno      @import the global variable errno
