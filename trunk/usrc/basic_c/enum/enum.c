/*
 * 1) No floating point supported
 * 2) enum is const 
 * 3) Once enum variable value defined, cannot be changed
 */

#include<stdio.h>
#define X 10

void main()
{
//	const int  one = 0, two = X, three = X+1, four = 20, five=four+1;
//	/* This line same as the below line to some extent, however this can be modified using pointers */

	enum data {one, two = X, three, four = 20, five}; 			/* integer constants, value given should be a constant */
//	enum temp { a = 1.2 };							/* This won't works, as the enum takes the value of integer constants */

//	int one;								/* One is already declared in enum, so cant be used */
//	one = 30;								/* this one is not possible as it is a constant */
//	X = X + 1;

	enum player_status {PLAYING, PAUSE, STOPPED};
	enum player_status pstatus = STOPPED;
	printf("The value of num: %d\n", pstatus);
	printf("The value of one: %d\n", one);
	printf("The value of two: %d\n", two);
	printf("The value of three: %d\n", three);
	printf("The value of four: %d\n", four);
	printf("The value of five: %d\n", five);

}


/*********OUTPUT*************/
/*
The value of num: 2
The value of one: 0
The value of two: 10
The value of three: 11
The value of four: 20
The value of five: 21
*/
