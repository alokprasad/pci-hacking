/* Program for quicksort 
 * 0) low < high
 * 1) Given the values of low and high 
	a) key =a [low];
	b) i = low;
	c) j = high;
 * 2) When key is greater than a[i] and i is less than high, increment i
 * 3) When key is less than a[j], decreament j
 * 4) when low < high, swap a[i] with a[j]
 * 5) else swap a[low] with a[j]
 */



#include<stdio.h>

void quick_sort(int arr[20],int,int);


void main()
{
	int arr[20],n,i;

	printf("Enter the number of elements in the Array: ");
	scanf("%d",&n);

	printf("\nEnter %d elements:\n\n",n);
	for(i = 0 ; i < n ; i++)
		scanf("%d", &arr[i]);

	quick_sort(arr, 0, n-1);

	printf("\nThe Sorted Array is:\n\n");
	for(i = 0 ; i < n ; i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void quick_sort(int arr[20], int low, int high)
{
	int key,j,temp,i;

	if (low < high)
	{
		key = arr[low];
		i = low;
		j = high;

		while (i<j)
		{
			while ((arr[i] <= key) && (i < high))
				i++;

			while ((arr[j] > key))
				j--;

			if (i < j)
			{ 
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

		temp = arr[low];
		arr[low] = arr[j];
		arr[j] = temp;
		quick_sort(arr,low,j-1);
		quick_sort(arr,j+1,high);
	}
}
