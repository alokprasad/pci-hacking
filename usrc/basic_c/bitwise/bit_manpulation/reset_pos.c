/*
 * Reset position bit in a number 
 */

int reset_pos(int num, int pos)
{
	return (num & (~(1 << pos)));
}
