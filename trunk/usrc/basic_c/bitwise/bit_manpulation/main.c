#include<stdio.h>

int toggle_pos(int, int);
int set_pos(int, int);
int set_pos_left(int, int);
int set_pos_left_till(int, int);
int reset_pos(int, int);

int main()
{
	int num, pos;

	printf("Enter the number: \n");
	scanf("%d",&num);

	printf("Enter the position: \n");
	scanf("%d",&pos);

	printf("The result of toggle_pos: %d\n\n", toggle_pos(num, pos));
	printf("The result of set_pos: %d\n\n", set_pos(num, pos));
	printf("The result of reset_pos: %d\n\n", reset_pos(num, pos));
	printf("The result of set_pos_left: %x\n\n", set_pos_left(num, pos));
	printf("The result of set_pos_left_till: %x\n\n", set_pos_left_till(num, pos));
	return 0;
}
