/*
 * A program to concatinate two strings
 */

#include <stdio.h>
#include <string.h>

void concat (char *, char *);

int main(void)
{
	char str1[10], str2[5];

	printf("Enter string one:");
//	scanf("%s", str1);
	gets(str1);

	printf("Enter string two:");
//	scanf("%s", str2);
	gets(str2);

	concat(str1, str2);

	printf("The concatinated string is: %s \n", str1);

	return 0;
}

void concat (char *s1, char *s2)
{
	while(*s1 != '\0') {
		s1++;
	}

	while (*s2 != '\0') {
		*s1++ = *s2++;
	}
	*s1 = '\0';
}


