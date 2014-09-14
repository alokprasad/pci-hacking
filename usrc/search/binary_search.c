/* Binary search program - enter the elements in ascending order */

#include <stdio.h>

int array[20];

int BinarySearch(int num, int key)
{
        int low = 0, high = num-1, mid;
        while(low <= high)
        {
                mid = (low + high)/2;
                if(array[mid] < key)
                {
                        low = mid + 1; 
                }
                else if(array[mid] == key)
                {
                        return mid;
                }
                else if(array[mid] > key)
                {
                        high = mid-1;
                }

        }
        return -1;
}

int main()
{
        int num, index;
        int iter;
        int key;

	printf("\n Enter the number :");
	scanf("%d",&num);

        /*Input has to be sorted in non decreasing order */
	printf("\n Enter the numbers in sorted order :");
        for(iter = 0;iter < num;iter++)
                scanf("%d",&array[iter]);

	printf("\n Enter the key:");
        scanf("%d",&key);

        index = BinarySearch(num,key); 
        if(index==-1)
                printf("Element not found\n");
        else

                printf("Element is at index %d\n", index+1);
        return 0;
}
