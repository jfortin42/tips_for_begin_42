# include <stdlib.h>
# include <stdio.h>

__attribute__((constructor)) void	begin()
{
	printf("begin\n");
}

int	main(void)
{
	int	*tab;

	if ((tab = malloc(sizeof(int) * 10)) == NULL)
		return (0);
	tab[0] = 42;
	printf("%d\n", tab[0]);
	// free(tab);
	// while (1)
	// 	;
	return (0);
}

__attribute__((destructor)) void	end()
{
	printf("end\n");
	while (1)
		;
}