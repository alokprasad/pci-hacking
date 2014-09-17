#include<stdio.h>
#define swap(a,b) {a = a+b; b = a-b; a = a-b;}

swap1(int *x,int *y,int *z)
{
	*x=*y;
	*y=*z;
	*z=*y-*x;
}
swap2(int *x,int *y,int *z)
{
	*x=*z;
	*y=*x-*y;
	*z=*x-*y;
}
void main()
{
	int a, b, c;
	printf("Enter three numbers:\n");
	scanf("%d %d %d", &a, &b, &c);

	printf("Before swapping a: %d b: %d c: %d\n", a, b, c);
	swap(a, b);
	swap(b, c);
	printf("After swapping a: %d b: %d c:%d\n", a, b, c);

	printf("Enter three numbers:\n");
	scanf("%d %d %d", &a, &b, &c);

	printf("Using the pointers\n");
	printf("Before swapping a: %d b: %d c: %d\n", a, b, c);
	swap1(&a, &b, &c);
	printf("After swapping a: %d b: %d c:%d\n", a, b, c);

	printf("Before swapping a: %d b: %d c: %d\n", a, b, c);
	swap2(&a, &b, &c);
	printf("After swapping a: %d b: %d c:%d\n", a, b, c);
}


