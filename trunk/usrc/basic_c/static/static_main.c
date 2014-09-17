/*
1) The program below doesn't execute
2) Error generated is as below
      
  /usr/lib/i386-linux-gnu/gcc/i686-linux-gnu/4.5.2/../../../crt1.o: In function `_start':
  (.text+0x18): undefined reference to `main'
  collect2: ld returned 1 exit status

3) When a executable execute, _start is the starting point of execution. 
4) Inside the _start, main will be called 
5) As the main is declared as static int main, and the scope of static is within the file
6) So the main is undefined for _start

Important note:
7) If the main is declared as static, the scope of the main remains visible to that file,
   and the other files may not be able to access the main.

*/

#include<stdio.h>

static void main(void)
{
	printf("Hello\n");
}

