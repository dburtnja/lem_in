//
// Created by denys on 29.03.17.
//

#include "lem_in.h"

void	add_to_room(int nbr, t_rooms *p, int *start_line)
{
	if (nbr > 0)
	{
		if (p->nbr == INT_MAX)
			(p->ant)++;
		else
			(p->ant) = nbr;
		if (*start_line == 1)
			ft_printf("L%d-%s", nbr, p->name);
		else
			ft_printf(" L%d-%s", nbr, p->name);
		*start_line = 0;
	}
}

int		remove_from_room(t_rooms *p, int ant_nbr)
{
	int		temp;

	if (p->nbr == 0 && p->ant > 0)
	{
		(p->ant)--;
		return (ant_nbr - p->ant);
	}
	else if (p->ant > 0)
	{
		temp = p->ant;
		p->ant = 0;
		return (temp);
	}
	return (0);
}

void	find_the_room_by_nbr(int f_room, int t_room, t_info *info)
{
	t_rooms	*p;
	t_rooms	*from;
	t_rooms	*in;

	from = NULL;
	in = NULL;
	if (info->start->nbr == f_room)
		from = info->start;
	p = info->rooms;
	while (p && (!from || !in))
	{
		if (p->nbr == f_room)
			from = p;
		if (p->nbr == t_room)
			in = p;
		p = p->next;
	}
	if (from == NULL && in == NULL)
		error(-15);
	add_to_room(remove_from_room(from, info->ants), in, &(info->startline));
}