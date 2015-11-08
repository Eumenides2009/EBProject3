/*
 * rot13.c: ROT13 cipher test application
 *
 * Authors: Group Member 1 <email address>
 *          Group Member 2 <email address>
 * Date:    The current time & date
 */
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
	/* Needs more code. */

	char read_buffer[256];      // read_buffer provided to read function call, this limit one read to 255 characters.
	char write_buffer[256];     // write_buffer provided to write function call, this limit one write to 255 characters.
	char input;			
	int i;
	ssize_t io_size;	   // variable used to contain the returning value of read

	printf("%lu\n",time());
	while((io_size = read(0,read_buffer,255)) > 0){   //if successfully read something
		for(i=0;i<io_size;i++){                   // loop over every chars in read_buffer
			input = read_buffer[i];

			if((input >= 'A' && input <= 'M') || (input >= 'a' && input <= 'm')){    //perform rot13 
				write_buffer[i] = input+13;
			}
			else if((input >= 'N' && input <= 'Z') || (input >= 'n' && input <= 'z')){  //perform rot13
				write_buffer[i] = input -13;
			}
			else{
				write_buffer[i] = input;    // if this char is not in rot13 range, let it unchanged
			}
		}

		io_size = write(1,write_buffer,io_size);    //write to stdout

	}

	if(io_size < 0){   // if return value is less than 0, then return 1 to indicate there is an error happened
		return 1;
	}
	return 0;	// else, read function had encountered EOF, terminate this program normally
}
