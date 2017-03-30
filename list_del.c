//
// Created by denys on 30.03.17.
//

#include "lem_in.h"

void	list_del(t_list *del)
{
	ft_memdel(&((del)->content));
	ft_memdel((void**)&del);
}

void	free_list(t_list **head)
{
	t_list	*p;
	t_list	*temp;

	p = *head;
	while (p)
	{
		temp = p;
		p = p->next;
		list_del(temp);
	}
}