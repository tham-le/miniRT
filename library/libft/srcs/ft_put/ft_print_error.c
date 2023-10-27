/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:22:43 by thi-le            #+#    #+#             */
/*   Updated: 2023/02/23 16:09:36 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_print_error(char *desc, int error)
{
	if (desc == NULL)
		return ((void) NULL);
	while (*desc)
		write(2, desc++, 1);
	write(2, "\n", 1);
	exit(error);
}
