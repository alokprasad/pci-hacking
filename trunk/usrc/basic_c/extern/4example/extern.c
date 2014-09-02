/*
 * 1) Extern variables can be used only, if they are declared as global 
 * 2) Here int i; inside the main is different and the int i declared at the bottom which is global is different
 */

#include<stdio.h>

void func1();

int main()
{
	int i = 10;

	printf(" The value of i inside main is : %d \n", i);
	func1();

	return 0;
}

//int i = 10;

