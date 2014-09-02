#include <stdio.h>

int main()
{
	const int a = 10;
	int *p;
	p = &a;
	printf("before - %d\n", *p);
	*p = 20; // a = 20 is not possible, but *p = 20 is possible. Thus still modifying the value of 'a'
	printf("after - %d\n", *p);
	return 0;
}


/***************OUTPUT******************/
/*
before - 10
after - 20
*/

