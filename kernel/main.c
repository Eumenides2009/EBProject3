

#include "utility.h"

uint32_t global_data;
volatile unsigned long kernel_time;  // kernel up time in miliseconds

extern unsigned *S_Handler;    //address of the custom swi handler
extern unsigned *I_Handler;
extern int setup(int argc, char *argv[]);  //assembly setup routine


int kmain(int argc, char** argv, uint32_t table)
{
	app_startup(); /* bss is valid after this point */
	global_data = table;

	/* Add your code here */


	int status_swi,status_irq,status;	
 	unsigned original_swi_1, original_swi_2,original_irq_1,original_irq_2;  //variables used to store the original swi handler
 	unsigned handler_swi,handler_irq;  // store the address of swi handler
 	unsigned ICMR,ICLR,OIER;

	status_swi = install_handler((unsigned *)EX_SWI,&handler_swi,S_Handler, &original_swi_1,&original_swi_2); //install custom swi handler

	status_irq = install_handler((unsigned *)EX_IRQ,&handler_irq,I_Handler,&original_irq_1,&original_irq_2);

	if(!status_swi && !status_irq){ // if it is a valid load instruction
		
		kernel_time = 0;

		setup_peripheral_device(&ICMR,&ICLR,&OIER);
		
		status=setup(argc,argv); // setup user space
	
		restore_handler((unsigned *)handler_swi,original_swi_1,original_swi_2); // restore original handler

		restore_handler((unsigned *)handler_irq,original_irq_1,original_irq_2);

		restore_peripheral_device(ICMR,ICLR,OIER);

		return status;
	}
	else{ // if it is not a valid load instruction
		printf("Unrecognized instruction.\n");

		return error_status;
	}


}
