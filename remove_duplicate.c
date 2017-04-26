/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_duplicate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:13:20 by dburtnja          #+#    #+#             */
/*   Updated: 2017/04/24 13:20:52 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list	*find_shorter(t_list *paths)
{
	t_list	*shorter;
	int		comp;

	comp = INT_MAX;
	shorter = NULL;
	while (paths)
	{
		if (comp > (int)(paths->content_size / sizeof(int)))
		{
			comp = (int)(paths->content_size / sizeof(int));
			shorter = paths;
		}
		paths = paths->next;
	}
	return (shorter);
}

int		comper_two_paths(int *cont, int c_len, int *shorter, int s_len)
{
	int	i;
	int j;

	if (shorter == cont)
		return (0);
	i = 1;
	while (i + 1 < c_len)
	{
		j = 1;
		while (j + 1 < s_len)
		{
			if (cont[i] == shorter[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	remove_same_paths(t_list **paths, int *shorter, int short_len)
{
	t_list	*p;
	t_list	*buf;
	int		c_len;

	p = *paths;
	*paths = NULL;
	while (p)
	{
		buf = p;
		c_len = (int)(buf->content_size / sizeof(int));
		if (comper_two_paths(buf->content, c_len, shorter, short_len))
			ft_lstadd(paths, remove_from_lst(&p, buf));
		else
			p = p->next;
		print_list(p, NULL);
		ft_putchar('\n');
		print_list(*paths, NULL);
		ft_putchar('\n');
	}
	*paths = p;
}

t_list	*remove_duplicate(t_list *paths)
{
	t_list	*shorter;
	t_list	*ret;

	ret = NULL;
	while (paths)
	{
		shorter = find_shorter(paths);
		remove_same_paths(&paths, shorter->content,
						  (int)(shorter->content_size / sizeof(int)));
		ft_lstadd_back(&ret, shorter);
	}
	return (ret);
}
