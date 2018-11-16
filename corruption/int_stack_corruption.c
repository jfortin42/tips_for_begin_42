#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;

	a = 42;
	b = 33;
	printf("addresses          a: [%p]\n"
		   "                   b: [%p]\n", &a, &b);

	printf("before overflow -> a: [%d]\n"
		   "                   b: [%d]\n", a, b);

	//overflow
	*(&b + 1) = 66;

	printf("after overflow  -> a: [%d]\n"
		   "                   b: [%d]\n", a, b);

}
