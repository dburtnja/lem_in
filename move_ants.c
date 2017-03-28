//
// Created by denys on 28.03.17.
//

#include "lem_in.h"

void	find_limit(t_list *paths, int ants, int f_len)
{
	int		i;
	int		size;
	int		l_size;
	int 	i_s;

	i_s = (int)sizeof(int);
	i = 0;
	size = 0;
	l_size = 0;
	while (paths)
	{
		size += (((int)(paths->content_size) / i_s) - f_len);
		f_len = (((int)(paths->content_size) / i_s));
		((int*)(paths->content))[0] = ants - (l_size == size ? 0 : size + i);
		l_size = size;
		i++;
		paths = paths->next;
	}
}

void	move_ants(t_info *info)
{
	if (info->paths->next != NULL)
		find_limit(info->paths->next, info->start->ant,
				   ((int)(info->paths->content_size / sizeof(int))));
}