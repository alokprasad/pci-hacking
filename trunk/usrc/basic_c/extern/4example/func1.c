
int printf(const char *, ...);

void func1()
{
	extern int i;

	printf("The value of i inside func1() is: %d \n", i);

}

int i = 20;

