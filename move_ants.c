/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:12:08 by dburtnja          #+#    #+#             */
/*   Updated: 2017/04/24 13:17:57 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	push_to_end(int *path, int path_size, t_info *info)
{
	int	start;

	path_size--;
	while (path_size > 0)
	{
		if (path_size > 1 || (path_size - 1 == 0 && info->start->ant > path[0]))
		{
			if (path_size - 1 == 0)
				start = 0;
			else
				start = path[path_size - 1];
			find_the_room_by_nbr(start, path[path_size], info);
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
		ft_putendl("");
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
