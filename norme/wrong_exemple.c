#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

typedef struct	s_all
{
	int			i;
	int			j;
	int			a;
	int			b;
	int			t;
	int			m;
}				t_all;

void genere_cellules(int cellule[4][6], t_all *all);

int		main(void)
{
	int 		i;
	int			j;
	static int	cellule[4][6] = {0};
	t_all		all;

	genere_cellules(cellule, &all);
	i = 0;
	while (i < 4)
	{
		printf("\n");
		j = 0;
		while (j < 6)
		{
			printf("%d ",cellule[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}

void	genere_cellules2(int cellule[4][6], t_all *all)
{
	while (all->t == 0)
	{
		all->m = rand()%24;
		all->a = 0;
		while (all->a < 4)
		{
			while (all->b < 6)
			{
				if (all->m == cellule[all->a][all->b])
					all->t = 0;
				else
				{
					all->t = 1;
					cellule[all->i][all->j] = all->m;
				}
				all->b++;
			}
			all->a++;
		}
	}
}

void	genere_cellules3(int cellule[4][6], t_all *all)
{
	all->m = rand()%24;
	all->t = 0;
	all->a = 0;
	while (all->a < 4)
	{
		all->b = 0;
		while (all->b < 6)
		{
			if (all->m == cellule[all->a][all->b])
				genere_cellules2(cellule, all);
			else
				cellule[all->i][all->j] = all->m;
			all->b++;
		}
		all->a++;
	}
}

void	genere_cellules(int cellule[4][6], t_all *all)
{
	srand (time(NULL));
	all->i = 0;
	while (all->i < 4)
	{
		all->j = 0;
		while (all->j < 6)
		{
			genere_cellules3(cellule, all);
			all->j++;
		}
		all->i++;
	}
}