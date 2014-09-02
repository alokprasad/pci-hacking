/*
 * 1) x+++++ cannot be used, or x++ + ++ also cannot be used. As this requires the lvalue and two operands
 * 2) In the declaration itself we cannot use the increment operators. Ex: int i++; and also in extern int a++ also.
 * 3) ++x++ cannot be used, says the lvaue required 
 */

#include<stdio.h>

int fun4(void)
{
	static int x = 10;
	extern int a;
	extern array[10];

	array[1] = 20;
	array[2] = 40;


	printf("Inside the extern-4 fun4() a:%d\n", a++);
	printf("Inside the extern-4 fun4() array[1]: %d, array[2]: %d\n", array[1], array[2]);

	return 0;	
}


