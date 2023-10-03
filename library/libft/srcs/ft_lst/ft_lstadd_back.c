/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:53:59 by thi-le            #+#    #+#             */
/*   Updated: 2023/01/30 16:04:39 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newlst)
{
	t_list	*p;

	if (lst)
	{
		if (*lst)
		{
			p = ft_lstlast(*lst);
			p->next = newlst;
		}
		else
			*lst = newlst;
	}
}
