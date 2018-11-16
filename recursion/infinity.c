void	ft_recursion(int nb)
{
	ft_recursion(nb + 1);
}

int		main(void)
{
	ft_recursion(42);
	return (0);
}
