/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:38:42 by itchinda          #+#    #+#             */
/*   Updated: 2023/10/27 22:53:30 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

char	*dup_one(char c)
{
	char	*new_elt;

	new_elt = malloc(sizeof(char) + 1);
	if (!new_elt)
		return (NULL);
	new_elt[0] = c;
	new_elt[1] = '\0';
	return (new_elt);
}

char	*str_concate(char *s, char c)
{
	char	*str;
	int		i;

	if (!s)
	{
		s = ft_strdup("");
		if (!s)
			return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(s) + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i++] = c;
	str[i] = '\0';
	free(s);
	return (str);
}

char	*spaces_check(char *line)
{
	char	*new_line;
	int		i;

	new_line = NULL;
	i = 0;
	while (line[i] == 32 || (line[i] > 6 && line[i] < 13))
		i++;
	while (line[i])
	{
		if (line[i] == 32 || (line[i] > 6 && line[i] < 13))
			new_line = str_concate(new_line, ' ');
		else
			new_line = str_concate(new_line, line[i]);
		if (!new_line)
			return (NULL);
		i++;
	}
	return (new_line);
}
