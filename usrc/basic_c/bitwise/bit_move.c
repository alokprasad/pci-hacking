/*  pos ->   3210 	
 * 1) num1 = 1011   - move the bit '1' of num1 to bit '2' of num2
 * 2) num2 = 1000
 * 3) so answer should be 1100
 *
 */

#include<stdio.h>

int main()
{
	int one, two, src_pos, dest_pos;
	int temp = 0, res; 
	int gar, shift = 1;

	printf("Enter first number: ");
	scanf("%d", &one);

	printf("Enter second number: ");
	scanf("%d",&two);

	printf("Initial value, one : %d, two : %d \n", one, two);
	
	printf("Enter source position for first number: ");
	scanf("%d", &src_pos);
	
	printf("Enter destination position for second number: ");
	scanf("%d", &dest_pos);
#if 0
/*
	temp = one >> src_pos;	
	res = temp << dest_pos;
*/
	shift = shift << src_pos;
	gar = one & shift;
	
	printf("temp: %d, res: %d, shift: %d \n", temp, res, shift);

	if(gar) {
		two = two | (1 << dest_pos);
	}
	else {
		res = 1 << dest_pos;		
		two = two & (~(res));	
	}
#else	
	if(one & (1 << src_pos)) {
		two |= (1 << dest_pos);
	} else {
		two &= (~(1 << dest_pos));
	}
#endif
	printf("Modified value, one : %d, two : %d \n", one, two);
	return 0;
}

