#include "utils.h"

void	ft_freearr(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	ft_freearr_int(int **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}


int		ft_tabsize(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return ((int)i);
}