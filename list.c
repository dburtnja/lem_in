//
// Created by Denys Burtnjak on 3/24/17.
//

#include "lem_in.h"

t_list	*remove_from_lst(t_list **head, t_list *rem)
{
	t_list	*p;

	p = *head;
	if (*head == rem)
		*head = (*head)->next;
	else if (p)
	{
		while (p->next && p->next != rem)
			p = p->next;
		if (p->next == rem)
			p->next = rem->next;
	}
	rem->next = NULL;
	return (rem);
}

void	rooms_add_back(t_rooms **alst, t_rooms *new)
{
	t_rooms	*p;

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

void	room_add(t_rooms **alst, t_rooms *new)
{
	new->next = *alst;
	*alst = new;
}

t_rooms	*new_room(void)
{
	t_rooms *buf;

	buf = (t_rooms*)ft_memalloc(sizeof(t_rooms));
	if (buf == NULL)
		error(-1);
	return (buf);
}

void	rooms_free(t_rooms **rooms)
{
	t_rooms *p;
	t_rooms	*temp;

	p = *rooms;
	while (p)
	{
		temp = p;
		p = p->next;
		print_and_dell_str_lst(temp->n_room, 0, 0);
		free(temp);
	}
}