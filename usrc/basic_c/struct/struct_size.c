/*
 * 1) The structure padding happens, 
 * 2) In the first structure, size will be 16
 * 3) In the second structure, size will be 12
 */

#include <stdio.h>

struct st1
{
	int a;
	char b;
	int c;
	char d;
};

struct st2
{
	int a;
	int b;
	char c;
	char d;
	char e;
};

struct st3
{
	int a;
	char b;
	int c;
	char d;
	float f;
};

int main()
{
	struct st1 s;
	struct st2 t;
	struct st3 u;

	printf("The sizeof struct 's' is :%ld \n", sizeof(s));
	printf("The sizeof struct 't' is :%ld \n", sizeof(t));
	printf("The sizeof struct 'u' is :%ld \n", sizeof(u));

	return 0;
}

