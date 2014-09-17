/*
 * 1) The scope of static is limited to a file or a program within which it is present
 * 2) The static variable value persists between the function calls
 */ 



#include<stdio.h>

static int g = 100;

void fun1()
{
	printf("Inside fun1() g:%d\n", g--);
}

void fun2()
{
	printf("Inside fun2() g:%d\n", --g);
}

void main()
{
	static int l = 20;

	printf("Inside the main() l:%d\n", l);
	printf("Inside the main() l:%d\n", l++);
	{
		static int l = 30;
		printf("Inside local block %d\n", l);
	}

	printf("Inside the main() l:%d\n", ++l);

	fun1();
	fun2();
}

/*
 Output for the above program
**********************************************************************************  

Inside the main() l:20
Inside the main() l:20
Inside local block 30
Inside the main() l:22
Inside fun1() g:100
Inside fun2() g:98
*/
