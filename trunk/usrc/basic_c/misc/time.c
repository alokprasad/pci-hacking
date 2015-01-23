#include <stdio.h>
//#include <conio.h>
#include <time.h>

void main()
{
	time_t t;
	time(&t);

	for (;;) {
//		clrscr();
		printf("Time is : %s", ctime(&t));
	}

}

