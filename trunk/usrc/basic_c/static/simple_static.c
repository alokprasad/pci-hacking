#include<stdio.h>

void fun(void);

int main(void)
{
	int i;

	for(i = 0; i < 5; i++) {
		fun();
	}

	return 0;
}

void fun()
{
	static int sum;
	int num;

	printf("Enter a number: \n");
	scanf("%d", &num);

	sum = sum + num;

	printf("The sum is : %d \n", sum);
}

