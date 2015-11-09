/*
 * Pengcheng Sun
 * Yifan Wu
 * 
 * This is a memory-test game, to test sleep 
 * and time functions. In this game, there are 
 * some numbers flashing on the screen, you need
 * to type the order of the numbers.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <bits/fileno.h>

#define MAX_LENGTH 255
int numbers[10];	//array which stores numbers flashing on the screen.
///////////////////////////////////
/// This function is to print the 
/// test on the screen.
///////////////////////////////////
void print_interface(int test_num){
	/*switch(i){
		case 0:
			printf("\n 11111-22222-33333\n");
			printf("|     |     |     |\n");
			printf(" 44444-55555-66666\n");
			printf("|     |     |     |\n");
			printf(" 77777-88888-99999\n");
			printf("|     |     |     |\n");
			printf("-------------------\n");
			break;
		case 1:
			printf("\n 11111-22222-33333\n");
			printf("|mole!|     |     |\n");
			printf(" 44444-55555-66666\n");
			printf("|     |     |     |\n");
			printf(" 77777-88888-99999\n");
			printf("|     |     |     |\n");
			printf("-------------------\n");
			break;
		case 2:
			printf("\n 11111-22222-33333\n");
			printf("|     |mole!|     |\n");
			printf(" 44444-55555-66666\n");
			printf("|     |     |     |\n");
			printf(" 77777-88888-99999\n");
			printf("|     |     |     |\n");
			printf("-------------------\n");
			break;
		case 3:
			printf("\n 11111-22222-33333\n");
			printf("|     |     |mole!|\n");
			printf(" 44444-55555-66666\n");
			printf("|     |     |     |\n");
			printf(" 77777-88888-99999\n");
			printf("|     |     |     |\n");
			printf("-------------------\n");
			break;
		case 4:
			printf("\n 11111-22222-33333\n");
			printf("|     |     |     |\n");
			printf(" 44444-55555-66666\n");
			printf("|mole!|     |     |\n");
			printf(" 77777-88888-99999\n");
			printf("|     |     |     |\n");
			printf("-------------------\n");
			break;
		case 5:
			printf("\n 11111-22222-33333\n");
			printf("|     |     |     |\n");
			printf(" 44444-55555-66666\n");
			printf("|     |mole!|     |\n");
			printf(" 77777-88888-99999\n");
			printf("|     |     |     |\n");
			printf("-------------------\n");
			break;
		case 6:
			printf("\n 11111-22222-33333\n");
			printf("|     |     |     |\n");
			printf(" 44444-55555-66666\n");
			printf("|     |     |mole!|\n");
			printf(" 77777-88888-99999\n");
			printf("|     |     |     |\n");
			printf("-------------------\n");
			break;
		case 7:
			printf("\n 11111-22222-33333\n");
			printf("|     |     |     |\n");
			printf(" 44444-55555-66666\n");
			printf("|     |     |     |\n");
			printf(" 77777-88888-99999\n");
			printf("|mole!|     |     |\n");
			printf("-------------------\n");
			break;
		case 8:
			printf("\n 11111-22222-33333\n");
			printf("|     |     |     |\n");
			printf(" 44444-55555-66666\n");
			printf("|     |     |     |\n");
			printf(" 77777-88888-99999\n");
			printf("|     |mole!|     |\n");
			printf("-------------------\n");
			break;
		case 9:
			printf("\n 11111-22222-33333\n");
			printf("|     |     |     |\n");
			printf(" 44444-55555-66666\n");
			printf("|     |     |     |\n");
			printf(" 77777-88888-99999\n");
			printf("|     |     |mole!|\n");
			printf("-------------------\n");
			break;
	}*/
	int i=0;
	unsigned long current_time;
	int num=-1;
	switch(test_num){
		case 1:
			for(i=0;i<3;i++){
				current_time = time();
				//Generate random number..
				num = ((int)(current_time%23)+1)%9+1;
				numbers[i]=num;	//store the random number 
				// display it on the screen and last for 
				// a little time.
				printf("%d",numbers[i]);
				sleep(1000);
				printf("\b \b ");
			}
			break;
		case 2:
			for(i=0;i<4;i++){
				current_time = time();
				num = ((int)(current_time%23)+1)%9+1;
				numbers[i]=num;
				printf("%d",num);
				sleep(900);
				printf("\b \b ");
			}
			break;
		case 3:
			for(i=0;i<5;i++){
				current_time = time();
				num = ((int)(current_time%23)+1)%9+1;
				numbers[i]=num;
				printf("%d",num);
				sleep(800);
				printf("\b \b ");
			}
			break;
		case 4:
			for(i=0;i<6;i++){
				current_time = time();
				num = ((int)(current_time%23)+1)%9+1;
				numbers[i]=num;
				printf("%d",num);
				sleep(700);
				printf("\b \b ");
			}
			break;
		case 5:
			for(i=0;i<7;i++){
				current_time = time();
				num = ((int)(current_time%23)+1)%9+1;
				numbers[i]=num;
				printf("%d",num);
				sleep(600);
				printf("\b \b ");
			}
			break;
		case 6:
			for(i=0;i<7;i++){
				current_time = time();
				num = ((int)(current_time%23)+1)%9+1;
				numbers[i]=num;
				printf("%d",num);
				sleep(500);
				printf("\b \b ");
			}
			break;
		case 7:
			for(i=0;i<8;i++){
				current_time = time();
				num = ((int)(current_time%23)+1)%9+1;
				numbers[i]=num;
				printf("%d",num);
				sleep(500);
				printf("\b \b ");
			}
			break;
		case 8:
			for(i=0;i<8;i++){
				current_time = time();
				num = ((int)(current_time%23)+1)%9+1;
				numbers[i]=num;
				printf("%d",num);
				sleep(400);
				printf("\b \b ");
			}
			break;
		case 9:
			for(i=0;i<9;i++){
				current_time = time();
				num = ((int)(current_time%23)+1)%9+1;
				numbers[i]=num;
				printf("%d",num);
				sleep(300);
				printf("\b \b ");
			}
			break;
		case 10:
			for(i=0;i<9;i++){
				current_time = time();
				num = ((int)(current_time%23)+1)%9+1;
				numbers[i]=num;
				printf("%d",num);
				sleep(200);
				printf("\b \b ");
			}
			break;
	}	
}

///////////////////////////////////
/// This function is to print the  
/// report of your performance on 
/// the screen.
///////////////////////////////////
void report_performance(int correct_count,int wrong_count){
	printf("\n\n////////////SUMMARY////////////\n");
	sleep(1000);
	printf("Correct times: ");
	sleep(1000);
	printf("%d\n",correct_count);
	sleep(1000);
	printf("Wrong times: ");
	sleep(1000);
	printf("%d\n",wrong_count);
	sleep(1000);
	// Print the evaluation.
	if(correct_count == 10){
		printf("HOLY SH*T! You are smarter than the god!\n");
	}
	else if(correct_count >= 9){
		printf("GOD LIKE! Your IQ must be above 160.\n");
	}
	else if(correct_count >= 8){
		printf("MONSTER KILL! You are genious.\n");
	}
	else if(correct_count >= 7){
		printf("Whicked Sick! Awesome!.\n");
	}
	else if(correct_count >= 5){
		printf("Just so so. Don't give up.\n");
	}
	else if(correct_count >= 3){
		printf("Ummmm. You didn't perform well in this test. Maybe next time.\n");
	}
	else if(correct_count < 3){
		printf("...You are joking, right?\n");
	}
	sleep(1000);

}
///////////////////////////////////
/// Main function.
///////////////////////////////////
int main(int argc, char** argv)
{
	unsigned long game_start_time;	//the game start time.
	unsigned long current_time;		//current time.
	unsigned long test_start_time;	// the test start time.

	unsigned long correct_order=0;	//the correct order.
	unsigned long input_order=0;	//the order inputed by player.
	int correct_count=0,wrong_count=0;
	int read_count=0;
	int test_num=1;

	char buffer[MAX_LENGTH];

	//initialize the array to store numbers.
	int i=0;
	for (i=0;i<10;i++){
		numbers[i]=-1;
	}

	printf("This is a memory-test game.\n");
	sleep(1000);	
	printf("There are 10 tests.\n");
	sleep(1000);
	printf("In each test, some random numbers flash on the screan. You need to remember the order and rewrite them.\n");
	sleep(3000);
	printf("At the end of this game, you can see the report of your performance.\n\n\n");
	sleep(1000);
	printf("When you are ready, type \"y\"to begin the game. Type other letter to exit the game.\n");
	read_count=read(STDIN_FILENO,buffer,MAX_LENGTH-1);
	if(!((buffer[0]=='y' || buffer[0] == 'Y') && read_count ==2)){
		return 0;
	}

	game_start_time=time();
	while(1){
		while(test_num<=10){	//There are 10 tests.
			printf("test: %d\n",test_num);
			sleep(2000);

			//print the flashing numbers.
			print_interface(test_num);

			printf("\nPlease type the order of numbers(for example: 38257): ");
			test_start_time = time();
			read_count = read(STDIN_FILENO,buffer,MAX_LENGTH-1);
			current_time = time();
			buffer[read_count-1]=0;
			input_order = 0;

			for (i=0;i<10;i++){
				if(buffer[i]==0)
					break;
				// Caculate the input order.
				input_order = input_order*10 + (int)buffer[i]-(int)'0';
			}

			//printf("%lu\n",input_order);

			printf("Time spend: %lu.%lus\n",(current_time-test_start_time)/1000,(current_time-test_start_time)%1000/100);
		
			for(i=0;i<10;i++){
				if(numbers[i]<0)
					break;
				//printf("numbers %d %d %lu\n",i,numbers[i],correct_order);
				//Caculate the correct order.
				correct_order = correct_order*10+numbers[i];
			}
			printf("Correct order is: %lu\n",correct_order);

			//Chech if the input is correct.
			if(input_order==correct_order){
				printf("Correct order.\n");
				correct_count++;
			}
			else {
				printf("Oh on, wrong order.\n");
				wrong_count++;
			}

			//clear up the numbers.
			for (i=0;i<10;i++){
				numbers[i]=-1;
			}
			sleep(2000);
			correct_order=0;
			test_num++;
		}

		report_performance(correct_count,wrong_count);

		printf("\nPress 'y' to try again. Press others to exit.");
		read_count=read(STDIN_FILENO,buffer,MAX_LENGTH-1);
		if(!((buffer[0]=='y' || buffer[0] == 'Y') && read_count ==2)){
			return 0;
		}
		test_num=1;
	}
	return 0;
}



