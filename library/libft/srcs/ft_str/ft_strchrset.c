/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:43:40 by thi-le            #+#    #+#             */
/*   Updated: 2023/05/17 14:10:51 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// function to return a pointer of the first occurence in a str if
// it belongs to a charset

char	*ft_strchrset(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (ft_strchr(charset, str[i]))
			return (&str[i]);
		i++;
	}
	return (NULL);
}
