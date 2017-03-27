//
// Created by denys on 26.03.17.
//

#include "lem_in.h"

int		already_been_hear(int *path, int step, int nbr)
{
	while (step > 0)
	{
		if (path[step - 1] == nbr)
			return (1);
		step--;
	}
	return (0);
}

int		start_rec(int step, int *path, t_rooms *from, t_info *info)
{
	t_list	*p;

	p = from->n_room;
	if (already_been_hear(path, step, from->nbr) == 1)
		return (0);
	path[step] = from->nbr;
	if (from->nbr == INT_MAX)
	{
		ft_lstadd(&(info->paths), ft_lstnew(path, sizeof(int) * (step + 1)));
		return (1);
	}
	while (p)
	{
		start_rec(step + 1, path, (t_rooms*)(p->content), info);
		p = p->next;
	}
	return (0);
}

void	remove_duplicate(t_list *paths)
{
	t_list	*p;
	int		i;
	int		*tab;

	i = 0;
	p = paths;
	while (p)
	{
		tab = (int*)p->content;
		while (i < (int)p->content_size)
		{
			ft_printf("%d, ", tab[i]);
			i++;
		}
		ft_putendl("");
		p = p->next;
	}
}

void	find_path(t_info *info)
{
	int		step;
	int		*path;

	step = 0;
	path = ft_memalloc(sizeof(int) * (info->nbr_rooms + 2));
	start_rec(step, path, info->start, info);
	if (info->paths == NULL)
		error(-10);
	remove_duplicate(info->paths);
}