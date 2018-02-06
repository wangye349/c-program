#include <stdio.h>
#include <string.h>

int
read_lines(char *str, int n);

int
strlen_re(char *s);

char
*strcat_re(char *str1, const char *str2);

char
*strcat_re_simplify(char *str1, const char *str2);


int main(void){

/***********--------------------pointer---------------------*****************/
	/*int *p, i;

	p = &i;*/
	
//	int i = 1, *p = &i;//"*p = 2" is wrong, "*p = &i" is necessary.
	
//	printf("%d\n",*p);
	
//	*p = 2;

//	printf("%d\n",i);

//	int *p = (int[]){2,3,4,5};
/* **************************************
 * equals "int a[] = {2,3,4,5};         *
 * 	   int *p = a[0];"              *
 * equals "int a[] = {2,3,4,5);         *
 * 	   int *p;                      *
 * 	   p = a;"                      *
 * equals "int a[4];                    *
 * 	   int *p = a;                  *
 * 	   for (int i=0;i<4;i++)        *
 *		p[i] = i+2;"            *
 * 	   p[i] designates *(p + i)     *
 ***************************************/

/************------------pointer and array-------------------**************

	int a[3][4], (*p)[4], i = 2, *p_1;


	for (p_1 = &a[0][0]; p_1 <= &a[2][3]; p_1++){
		*p_1 = 0;
	}


	for (p = &a[0]; p < &a[3]; p++){
		(*p)[i] = 2;
	}

	printf ("%d\n", a[2][2]);
		
*******---------------string------------------------------***************/

	printf ("When you come to a fork in the road, take it."
		"--Yogi Berra\n");
	
	char date[100] = "Jan 6";
	
	char *p = date;

	puts(p);
	
	puts(date);

	printf("Enter a sentense: \n");

/*	char other_date[100];
	gets(other_date);*/
//this should never be used, cause the "gets" function is too dangerous!!!!!!!!!

		
	
	char other_date[100];

	read_lines(other_date,6);

	printf("other date is %s\n",other_date);

//	strcpy(date, other_date);//not safe;
	
	strncpy(date, other_date, sizeof(date) - 1);
	date[sizeof(date) - 1] = '\0';
	
	char *date_temp = date;

//	strcat(date, other_date); //still not safe
	strncat(date, other_date, sizeof(date) - strlen(date) - 1);
	date[sizeof(date) - 1] = '\0';
	
	printf("date change is: ");
	puts(date);
	
	strcat_re(date_temp, other_date);

	printf("date my change is: ");
	puts(date_temp);

	printf("the length of date is %d or %d\n", (int) strlen(date), strlen_re(date));
	
	printf("date is larger than other_date, %d\n",(_Bool) strcmp(date,other_date));

	

	return 0;
}

int read_lines(char *str, int n){

	int i = 0, ch;

	while ((ch = getchar()) != '\n'){
	
		if (i < n)
			str[i++] = ch;

	}

	str[i] = '\0';

	return i;
}


int strlen_re(char *s){
	
	const char *p = s;
	
	while (*s++);

	return (int) (s - p - 1);
}

char *strcat_re(char *str1, const char *str2){
	char *combine_two_string = str1;

	for (int i = 0; i < sizeof(str1) - 2; i++){

		*(combine_two_string + i) = *(str1 + i);

	}
	
	for (int j = 0; j < sizeof(str2) - 2; j++){

		*(combine_two_string + sizeof(str1) + j - 2) = *(str2 + j);

	}

	*(combine_two_string + sizeof(str1) + sizeof(str2) - 2) = '\0';

	return combine_two_string;

}

char *strcat_re_simplify(char *str1, const char *str2){
	char *p = str1;

	while(*p)
		p++;

	while(*p++ = *str2++);

	return str1;
}
