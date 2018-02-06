#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	int value;
	struct node *next;
};

struct vstring{
	int len;
	char chars[];
};//flexible array.

struct node *add_to_list(struct node *list, int n);

struct node *search_list(struct node *list, int n);

struct node *delete_from_list(struct node *list, int n);

int main(void){

	struct node *first = NULL;
	struct node *new_node;

	new_node = malloc(sizeof(struct node));
	new_node -> value = 10; //equals (*new_node).value = 10;

//flexible array. be sure that the last part of vstring is an array, and the parts in the vstring cannot only be the array, need other parts.
	int n = 100;
	struct vstring *str = malloc (sizeof(struct vstring) + n);
	str->len = n;

	return 0;
}

struct node *add_to_list(struct node *list, int n){

	struct node *new_node;
	
	new_node = malloc(sizeof(struct node));
	
	if(new_node == NULL){
		printf("Eroor: malloc failed in add_to list\n");
		exit(EXIT_FAILURE);
	}

	new_node -> value = n;
	new_node -> next = list;

	return new_node;

}

struct node *search_list(struct node *list, int n){

	for (; (list != NULL) && (list ->value != n); list = list -> next)
		;

	return list;

}

struct node *delete_from_list(struct node *list, int n){

	struct node *pre, *cur;

	for (cur -> next = list, pre = NULL; cur != NULL && cur -> value != n; pre = cur, cur = cur -> next)
		;

	if (cur == NULL)					//n is not found.
		return list;

	if (pre == NULL)					//n is in the first node.
		list = list -> next;
	else
		pre -> next = cur -> next;

	free (cur);
	return list;

}
