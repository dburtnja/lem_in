#include "libft.h"

void				ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*p;

	p = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (p->next)
			p = p->next;
		p->next = new;
	}
}


