/*
 * Toggling a bit at a given position
 */

int toggle_pos(int num, int pos)
{
	num = num ^ (1 << pos);
	return num;
}
