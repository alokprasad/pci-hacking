#include <stdio.h>

int main()
{
#if 0
	//CASE 1
	int a = 10, b = 12;
	const int *p = &a;	// *p, value is constant
	a = 15 ; // is possible,
//	*p = 20; // is not possible 
	printf("*p => a: %d\n", *p);
	printf("a: %d\n", a);
#endif
	//int *const r;
	//const int const *s;
#if 1
	//CASE 2
	int a = 10, b = 12;
	int const *p = &a;

	//*p = 20;		// This cannot be done
	printf("*p => a: %d\n", *p);
	printf("Before a: %d\n", a);
	a = 15;
	printf("After a: %d\n", a);

	p = &b;
	printf("*p => b: %d\n", *p);
	printf("b: %d\n", b);
#endif

	return 0;
}
/**************OUTPUT*********/
/*
*p => a: 10
Before a: 10
After a: 15
*p => b: 12
b: 12
*/
