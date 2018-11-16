# When use it #

- Big allocation (> 1Mo)

- Size unknown at compilation

- When used out of the allocation memory's scope  

	Exemple:
	```
	int	*create_tab(int nbr_case)
	{
		int	*tab;

		tab = malloc(sizeof(int) * nbr_case);
		return (tab);
	}

	int	main(void)
	{
		int	*tab;

		if ((tab = create_tab(10)) == NULL)
			return (0);
		tab[0] = 42;
		...
		...
		...
		free(tab);
		return (0);
	}
	```