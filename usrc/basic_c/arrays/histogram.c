/*
 * This program which prints the '*' number of times declared in the array
 * An array program, which prints the '*' wrt to the histograms
 * %5d, "four" -> prints _four,
 * %6d, "four" -> prints __four,   ( '_' means space)
 *
 */

#include <stdio.h>
#define SIZE 10

int main()
{
	int n[ SIZE ] = { 19, 3, 15, 7, 11, 9, 13, 5, 17, 1 };

	int i, j;

	int width = 10, num = 20;

	printf( "%s%13s%21s\n", "Element", "Value", "Histogram" );
//	printf( "%5s%4s%s\n", "one", "two", "three" );

//	printf("%2$*1$d \n", width, num);
	
	for(i = 0; i< SIZE; ++i)
	{
		printf( "%7d%13d ", i, n[ i ]) ;

		for ( j = 1; j <= n[ i ]; j++ ) /* print one bar */
			printf( "%c", '*' );

		printf( "\n" );

	}                

	return 0;
}

