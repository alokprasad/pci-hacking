int printf(const char *, ...);

//extern int a;
extern int g;

void fun1()
{
	g = 30;
//	printf("inside fun1() a: %d", a);	// This cannot be printed as the 'a' is local varible
	printf("inside fun1() g: %d \n", g);

}

/* Only the global variables can be declared as extern */
