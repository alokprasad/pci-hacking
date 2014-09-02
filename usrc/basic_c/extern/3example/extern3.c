/*
 * 1) x+++++ cannot be used, or x++ + ++ also cannot be used. As this requires the lvalue and two operands
 * 2) In the declaration itself we cannot use the increment operators. Ex: int i++; and also in extern int a++ also.
 * 3) ++x++ cannot be used, says the lvaue required 
 */

#include<stdio.h>

int fun3(void)
{
	static int x = 10;
	extern int a;
	printf("Inside the extern-2 fun3() a:%d\n", a++);
	return 0;	
}


