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

void	move_ants(t_info *info)
{
	if (info->paths->next != NULL)
		find_limit(info->paths->next,
				   ((int)(info->paths->content_size / sizeof(int))));
}