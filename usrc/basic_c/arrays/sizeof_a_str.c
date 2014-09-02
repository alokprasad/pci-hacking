/*
 * strings are collections of characters sitting next to each other in memory. 
 * The only difference between an array of characters and string, 
 *	is that you cannot modify string literals, whereas you can modify an array.
 * strlen omit the \0, NULL at the end of string
 * sizeof() calculate the \0 at the end of string
 * len1 = 5, len2 = 6
 * sizeof(one) = 6, sizeof(two) = 7
 */

#include<stdio.h>
#include<string.h>

int main(void)
{
	char one[] = {'f','i','r','s','t','\0'};
	char two[] = "second";
	int len1, len2;

	len1 = strlen(one);
	len2 = strlen(two);

	printf(" The string length of one is %d \n", len1);
	printf(" The string length of two is %d \n", len2);
	printf(" The string size one is %d \n", sizeof(one));
	printf(" The string size two is %d \n", sizeof(two));

	return 0;
}

