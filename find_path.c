//
// Created by denys on 26.03.17.
//

#include "lem_in.h"

int		start_rec(int step, int *path, t_rooms *from, t_info *info)
{
	t_list	*p;

	p = from->n_room;
	if (from->nbr == INT_MAX)
	{

		add_path(info, );
		return (1);
	}
	while (p)
	{
		path[step] = from->nbr;
		start_rec(step + 1, path, (t_rooms*)p->content, info)

		p = p->next;
	}
	return (0);
}

void	find_path(t_info *info)
{
	int		step;
	int		*path;

	step = 0;
	path = ft_memalloc(sizeof(int) * info->nbr_rooms)
	start_rec(step, path, info->start, info);
}