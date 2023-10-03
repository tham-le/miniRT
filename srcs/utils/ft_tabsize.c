#include "utils.h"

int		ft_tabsize(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return ((int)i);
}