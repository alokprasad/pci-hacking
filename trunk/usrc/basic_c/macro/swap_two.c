#include<stdio.h>
#define swap(a, b) 	{a = a + b; b = a - b; a = a - b;}
#define swap_xor(a, b) 	{a = a ^ b; b = a ^ b; a = a ^ b;}

void main()
{
	int a, b;
	printf("Enter two numbers:\n");
	scanf("%d %d", &a, &b);

	printf("Before swapping a: %d, b: %d\n", a, b);
	swap(a, b);
	printf("After swapping a: %d, b: %d\n", a, b);
	printf("Before swapping a: %d, b: %d\n", a, b);
	swap_xor(a, b);
	printf("After swapping a: %d, b: %d\n", a, b);
}


