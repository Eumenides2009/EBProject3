/** @file typo.c
 *
 * @brief Echos characters back with timing data.
 *
 * Links to libc.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <bits/fileno.h>

#define MAX_LENGTH 255

int main(int argc, char** argv)
{
	/* Add code here -- put your names at the top. */
	unsigned long old_time;
	unsigned long new_time;

	char buffer[MAX_LENGTH];
	
	while(1){

		printf("Defense of the Ancients > ");

		old_time = time();

		read(STDIN_FILENO,buffer,MAX_LENGTH);

		new_time = time();

		printf("%s%lu.%lus\n",buffer,(new_time-old_time)/1000,(new_time-old_time)%1000/100);

	}
	return 0;
}
