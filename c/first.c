#include <stdio.h>//general
#include <stdbool.h>//bool flag, ture, false

#define INCHES_PER_POUND (1.0f/2.0f)

int main(void)
{

	printf("To C, or not to C: that is the question.\n");
	

/*********************************************************************************
 * To run this program, just "gcc first.c".                                      *
 *This step would create a file named "a.out", then just type "./a.out".         *
 *If you'd like to create another name to replace the "a.out", just use the      *
 *command line "gcc -o first first.c", this time you'd see a file named "first", *
 *then the same procejure "./first".                                             *
 ********************************************************************************/                  

/********--------------------scanf--------------------------------------------------******/
	
	int density, density2, height = 12;
	int weight = 1;
	
	printf("how much is the density: ");
	scanf("%d /%d" , &density, &density2);
	
	
	printf("the volume is %.2f\n", INCHES_PER_POUND * height * weight * density * density2);

/*****************------------------------if--------------------------------------------****/
	int i, j, k, max;
	printf("the next line: ");
	scanf("%d%d%d", &i, &j, &k);
	
	if (i > j){
		if (i > k){
			max = i;
		} else {
			max = i;
		}
	} else{
		if (j > k){
			max = j;
		} else{
			max = k;
		}
	}
	
	printf("the max of i j k is %d\n", max);	
/************************************************************************************
 * if(**){******}                                                                   *
 * else if(**){******}                                                              *
 * else{******}                                                                     *
 * i > j ? i : j  conditional expression. (if i > j, then i; else j.)               *
 * **********************************************************************************/


/*************************************************************************************/
	
	bool flag = false;

/*************------------------------------switch------------------------------************/

//To replace the max program above, this time I choose "switch".
	
	switch ((i <= j) + (i == j)) {
		case 0: printf("the max of i and j is %d.\n", i);
			break;
		case 2: printf("the two numbers(i and j) are the same.\n");
			break;
		case 1: printf("the max of i and j is %d.\n", j);
			break;
		default:printf("error!\n");
	}

/************************************************************************************
 * To compare the 3 numbers, just compare two, then multiply 100, then the next two,*
 * multiply 10, then the third two, at last just add, and test which one is one.    *
 * Keep in mind with this, to represent i < j < k, (i < j && j < k) is right.       *
 * **********************************************************************************/

/******************----------------------------while-----------------------******************/
	
	int max_number;
	printf("input a number, then I will calculate the smaller numbers' square: ");
	scanf("%d", &max_number);
	
	int count_i = 1;
	while (count_i <= max_number){
		printf("%10d%10d\n", count_i, count_i * count_i);
		count_i++;
	}

/********************---------------------do while-------------------************************/

//use "do { *** } while(**)" to replace the "while".

	count_i = 1;
	if(max_number >= 1){
		do {
			printf("%10d%10d\n", count_i, count_i * count_i);
			count_i++;
		} while (count_i <= max_number);
	} else{
		printf("Error!\n");
	}

/*************************------------for loop---------------********************************/

//use "if" to replace "while".
	
	for(count_i = 1; count_i <= max_number; count_i++){
		printf("%10d%10d\n", count_i, count_i * count_i);
		if (count_i == 4)
			break;
	}

//This program above can be replaced.

	for(count_i = 1; count_i <= max_number && count_i != 5; count_i++){
		printf("%10d%10d\n", count_i, count_i * count_i);
	}
/************************************************************************************
 * To create a unlimited loop, use "if (;;) { ******* }".                           *
 * and this expression"if (int i = 1; i < n; i++) { ******** }", the "i" can only   *
 * be used in the for loop.                                                         *
 * *********************************************************************************/ 

/***********--------------------exercise calculate e----------------**********************************/

	int e_n;
	printf("to calculate e, input a number: ");
	scanf("%d", &e_n);

	float result = 0, result_temp = 1;

	for(int i = 1; i <= e_n; i++) {
		result_temp *= i;
		result += 1.0f/result_temp;
	}
	
	printf("the estimate number to e is %.20f\n", result + 1);

/**************-------------------------the end-----------------------------***************************/


	return 0;
}	
