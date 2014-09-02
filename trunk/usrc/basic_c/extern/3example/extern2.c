#include<stdio.h>

int fun2(void)
{
	extern int a;
	printf("Inside the extern-2 fun2() a:%d\n",a);
	return 0;	
}

