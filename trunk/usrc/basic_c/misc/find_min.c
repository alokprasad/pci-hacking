/* Find the smallest number in the integer array */

#include<stdio.h>

int main()
{
	int array[5],  min, i;

	printf("Elements");

	for(i = 0; i < 5; i++)
		scanf("%d", &array[i]);
	
	min = array[0];

	for(i = 1; i < 5; i++)
	{
		if(array[i] < min)
		{
			min = array[i];
		}
	}
	printf("min: %d", min);
}

