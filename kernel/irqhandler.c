#include "irqhandler.h"

extern volatile unsigned long kernel_time;

void irq_handler(void){

	if((reg_read(INT_ICPR_ADDR) & (INT_ICCR_DIM << INT_OSTMR_0)) && (reg_read(OSTMR_OSSR_ADDR) & OSTMR_OSSR_M0)){

		kernel_time += irq_elapse_time;

		reg_write(OSTMR_OSMR_ADDR(0), reg_read(OSTMR_OSCR_ADDR) + irq_elapse_count);

		reg_set(OSTMR_OSSR_ADDR, OSTMR_OSSR_M0);

	}

	return ;
}	


