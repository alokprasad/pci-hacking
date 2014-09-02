/*
 * set all bits to 1 from a given position towards its left
 */

extern int printf(char *, ...);
extern int scanf(const char *, ...);

int set_pos_left_till(int num, int pos)
{
	int dest;

	printf("Enter the destination pos:");
	scanf("%d", &dest);

	while((pos < 32) && (dest > 0)){		
		num = (num | (1 << pos++));
		dest--;
	}

	return num;
}
