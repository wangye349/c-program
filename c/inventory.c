#include <stdio.h>
#include <string.h>

#define MAX_PART_NUMBLE 100
#define NAME_LEN 20
#define DEBUG 0

void
insert(void);				//insert part number / part name /part quantities.

void
search(void);				//search part number, find if it exists, and list its name and quantities.

void
update(void);				//update one part's quantities.

void
print(void);				//print out all the part's number / name /quantities.

int 
find_number(int number_in);		//find whether the number exists, and return its location in the "inventory" array. 

void
read_line(char *line);			//in the insert mode, read the part name, and store it into the "inventory" array.

struct {
	int number;
	char name[NAME_LEN];
	int quantities;
} inventory[MAX_PART_NUMBLE];		//initialize an structure array to store the part number / part name / part quantities.

int storage = 0;			//the part's location in the "inventory" array.

int main(void){

	char op;			//read operation code.
	
	for (;;){

		printf("Enter operation code: ");
		scanf(" %c", &op);	

		while (getchar() != '\n')//ignore '\n'.
			;

		switch (op){
			case 'i': insert();
				break;
			case 's': search();
				break;
			case 'u': update();
				break;
			case 'p': print();
				break;
			case 'q': return 0;
			default: printf("Invalid operation code!\n");
		}

	}

}

void read_line(char line[]){
	
	char ch;							
	int i = 0;

	while ((ch = getchar()) == ' ')					//ignore the space.
		;

	for (i = 0; (ch = getchar()) != '\n' && ch != EOF; i++){

		line[i] = ch;						//read the name.

	}
	line[i] = '\0';

	return;
}

int find_number(int number_in){

#if DEBUG
		printf("%d        %s         %d\n", inventory[0].number, inventory[0].name, inventory[0].quantities);
#endif

	for (int i = 0; i < storage; i++){

		if (inventory[i].number == number_in)
			return i;					//search all the "inventory" array, if it's matched, return its location in the array.
	
	}

	return -1;							//"-1" is not in the array location.

}

void insert(void){
	
	char ch, name_length = 0;					

	if (storage == MAX_PART_NUMBLE){				//check if the array is full.
		printf("The datebase is full, can't insert any parts!\n");
		return;
	}
	else {

		printf("Enter part number: ");				//read the part number.
		scanf("%d", &inventory[storage].number);
		
#if DEBUG
		printf("this work\n");
#endif

		if(find_number(inventory[storage].number) >= 0){
		
			printf("It's already existed!");
			return;

		}

		printf("Enter part name: ");
		
/*************************************************************************
 *1 while ((ch = getchar()) != '\n' && ch != EOF){			 *
 * 									 *
 *	strcat(inventory[storage].name, ch);                             *
 *	name_length++;                                                   *
 *									 *
 * }                                                                     *
 * inventory[storage].name[name_length] = '\0';                          *
 *                                                                       *
 *                                                                       *
 *2 scanf(" %c\n",  inventory[storage].name);                            *
 *                                                                       *
 * these two methods are not gonna work.                                 *
 ************************************************************************/
		
		read_line(inventory[storage].name);

		printf("Enter part quantities: ");
		scanf("%d", &inventory[storage].quantities);

		storage++;

#if DEBUG	
		printf("%d        %s         %d\n", inventory[0].number, inventory[0].name, inventory[0].quantities);
#endif

	}
}

void search(void){

	int search_number;

	printf("Enter part number: ");
	scanf("%d", &search_number);
	
#if DEBUG
	printf("%d\n",find_number(search_number));
#endif

	if(find_number(search_number) >= 0) {
		
		printf("Part name: %s\n", inventory[find_number(search_number)].name);

		printf("Part quantities: %d\n", inventory[find_number(search_number)].quantities);
	
	}
	else {
		
		printf("Part is not found!\n");
	
	}

	return;
}

void update(void){

	int search_number, update_number;

	printf("Enter part number: ");
	scanf("%d", &search_number);

	if (find_number(search_number) < 0)
	
		printf("Part is not found!\n");
	
	else {
	
		printf("Enter part number: ");
		scanf("%d", &update_number);
		
		inventory[find_number(search_number)].quantities += update_number;

	}

	return;

}

void print(void){
	
	printf("Part Number        Part Name          Quantities\n");

	for (int i = 0; i < storage; i++){

		printf("%d        %s         %d\n", inventory[i].number, inventory[i].name, inventory[i].quantities);

	}
	
	return;

}
		
