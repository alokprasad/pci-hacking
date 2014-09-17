/*
 * 1) Both *&a and &*a gives the address of a 
 * 2) %p - always gives the address in hex format
 */

#include<stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int a; /* a is an integer */
	int *aPtr; /* aPtr is a pointer to an integer */

	a = 7;
	aPtr = &a; /* aPtr set to address of a */

	printf("\n\n");

	printf("The value of &a is %p \n", &a); 
	printf("The value of aPtr is %p \n", aPtr );

	printf("\n\n");

	printf("The value of a is %d \n", a);
	printf("The value of *aPtr is %d \n", *aPtr );

	printf( "\n\nShowing that * and & are inverses of "
			"each other.\n&*aPtr = %p"
			"\n*&aPtr = %p\n", &*aPtr, *&aPtr );
	return 0;
}

