/*
 * kernel.c: Kernel main (entry) function
 *
 * Author: Pengcheng Sun <pengches@andrew.cmu.edu>
 *         
 * Date:   The current time & date
 */
#include <exports.h>
#include "swihandler.h"



extern unsigned *S_Handler;    //address of the custom swi handler
extern int setup(int argc, char *argv[]);  //assembly setup routine

int main(int argc, char *argv[]) {
	
 	int status;	
 	unsigned original_1, original_2;  //variables used to store the original swi handler
 	unsigned handler;  // store the address of swi handler

	status = install_swi_handler((unsigned *)vector_entry,&handler,S_Handler, &original_1,&original_2); //install custom swi handler

	if(!status){ // if it is a valid load instruction
		
		status=setup(argc,argv); // setup user space
	
		restore_handler((unsigned *)handler,original_1,original_2); // restore original handler

		return status;
	}
	else{ // if it is not a valid load instruction
		printf("Unrecognized instruction.\n");

		return error_status;
	}
}



