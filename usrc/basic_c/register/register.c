#include<stdio.h>

//register int j=20;		
/* 1) Globally the register cannot be declared, since if the memory of the registers are full, 
      the variable will be defined in the stack as a local variable. 

 * 2) The address of the registers cannot be obtained, as the registers are stored in the CPU
   	ex:-  	register int i=10;
		int *p;
		p = &i;

 * 3) The register pointer is assigned to a integer, this works 
	int	i = 10;
	register int *p = &i;
	register int a[5];
	printf("The register address a : %p \n", a);   -> prints the hex address 0x543abfe
	printf("The register address i : %p \n", i);   -> prints the hex address 0x512afed

 * 4) Cannot access the address of the register variable either through the pointers or just like an array.
	register int a[5];
	printf("The register address a : %p \n", a);

 * 5) Two storage class specifiers cannot be combined and cannot be used for a single variable
 * 	 for example static extern int a;
 */
int main()
{
	register float a;
	register char c;
	register long l;
	register long double x;
	register double y;
	
	a = 5.14;
	c = 'd';
	l = 13446466;
	x = 145674786.156745;
	y = 12365478925.2354;
	printf("The register value a : %f \n", a);
	printf("The register value c : %c \n", c);			//character
	printf("The register value l : %ld \n", l);			//%ld -> long int
	printf("The register value x : %lf \n", x);			//%lf -> long double
	printf("The register value y : %lf \n", y);			//%lf -> double
	printf("The sizeof short	: %u\n", sizeof(short));
	printf("The sizeof int		: %u\n", sizeof(int));
	printf("The sizeof float	: %u\n", sizeof(float));
	printf("The sizeof long		: %u\n", sizeof(long));
	printf("The sizeof double	: %u\n", sizeof(double));
	printf("The sizeof long long	: %u\n", sizeof(long long));
	printf("The sizeof long double  : %u\n", sizeof(long double));
	return 0;
}

