/* Bubble sort to sort the elements in ascending order */
/* If there are 'n' elements, the looping is done for n-1 times */
/* Outer loop is to repeat the comparisions and the inner loop is for compare each element */

#include <stdio.h>

int n;
int a[20];

void bubble_sort()
{
	int i, j, temp;

	for (i = 0; i < n-1; i++) {
		for (j = 0; j < n-1-i; j++) {
			if (a[j] > a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

int main(void)
{
	int i;
	
	printf("Enter the number of elements: \n");
	scanf("%d",&n);
	
	printf("Enter the elements: \n");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	bubble_sort();
	
	printf("The sorted array is: \n");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);

	printf("\n");
}
