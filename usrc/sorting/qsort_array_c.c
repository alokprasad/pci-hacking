  #include <stdio.h>
       #include <stdlib.h>
       #include <string.h>

       static int
       cmpint(const void *a, const void *b)
       {
    		return (*(int*)a - *(int*)b);
		
       }

       int
       main(int argc, char *argv[])
       {
           int arr[4]={4,3,1,2};


           qsort(&arr[0],4, sizeof(int), cmpint);

           for (int j = 0; j < 4; j++)
               printf("%d ",arr[j]);
           exit(EXIT_SUCCESS);
       }

