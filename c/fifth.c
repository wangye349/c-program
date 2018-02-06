#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME 20

struct Part{
	
	int number;
	char *name;//[MAX_NAME + 1];

};


int main(void){

/*************------------struct and enumeration-------------**********************/
	struct Part part1, part2;
	part1.number = 3;
//	strcpy(part1.name, "abc");
	part1.name = "abc";

	struct Part part3[100] ={[0].number = 1, [0].name = "abc"};

	int i;
	enum {CLUBS = 1, DIAMONDS = 2, HEARTS = 3, SPADES = 4} s;

	s = 1;		//s means CLUBS.
	s++;		//s means DIAMONDS.
	i = DIAMONDS; 	//i equals to 2.

/**********---------------malloc-calloc-realloc----------************************/

	char *p;

	if ((p = (char *)malloc(100)) != NULL){
	
		printf("allocate the number successfully!\n");

	}
	
	p = "abc";
	printf("%s\n", p);

	int *a;
	a = (int *)malloc(100 * sizeof(int));

	struct Part *str;
	str = calloc(100, sizeof(struct Part));
	printf("calloc %d\n", (int)(sizeof(str)/sizeof(*str)));

	str = realloc(str, sizeof(struct Part));
	printf("realloc %d\n", (int)(sizeof(str)/sizeof(*str)));
	
	
	return 0;
}
