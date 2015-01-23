/*
 * 1) The const is a keyword and not a data type
 * 2) const static int g; 
 * 	This can be used, however the variable 'g' cannot be changed 
 * 3) volatile register int l = 20;	// This works
 *
 * 4) Volatile means, always the data is accessed from the memory, sometimes the variable values may be accessed from the registers
 * 5) Thus when accessed, the value is obtained from the memory and after the change the value is written back to the memory
 * 6) The volatile qualifier declares a data object, so that can have its value changed in ways outside the control or detection of the compilation 
 * 7) The value of the volatile may get changed without any action being taken by the code 
 * 8) If the volatile is used for struct or union, then all the members inside this are volatile. 
 *    If needed individually, declare volatile individually for the members of the struct. 
 * 9) Real time example for volatile: Used in RTC, as the value of the time keeps changing and this is read to a memory. 
 * 10) The values stored in register gets modified any time by any other process. Thus the volatile always accesses the memory locations 
 * 11) 'const volatile' and 'volatile const' both keywords cannot be used at a time.
 */ 

#include<stdio.h>

const static int g = 100;

void fun1()
{
	printf("Inside fun1() g:%d\n", g);
}

void fun2()
{
	printf("Inside fun2() g:%d\n", g);
}

void main()
{
	volatile register int l = 20;	// This works
	
	const volatile cv = 1;
	volatile const vc = 10;
	
	//cv ++;			// error: increment of read-only variable ‘cv’
	//++ vc;			// These opearation is not permitted, 

	printf("cv : %d \n", cv);
	printf("vc : %d \n", vc);

	printf("Insine the main() l:%d\n", l);
	printf("Inside the main() l:%d\n", l++);
	printf("Inside the main() l:%d\n", ++l);

	// g=g++;			//error: increment of read-only variable ‘g’

	fun1();
	fun2();
}


/**************OUTPUT********************/
/*
cv : 1
vc : 10
Insine the main() l:20
Inside the main() l:20
Inside the main() l:22
Inside fun1() g:100
Inside fun2() g:100
*/
