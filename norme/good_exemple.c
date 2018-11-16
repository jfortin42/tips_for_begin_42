#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LINES 4
#define COLUMNS 6

typedef struct	s_cel
{
	int			tab[LINES][COLUMNS];
	int			line;
	int			column;
}				t_cel;

int	foreach_cellule(t_cel *cellule, int nbr, int (*f)(t_cel *, int))
{
	cellule->line = 0;
	while (cellule->line < LINES)
	{
		cellule->column = 0;
		while (cellule->column < COLUMNS)
		{
			if (f(cellule, nbr))
				return (1);
			cellule->column++;
		}
		cellule->line++;
	}
	return (0);
}

int	number_exists(t_cel *cellule, int nbr)
{
	if (cellule->tab[cellule->line][cellule->column] == nbr)
		return (1);
	return (0);
}

int	generate_number(t_cel *cellule, int nbr)
{
	int	save_line;
	int	save_col;

	save_line = cellule->line;
	save_col = cellule->column;
	nbr = rand() % (LINES * COLUMNS);
	while (foreach_cellule(cellule, nbr, number_exists))
		nbr = rand() % (LINES * COLUMNS);
	cellule->tab[save_line][save_col] = nbr;
	cellule->line = save_line;
	cellule->column = save_col;
	return (0);
}

int	print_cellule(t_cel *cellule, int nbr)
{
	(void)nbr;
	printf("%d ", cellule->tab[cellule->line][cellule->column]);
	if (cellule->column == COLUMNS - 1)
		printf("\n");
	return (0);
}

int	main(void)
{
	t_cel	cellule;

	srand(time(NULL));
	memset(&cellule, -1, sizeof(cellule));
	foreach_cellule(&cellule, 0, generate_number);
	foreach_cellule(&cellule, 0, print_cellule);
	return (0);
}
