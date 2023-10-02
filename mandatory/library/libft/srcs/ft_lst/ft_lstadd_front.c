/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:34:29 by thi-le            #+#    #+#             */
/*   Updated: 2023/01/30 16:04:09 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Adds the node ’newlst’ at the beginning of the list */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *newlst)
{
	if (lst)
	{
		if (*lst)
			newlst->next = *lst;
		*lst = newlst;
	}
}
