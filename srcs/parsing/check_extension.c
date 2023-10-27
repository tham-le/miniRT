/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:44:18 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/27 22:53:27 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdlib.h>

int	check_extension(char *file_name)
{
	char	*ext;

	if (!ft_strchr(file_name, '.'))
		return (1);
	ext = file_name + ft_strlen(file_name) - 3;
	if (ft_strncmp(ext, ".rt", ft_strlen(ext)))
		return (1);
	return (0);
}
