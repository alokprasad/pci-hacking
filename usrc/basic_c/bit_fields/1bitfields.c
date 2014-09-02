/*
 * 1) Always go for unsigned <datatype> when using bit fields
 * 2) type specifiers, double, float cannot be used as bitfield 
 * 3) Always the value will be truncated to the bitfield size, so no overlapping with the next member
	example: 
		unsigned int a : 2;	
		unsigned int b : 4;	
	
		.b = 0;
		.a = 10;
		
	Here, the value of b is 0, however after assigning the value of a to 10 => 0x1010 
	while printing, the value of a is 2 and the value of b is 0. Thus truncating the values.  
 * 4) 	int *p;
	p = &sb.a;  error: cannot take address of bit-field ‘a’
 */

#include <stdio.h>

struct bitfield {
	unsigned int a : 2;
	unsigned int b : 4;
	unsigned char c : 2;
};

int main()
{
	struct bitfield sb, *sp = &sb; 	
	int i, *p;	

	printf("The sizeof the struct is:%d \n", sizeof(sb));	
	printf("The sizeof *sp is:%d \n", sizeof(*sp));	
	printf("The sizeof sp(%p) is:%d \n", sp, sizeof(sp));	
	printf("The sizeof 'struct bitfield' is:%d \n", sizeof(struct bitfield));	

//	p = &sb.a;						// This feature wont support
	sb.a = 10;
	sb.b = 0;
	sb.c = 'b';
	i = 'b';

	printf("The value of a : %d \n", sb.a);
	printf("The value of b : %d \n", sb.b);
	printf("The value of c : %d \n", sb.c);			// printing only the last two bits of data
	printf("The value of i as integer : %d \n", i);
	printf("The value of i as character : %c \n", i);
}


/**************OUTPUT***************************/
/*
The sizeof the struct is:4
The sizeof *sp is:4
The sizeof sp(0xbffe26ec) is:4
The sizeof 'struct bitfield' is:4
The value of a : 2
The value of b : 0
The value of c : 2
The value of i as integer : 98
The value of i as character : b
*/
