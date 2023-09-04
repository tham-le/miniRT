/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itchinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:19:51 by itchinda          #+#    #+#             */
/*   Updated: 2023/08/16 16:19:52 by itchinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"


char	**ft_subarr(char **tab, int start, int size)
{
	char	**arr;
	int		i;

	if (!tab)
		return (NULL);
	arr = malloc(sizeof(char *) * (size + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
		arr[i++] = ft_strdup(tab[start++]);
	arr[i] = NULL;
	return (arr);
}
