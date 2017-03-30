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
	t_str	*p;

	p = from->n_room; //remove from path
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
		start_rec(step + 1, path, (t_rooms*)(p->str), info);
		p = p->next;
	}
	return (0);
}


char	*return_name(t_info *info, int nbr)
{
	t_rooms	*p;

	p = info->start;
	if (p->nbr == nbr)
		return (p->name);
	p = info->rooms;
	while (p)
	{
		if (p->nbr == nbr)
			return (p->name);
		p = p->next;
	}
	return (NULL);
}

void	print_list(t_list *paths, t_info *info)
{
	t_list	*p;
	int		i;
	int		*tab;

	p = paths;
	while (p)
	{
		i = 0;
		tab = (int*)p->content;
		while (i < ((int)p->content_size / (int)sizeof(int)))
		{
			ft_printf("%-15s", return_name(info, tab[i]));
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
	info->paths = remove_duplicate(info->paths);
	ft_memdel((void**)&path);
}