/*
 * 1) Taking a number as input and print the binary equivallent of that number
 *
 */

#include<stdio.h>
#include<string.h>

void store_in_array(int);

int main(void)
{
	int num, i;

	printf("Enter the number: \n");
	scanf("%d", &num);

	printf("The number in binary is: \n");
	for(i = sizeof(int); i >= 0; i--) {
		if(num & (1<<i)) {
			printf("1");
		}
		else {
			printf("0");
		}
	}
	printf("\n\n");

	store_in_array(num);

	return 0;
}

void store_in_array(int num)
{
	int i;
	char str[sizeof(int)];
	int j = strlen(str);

/* Here some circus is done, taking strlen(str) as the system is little endian format */

	for(i = 0; i < sizeof(int); i++) {
		if(num & (1<<i)) {
			str[j--] = '1';
		}
		else {
			str[j--] = '0';
		}
	}
	str[j--] = '\0';
	printf("The string is : \n %s \n", str);
}

