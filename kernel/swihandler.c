// Pengcheng Sun <pengches@andrew.cmu.edu>

#include "swihandler.h"


extern volatile unsigned long kernel_time;

int swi_handler(int swi_number){

	//get swi number
	swi_number = swi_number & swi_mask;

	switch(swi_number){
	
		case WRITE_SWI:return write_swi_return;break;
		case READ_SWI:return read_swi_return;break;
		case EXIT_SWI:return exit_swi_return;break;
		case TIME_SWI:return  time_swi_return;break;
		case SLEEP_SWI:return sleep_swi_return;break;
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



unsigned long time_handler(void){
	

	return kernel_time;

}


void sleep_handler(unsigned long millis){
	

	unsigned long target = kernel_time + millis;

	while(kernel_time <= target);

	return ;
}
