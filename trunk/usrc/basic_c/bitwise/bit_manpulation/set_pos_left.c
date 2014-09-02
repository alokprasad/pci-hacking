/*
 * set all bits to 1 from a given position towards its left
 */

int set_pos_left(int num, int pos)
{
	while(pos != 32){		
		num = (num | (1 << pos++));
	}
	return num;
}
