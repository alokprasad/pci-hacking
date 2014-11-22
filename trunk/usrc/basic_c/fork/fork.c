/* 1. When fork called,
   2. 0 is returned to child process
   3. PID of child is returned to parent process
   4. In below program, both if and else will be executed.
*/

/* version 78 */

#include <stdio.h>
#include <sys/types.h>
void childprocess(void);
void parentprocess(void);
void main()
{
	pid_t pid = fork();

	if(pid == 0 )
	{
		childprocess();
	}
	else
	{
		parentprocess();
	}
}

void childprocess()
{

	printf("child");

}


void parentprocess()
{

	printf("parent");

}


