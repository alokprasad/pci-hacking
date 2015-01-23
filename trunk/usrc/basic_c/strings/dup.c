/* Remove duplicate characters in the string */

#include<stdio.h>

int main(void)
{
	char s[50];
	int i = 0, j;
	printf("enter character string:");
	while((s[i] = getchar()) != '\n')
	{
		for(j = 0; j < i; j++)
			if(s[j] == s[i])
				i--;
		i++;
	}
	printf("after removing the duplicates the string is:");
	for(j = 0; j < i; j++)
		printf("%c",s[j]);
} 


