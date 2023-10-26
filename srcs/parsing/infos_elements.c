/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:11:09 by itchinda          #+#    #+#             */
/*   Updated: 2023/10/26 20:33:54 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

char	*before_dot(char *elems, int	*dot)
{
	int	i;

	i = 0;
	while (elems[i] && elems[i] != '.')
	{
		i++;
		(*dot)++;
	}
	return (ft_substr(elems, 0, *dot));
}

char	*after_dot(char *elems, int	*dot)
{
	int	i;

	i = *dot + 1;
	while (elems[i])
		i++;
	return (ft_substr(elems, *dot + 1, ft_strlen(elems)));
}

int	nb_dots(char *elems)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (elems[i])
	{
		if (elems[i] == '.')
			count++;
		i++;
	}
	return (count);
}

int	only_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] == '-' && i == 0)
			{
				i++;
				continue ;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_float(char *elems)
{
	char	*bef_dot;
	char	*aft_dot;
	int		dot;

	dot = 0;
	bef_dot = before_dot(elems, &dot);
	aft_dot = after_dot(elems, &dot);
	if (nb_dots(elems) > 1)
		return (1);
	if (only_digits(bef_dot) || only_digits(aft_dot))
		return (free(bef_dot), free(aft_dot), 1);
	free(bef_dot);
	free(aft_dot);
	return (0);
}
