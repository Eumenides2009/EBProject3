/** @file splat.c
 *
 * @brief Displays a spinning cursor.
 *
 * Links to libc.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv)
{
	/* Add code here -- put your names at the top. */

	
	

	while(1){

		printf("\b \b|");
		sleep(200);
		printf("\b \b/");
		sleep(200);
		printf("\b \b-");
		sleep(200);
		printf("\b \b\\");
		sleep(200);
	}

	return 0;
}
