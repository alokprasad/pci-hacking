/*
 * Implementation of singular linked list 
 * This performs the following operations
 * 1) insert a number in front/rear
 * 2) remove a number in front/rear
 * 3) delete a number from a given position
 * 4) display the list
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
NODE insert_rear(NODE first)
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
	return(first);
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

/* Insert a element at a given position */
NODE insert_pos(NODE first)
{
	int num, pos;
	NODE temp, cur, prev;

	printf("\n Enter a number to insert: ");
	scanf("%d", &num);
	printf("\n Enter the position: ");
	scanf("%d", &pos);
	
	temp = getnode();
	temp->link = NULL;
	temp->data = num;

	if (pos == 1) {
		temp->link = first;
		return (temp);
	}
	
	cur = first;
	prev = NULL;
	while ((cur->link != NULL) && (pos > 1)){
		prev = cur;
		cur = cur->link;
		pos--; 
	}
	if (cur == NULL) {
		printf("Invalid position for insertion");
		return(first);
	}
	prev->link = temp;
	temp->link = cur;
	return(first);
}

/* Deletes an element at the end of the list */
NODE delete_rear(NODE first)
{
	NODE temp, cur;
	
	if(first == NULL) {
		printf("List is empty \n");
		return (first);
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

/* Deletes an element from the given position */
NODE delete_pos(NODE first)
{
	NODE temp, prev, cur;
	int pos;
	
	printf("\n Enter the position: ");
	scanf("%d", &pos);

	if(first == NULL) {
		printf("List is empty \n");
		return (first);
	}
	
	if (pos ==1) {
		first->link = temp;
		printf("Deleted element is : %d", first->data);
		return (temp);
	}
	
	cur = first;
	prev = NULL;
	while((cur->link != NULL) && (pos > 1)) {
		prev = cur;
		cur = cur->link;
		pos--;
	}
	printf("Deleted element is : %d", cur->data);
	prev->link = cur->link;
	
	return (first);
}

/* Displays the elements in the list */
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

/* Reverse a linked list */
NODE reverse(NODE first)
{
	NODE prev = NULL;
	NODE cur = first;
	NODE next;

	while (cur != NULL) {
		next = cur->link;
		cur->link = prev;
		prev = cur;
		cur = next;
	}
	first = prev;
	return (first);
}

int main(void)
{
	NODE first = NULL;
	int choice;
	
	printf("\t\t*** SINGULAR LIST *** \n");
	while(1) {
		printf("\n 1.INSERT FRONT \n 2.INSERT REAR \n 3.DELETE FRONT \n 4.DELETE REAR \n"
			" 5.INSERT POS \n 6.DELETE POS \n 7.DISPLAY LIST \n 8.REVERSE \n 9.EXIT \n");
		scanf("%d", &choice);
		switch(choice) {
			case 1: first = insert_front(first);
				printf("\n After Insertion, list elements are: ");
				display(first);
				break;
		
			case 2:	first = insert_rear(first);
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
		
			case 5:	first = insert_pos(first);
				printf("\n After insertion, list elements are: ");
				display(first);
				break;
	
			case 6: delete_pos(first);
				printf("\n After deletion, list elements are: ");
				display(first);
				break;	

			case 7: printf("\n List elements are: ");
				display(first);
				break;

			case 8: first = reverse(first);
				printf("\n The reversed list is: ");
				display(first);
				break;			

			default:exit(0);
		}
	}
}
