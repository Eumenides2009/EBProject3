#include "utility.h"

int install_handler(unsigned *vector,unsigned *handler,unsigned *S_Handler, unsigned *original_1, unsigned *original_2){

	unsigned  offset;
	unsigned  *s_vector;
	unsigned  *s_handler;
	
	vector = (unsigned *)((unsigned )vector * 4);

	printf("%p\n",vector);

	if(((*vector) & 0xfffff000) == load_inc_ins){ //if this is a load instruction with positive offset
		offset = (*vector) & 0x00000fff;
		s_vector = (unsigned *)((unsigned)vector+0x8+offset);


	}
	else if(((*vector) & 0xfffff000) == load_dec_ins){ //if this is a load instruction with negative offset
		offset = (*vector) & 0x00000fff;
		s_vector = (unsigned *)((unsigned)vector+0x8-offset);

	}
	else{
		return 1;
	}

	printf("store hanlder!!\n");
	// get the actual address of swi handler
	*handler = *s_vector;
	s_handler =(unsigned *)(*s_vector);

	//store original swi handler
	*original_1 = *s_handler;
	*original_2 = *(s_handler+1);

	//write new swi handler
	*s_handler = load_dec_ins | 0x4;
	*(s_handler+1) = (unsigned)S_Handler;

	return 0;
}


void restore_handler(unsigned *handler,unsigned original_1, unsigned original_2){


	//restore swi handler
	*handler = original_1;
	*(handler+1) = original_2;

}


void setup_peripheral_device(unsigned *ICMR, unsigned *ICLR, unsigned *OIER){

	*ICMR = reg_read(INT_ICMR_ADDR);
	*ICLR = reg_read(INT_ICLR_ADDR);
	*OIER = reg_read(OSTMR_OIER_ADDR);

	reg_write(INT_ICMR_ADDR,INT_ICCR_DIM<<INT_OSTMR_0);
	reg_write(INT_ICLR_ADDR,0x0);


	reg_clear(OSTMR_OIER_ADDR,OSTMR_OIER_E0|OSTMR_OIER_E1|OSTMR_OIER_E2|OSTMR_OIER_E3);
	reg_set(OSTMR_OIER_ADDR,OSTMR_OIER_E0);
	reg_write(OSTMR_OSMR_ADDR(0),reg_read(OSTMR_OSCR_ADDR)+irq_elapse_count);



}


void restore_peripheral_device(unsigned ICMR, unsigned ICLR, unsigned OIER){

	reg_write(INT_ICMR_ADDR,ICMR);
	reg_write(INT_ICLR_ADDR,ICLR);
	reg_write(OSTMR_OIER_ADDR,OIER);
}


