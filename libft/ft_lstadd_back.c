#include "../inc/miniRT.h"

void	ft_lstaddback(t_objs **alst, t_objs *new)
{
	t_objs *ptr;

	if (alst && (*alst)->polym)
	{
		ptr = *alst;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
	else if(*alst)
	{
		*alst = new;
		(*alst)->next = NULL;
	}
}