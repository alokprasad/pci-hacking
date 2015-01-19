/* Check whether nth bit is set or not */

#include <stdio.h>

int main()
{
	int num, pos;

	printf("Enter the number for : \n");
	scanf("%d", &num);

	printf("Enter the pos, check pos is set or not:");
	scanf("%d", &pos);

	printf("Number %d, New position, %d \n", num, (1 << pos));

	if (num & (1 << pos))
		printf("Bit set \n");
	else
		printf("Bit not set \n");

}
