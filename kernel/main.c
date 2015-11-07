#include <exports.h>

#include <arm/psr.h>
#include <arm/exception.h>
#include <arm/interrupt.h>
#include <arm/timer.h>

#include "swihandler.h"
uint32_t global_data;

extern unsigned *S_Handler;    //address of the custom swi handler
extern int setup(int argc, char *argv[]);  //assembly setup routine


int kmain(int argc, char** argv, uint32_t table)
{
	app_startup(); /* bss is valid after this point */
	global_data = table;

	/* Add your code here */


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
