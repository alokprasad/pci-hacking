/*
 * Implementation of singular linked list 
 * This performs the following operations
 * 1) insert a number in front/rear
 * 2) remove a number in front/rear
 * 3) display the list
 */

#include <stdio.h>
#include <stdlib.h>

/* Declare the structure with a data variable and a next link */
struct node 
{
	int data;
	struct node *link;
};

/* Alias to the struct Node - node */
typedef struct node* NODE;

/* Allocates a node member */
NODE getnode()
{
	NODE temp;
	temp = (NODE) malloc(sizeof(struct node));
	if(temp == NULL) {
		printf("Out of memory \n");
		return;
	}
	return (temp);
}

/* Inserts an element at the end of the list */
void insert_rear(NODE first)
{
	int num;
	NODE temp, cur;
	temp = getnode();
	
	printf("\n Enter a number to insert: ");
	scanf("%d", &num);
	
	cur = first;
	while (cur->link != NULL) {
		cur = cur->link;
	}
	temp->data = num;
	temp->link = NULL;	
	cur -> link = temp;
}

/* Inserts an element at the front of the list */
NODE insert_front(NODE first)
{
	int num;
	NODE temp;
	temp = getnode();
	
	printf("\n Enter a number to insert: ");
	scanf("%d", &num);
	temp->data = num;
	temp->link = first;
	return (temp);
}

/* Deletes an element at the end of the list */
void delete_rear(NODE first)
{
	NODE temp, cur;
	
	if(first == NULL) {
		printf("List is empty \n");
	}

	temp = first;
	cur = temp->link;
	while (cur->link != NULL) {
		cur = cur->link;
		temp = temp->link;
	}
	printf("%d is deleted \n", cur->data);
	temp -> link = NULL;
}

/* Deletes an element at the front of the list */
NODE delete_front(NODE first)
{
	if(first == NULL) {
		printf("List is empty \n");
		return (first);
	}
	printf("%d is deleted \n", first->data);
	first = first->link;
	return (first);
}

void display(NODE first)
{
	if (first == NULL) {
		printf("List is empty \n");
		return;
	}
	
	while (first != NULL) {
		printf("%d->", first->data);
		first = first->link;
	}
}

int main(void)
{
	NODE first = NULL;
	int choice;
	
	printf("\t\t*** SINGULAR LIST *** \n");
	while(1) {
		printf("\n 1.INSERT FRONT \n 2.INSERT REAR \n 3.DELETE FRONT \n 4.DELETE REAR \n 5.DISPLAY LIST \n 6.EXIT \n");
		scanf("%d", &choice);
		switch(choice) {
			case 1: first = insert_front(first);
				printf("\n After Insertion, list elements are: ");
				display(first);
				break;
		
			case 2:	insert_rear(first);
				printf("\n After Insertion, list elements are: ");
				display(first);
				break;
				
			case 3:	first = delete_front(first);
				printf("\n After deletion, list elements are: ");
				display(first);
				break;

			case 4:	delete_rear(first);
				printf("\n After deletion, list elements are: ");
				display(first);
				break;

			case 5: printf("\n List elements are: ");
				display(first);
				break;

			default:exit(0);
		}
	}
}
