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

void	push_to_end(int *path, int path_size, t_info *info)
{
	path_size--;
	while (path_size > 0)
	{
		if (path_size - 1 == 0 && info->start->ant > path[0])
		{

		}
		path[path_size - 1]
		path_size--;
	}

//	if (info->start->ant > path[0])
}

void	push_ants(t_info *info)
{
	t_list	*p;
	int		*path;

	p = info->paths;
	while (info->start > 0)
	{
		while (p)
		{
			path = (int *) p->content;
			push_to_end(path, (int)(p->content_size / sizeof(int)), info);
			p = p->next;
		}
	}
}

void	move_ants(t_info *info)
{
	if (info->paths->next != NULL)
		find_limit(info->paths->next,
				   ((int)(info->paths->content_size / sizeof(int))));
	push_ants(info);
}