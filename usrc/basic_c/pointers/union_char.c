/*
 * 1) char *p = (char*)&one.i; -> address of the one.i, type casted to character pointer, so the address of the starting byte of 'i' gets pointed to this
 * 2) The pointer gets incremented, as shown below
	@0x7fff3109a310 - 34
	@0x7fff3109a311 - 12
	@0x7fff3109a312 - 0
	@0x7fff3109a313 - 0
	The character c: 4 @ 0x7fff3109a310 , Here the last byte of the integer is shown
*/
union test{
	int i;
	char c;
};

void main()
{
	int i;
	union test one;
	one.i = 0x1234;
	char *p = (char*)&one.i;	

	for(i=0; i<4; i++, p++) {
		printf("@%p - %x\n", p, *p);
	}

	printf("The character c: %c @ %p\n", one.c, &one.c);
}

