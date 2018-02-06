#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

double 
average(double a, double b);

int
sum_two_dimensional_array(int n, int m, int a[n][m]);

int main(void){
	
/**************------------------char--------------------------**************************/

	char ch;


//	scanf("%c", &ch);
//	printf("%c\n", toupper(ch));//toupper(ch) tries to turn the ch into upper case.

/************------------------getchar---puchar---------------**************************/

//	ch = getchar();
//	putchar(ch);
	/*
	printf("next part:");

	int len = 0;
	while((ch = getchar()) != '\n' && ch != ' ')
		len ++;

	printf("the length of the string is %d\n", len);*/

/******************************************************************************************
 * "define Bool int" is equal to "typedef int Bool".                  sizeof(a)           *
 * ***************************************************************************************/

/*******--------------------------array------------------------------------***************/

	int a[10] = {1,3,4};
	int i;
	
	for (i = 0; i < 10; i++)
		a[i] = i;
	
	int length_of_array;
	length_of_array = (int)(sizeof(a)/sizeof(a[0]));

/*const*/int array_two_dimen[3][3] = {false};	

	char c = '3';
	i = c - 48;
	
	printf("%d\n",i);

/*	int b[];
	
	for (i = 0; i < 989; i++)
		b[i] = i;

	printf("%d",(int)(sizeof(b)/sizeof(b[0])));*****-----not allowed for the b[]------******/

/************-----------------function----------------------******************************/

	double x = 1, y = 2;
	printf("average of x and y is %f\n",average(x,y));	

	printf("sum of the two dimentional array is %d\n", sum_two_dimensional_array(3, 3, array_two_dimen));	
	
//	printf("sum of a two dimentional array is %d\n", sum_two_dimensional_array(2, 2, (int d[][]){2,3,4,5}));

		

	return 0;
}

double average(double a, double b){
	
	static double divi = 2.0;
	double ave = (a + b) / divi;
	return ave;

}

int sum_two_dimensional_array(int n, int m, int a[n][m]){

	int sum = 0;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
	
	 		sum += a[i][j];
	
		}
	}

	return sum;
}		
