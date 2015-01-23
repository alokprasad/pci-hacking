#include <stdio.h>

int main(void)
{
	int sum = 0, i, res = 0;

	for (i = 0; i <= 100; i++)
		sum = sum + i;

	printf("total sum is : %d \n", sum);

	res = 100 * 101 / 2;
	printf("res is : %d \n", res);


}
