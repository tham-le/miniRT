#include "../inc/miniRT.h"

void	ft_lstaddback(t_objs **alst, t_objs *new)
{
	t_objs *ptr;

	if (alst && (*alst)->polym)
	{
		printf("la\n");
		ptr = *alst;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
	else if(*alst)
	{
		printf("ici\n");
		*alst = new;
		(*alst)->next = NULL;
	}
}