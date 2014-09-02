
//static int a = 30;				//extern is not possible as the scope of static is limited to only this file

/* CASE-1
 * - In case of extern, no memory will be allocated. However the extern varibles gets the reference from the global variable. 
 * - Extern should be used for only global variables.
 * - Local variables cannot be accessed using extern as the scope of local variables limits to a module or function.
 * - However extern is declared inside local function, this works - as the definition of the variable 'i' is defined globally.
 * 
 * CASE-2
 * - The variable 'a' is defined global here, thus this can be used as extern in the extern2.c
 * - In the extern2.c the extern is declared, and used. But the memory will be allocated for this in the extern1.c
 * - The extern cannot be used in 2 files with 2 main functions  
 *
 * CASE-3
 * - Declaring a int array as extern, which works and this is used in extern4.c 
 *
 */
#include<stdio.h> 

int a = 30;
int i = 10;
int array[10];

void function()
{
	printf("Inside the extern-1 function() i:%d\n",i);
}

void main()
{
	int i = 20;

	printf("Inside the extern-1 main() i:%d\n",i);

	{
		extern int i;
		printf("%d\n", i);
	}

	printf("Inside the extern-1 main() i:%d\n",i);

	function();
	fun2();
	a++;
	fun2();
	a++;
	fun3();
	a++;
	fun3();

	fun4();
}

