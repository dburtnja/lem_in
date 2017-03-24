//
// Created by Denys Burtnjak on 3/24/17.
//

#include "lem_in.h"

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
	else
	{
		buf->r = (t_rooms**)ft_memalloc(sizeof(t_rooms*) * 2);
		if (!(buf->r))
			error(-1);
	}
	return (buf);
}