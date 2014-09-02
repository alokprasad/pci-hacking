/*
 * 1) Here we take one number 
 * 2) src position and destination positions are taken as input for that number
 * 3) The src and dest poistion are swapped within the number
 * 4) example num: 1000 => 8
 * 5) 	  src_pos: 3
 * 6)	 dest_pos: 7
 * 7) So the result is, 10000000 
 */

int printf(char *, ...);
int atoi(char *);

int main(int argc, char **argv)
{
	int num, d, s, res, dst_m, src_m;

	if(argc != 4) {
		num = 8, d=7, s=3;
		printf("No args passed, so taking defaults\n");
	} else {
		num = atoi(argv[1]);
		s = atoi(argv[2]);
		d = atoi(argv[3]);
	}

	printf("Number = %d, src = %d, dst = %d\n", num, s, d);

	src_m = 1 << s;			/* to get src bit high */
	dst_m = 1 << d;			/* to get dst bit high */

	if(num & src_m)	{
		res = num | dst_m;	/*if 1 get that to res, intermidiate*/
	} else {
		res = num & (~(dst_m));
	}

	if((num & dst_m)) {
		num = res | src_m;
	} else {
		num = res & (~(src_m));
	}

	printf("%x == %d\n", num, num);
	printf("%b == %d\n", num, num);
	return 0;
}


