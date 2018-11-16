#include <stdlib.h>
#include <unistd.h>

//#define malloc(X) (NULL)

int	main(void)
{
	int	*magic;

	write(1, "test no protected malloc\n", 25);
	magic = (int *)malloc(*magic);
	*magic = 42;
	write(1, "OK\n", 3);
	return (0);
}

/*int	main(void)
{
	int	*magic;

	write(1, "test protected malloc\n", 22);
	if ((magic = (int *)malloc(*magic)) == NULL)
	{
		write(1, "return NULL\n", 12);
		return (0);
	}
	*magic = 42;
	write(1, "OK\n", 3);
	return (0);
}*/
