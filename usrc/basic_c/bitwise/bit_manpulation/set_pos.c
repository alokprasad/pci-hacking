/*
 * Set position bit in a number
 */

int set_pos(int num, int pos)
{
	return (num | (1 << pos));
}
