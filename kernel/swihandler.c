// Pengcheng Sun <pengches@andrew.cmu.edu>

#include "swihandler.h"


int install_swi_handler(unsigned *vector,unsigned *handler,unsigned *S_Handler, unsigned *original_1, unsigned *original_2){

	unsigned  offset;
	unsigned  *s_vector;
	unsigned  *s_handler;
	

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



int swi_handler(int swi_number){

	//get swi number
	swi_number = swi_number & 0x00ffffff;

	switch(swi_number){
	
		case WRITE_SWI:return -1;break;
		case READ_SWI:return 0;break;
		case EXIT_SWI:return 1;break;
		default: printf("Invalid software interrupt number!\n");return error_status;break;

	}
}


ssize_t read_handler(int fd, void *buf, size_t count){
	char ch;
	size_t read_count=0;

 	char *read_buf = (char *)buf;

	if(fd != STDIN_FILENO){ //invalid fileno
		return -EBADF;
	}

	if((unsigned)buf>= ram_lower_bound && (unsigned)buf + count - 1 <= ram_upper_bound){ // if within valid stack range
		while(count!=0){
			ch = getc();
			switch(ch){

				case 4: return read_count;  //EOF
				case 8:   		
						puts("\b \b");			//backspace
						if(read_count>0){
							read_count--;
							read_buf--;
							
						}
						break;
				case 127: 		
						puts("\b \b");			//delete
						if(read_count>0){
							read_count--;
							read_buf--;
							
						}
						break;
				case 10: ch='\n';*read_buf = ch;read_count++;read_buf++;putc('\n');return read_count;  //newline
				case 13: ch='\n';*read_buf = ch; read_count++;read_buf++;putc('\n');return read_count;	//carriage return
				default: *read_buf = ch; read_count++;read_buf++;putc(ch);break;
			}

			count--;

		}
		
		return read_count;
	}
	else{
		return -EFAULT;
	}
}


ssize_t write_handler(int fd, const void* buf, size_t count){
	
	size_t write_count=0;


	char *write_buf = (char *)buf;

	if(fd!=STDOUT_FILENO){ //if invalid fileno
		
		return -EBADF;
	}
	if(((unsigned)buf >= ram_lower_bound && (unsigned)buf + count -1 <= ram_upper_bound) || (unsigned)buf + count - 1 <= rom_upper_bound){ // if within valid stack range

		while(count != 0){
			putc(*write_buf);
			write_buf++;
			count--;
			write_count++;
		}

		return write_count;

	}
	else{
		return -EFAULT;
	}

}


