//
// Created by denys on 27.03.17.
//

#include "lem_in.h"

t_list	*find_shorter(t_list *p, t_list *ret)
{
	t_list	*shorter;
	int		comp;

	comp = INT_MAX;
	shorter = NULL;
	while (p)
	{
		if ((int)(p->content_size) < comp && different_array(ret, p))
		{
			comp = (int)p->content_size;
			shorter = p;
		}
		p = p->next;
	}
	return (shorter);
}

int		find_nbr_in_lst(int nbr, t_list *head)
{
	int		i;

	while (head)
	{
		i = 0;
		while (i < (int)head->content_size)
		{
			if (nbr != 0 && nbr != INT_MAX && nbr == ((int*)(head->content))[i])
				return (1);
			i++;
		}
		head = head->next;
	}
	return (0);
}

int		different_array(t_list *head, t_list *new)
{
	int		i;

	i = 0;
	if (head == NULL)
		return (1);
	while (i < ((int)new->content_size) / (int)sizeof(int))
	{
		if (find_nbr_in_lst(((int*)(new->content))[i], head) == 1)
			return (0);
		i++;
	}
	return (1);
}

t_list	*remove_duplicate(t_list *paths)
{
	t_list	*shorter;
	t_list	*ret;

	ret = NULL;
	while (paths)
	{
		shorter = find_shorter(paths, ret);
		if (different_array(ret, shorter))
			ft_lstadd_back(&ret, remove_from_lst(&paths, shorter));
		else
			list_del((remove_from_lst(&paths, shorter)));

	//	ft_putendl("");
		//print_list(paths, info);
	}
	return (ret);
}