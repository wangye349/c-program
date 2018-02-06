#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25
#define MAX_PARTS 100

#define DEBUG 0 
#define DEBUG2 0 

int 
read_line(char str[], int n);

struct node {
	
	int number;
	char name[NAME_LEN];
	int on_hand;

	struct node *next;

};

struct node *inventory = NULL;

int num_parts = 0;

struct node *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

int main(void){

	char code;
	
	for(;;) {
		printf("Enter operation code: ");
		scanf(" %c", &code);
	
		while (getchar() != '\n')
			;
	
		switch (code) {
			case 'i': insert();
				  break;
			case 's': search();
				  break;
			case 'u': update();
				  break;
			case 'p': print();
				  break;
			case 'q': return 0;
			default: printf("Illegal code!\n");
		}
	}
}

int read_line(char *str, int n){

	char ch;
	int i;
	
	ch = getchar();	
//	str = malloc(sizeof(char) * NAME_LEN);
	while ((ch = getchar()) == 32)
		printf("12\n");

#if DEBUG2
	printf("%c\n", ch = getchar());

	printf("%c\n", ch = getchar());
#endif
	for (i = 0; ch != '\n' && ch != EOF; i++) {	//in case of the '\n' of the last line, ther need a ch = getchar()
		str[i] = ch;
		ch = getchar();

	}
	str[i] = '\0';

#if DEBUG 
	printf("123456789%s\n", str);
#endif
	return i;
}

void insert(void){
	
	struct node *new_node;
	new_node = malloc(sizeof(struct node));
	
	if(new_node == NULL){
	
		printf("the datebase is full\n");
		return;
	}

/*	if (num_parts == MAX_PARTS) {
		printf("Datebase is full; can't add more parts.\n");
		return;
	}
	num_parts++;*/

	printf("Enter part number: ");
	scanf("%d", &new_node -> number);
	
	struct node *pre, *cur;

#if DEBUG 
	printf("1234567890\n");
#endif
	for (pre = NULL, cur = inventory; cur != NULL && cur -> number < new_node -> number; pre = cur, cur = cur -> next)
		;
	
#if DEBUG 
	printf("1234567890\n");
#endif
	if (cur != NULL && cur -> number == new_node -> number){
		printf("Part already exists\n");
		free(new_node);
		return;
	}
	
	printf("Enter part name: ");
	int i = read_line(new_node -> name, NAME_LEN);

#if DEBUG 
	printf("1234567890%d\n", i);
#endif

	printf("Enter quantity on hand: ");
	scanf("%d", &new_node -> on_hand);

	new_node -> next = cur;
	if (pre == NULL) 
		inventory = new_node;
	else
		pre -> next = new_node;

	for (cur = inventory; cur != NULL; cur = cur -> next){

		printf("%d           %s               %d\n", cur -> number, cur -> name, cur -> on_hand);
	}
}

struct node *find_part (int number){
	
	struct node *cur;

	for (cur = inventory; cur != NULL && cur -> number != number; cur = cur -> next)
		;

	return cur;

}
	

void search(void){

	int number;
	struct node *find_number;

	find_number = malloc(sizeof(int) * 2 + sizeof(char) * NAME_LEN + sizeof(struct node));

	printf("Enter part number: ");
	scanf("%d", &number);
	
	find_number = find_part(number);

	if (find_number != NULL){
		
		printf("Part name: %s\n", find_number -> name);
		printf("Quantity on hand: %d\n", find_number -> on_hand);

	}
	else
		printf("Parts not found\n");

}

void update(void){
	
	int number, change;

	printf("Enter part number: ");
	scanf("%d", &number);

	if (find_part(number) != NULL){

		printf("Enter changer in quantity on hand: ");
		scanf("%d", &change);

		find_part(number) -> on_hand += change;
	}
	else
		printf("Part not found\n");

}

void print(void){

	struct node *cur;
	
	printf("Part Number Part Name    quantity on Hand\n");

	for (cur = inventory; cur != NULL; cur = cur -> next){
		
		printf("%d           %s               %d\n", cur -> number, cur -> name, cur -> on_hand);
	}
}
