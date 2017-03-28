//
// Created by denys on 28.03.17.
//

#include "lem_in.h"

void	find_limit(t_list *paths, int first_len)
{
	int		i;
	int		len;

	i = 0;
	while (paths)
	{
		len = (int)(paths->content_size / sizeof(int)) - first_len;
		((int*)(paths->content))[0] = len + i;
		i++;
		paths = paths->next;
	}
}

void	add_to_room(int nbr, t_rooms *p)
{
	if (p->nbr == INT_MAX)
		(p->ant)++;
	else
		(p->ant) = nbr;
}

int		remove_from_room(t_rooms *p, int ant_nbr)
{
	int		temp;

	if (p->nbr == 0)
	{
		// if empty
		(p->ant)--;
		return (ant_nbr - p->ant);
	}
	else
	{
		temp = p->ant;
		p->ant = 0;
		return (temp);
	}
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
	while (p)
	{
		if (p->nbr == f_room)
			from = p;
		if (p->nbr == t_room)
			in = p;
		p = p->next;
	}
	if (from == NULL && in == NULL)
		error(-15);
	add_to_room(remove_from_room(from, info->ants), in);
}

void	push_to_end(int *path, int path_size, t_info *info)
{
	path_size--;
	while (path_size > 0)
	{
		if (path_size > 1 || (path_size - 1 == 0 && info->start->ant > path[0]))
		{
			find_the_room_by_nbr(path[path_size - 1], path[path_size], info);
		}
		path_size--;
	}
}

void	push_ants(t_info *info, t_rooms *last)
{
	t_list	*p;
	int		*path;


	while (last->ant != info->ants)
	{
		p = info->paths;
		while (p)
		{
			path = (int *)p->content;
			push_to_end(path, (int)(p->content_size / sizeof(int)), info);
			p = p->next;
		}
	}
}

void	move_ants(t_info *info)
{
	t_rooms	*last_room;

	if (info->paths->next != NULL)
		find_limit(info->paths->next,
				   ((int)(info->paths->content_size / sizeof(int))));
	last_room = info->rooms;
	while (last_room && last_room->nbr != INT_MAX)
		last_room = last_room->next;
	push_ants(info, last_room);
}