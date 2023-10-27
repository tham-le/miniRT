/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:38:41 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/26 21:38:51 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "mlx.h"

void	ft_lstdelone(t_light *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst);
}

void	ft_lstdel_obj(t_objs *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst);
}

void	ft_clear_light(t_light **lst, void (*del)(void *))
{
	t_light	*lst2;

	if (lst)
	{
		while (*lst)
		{
			lst2 = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = lst2;
		}
	}
}

void	ft_clear_obj(t_objs **lst, void (*del)(void *))
{
	t_objs	*lst2;

	if (lst)
	{
		while (*lst)
		{
			lst2 = (*lst)->next;
			ft_lstdel_obj(*lst, del);
			*lst = lst2;
		}
	}
}
