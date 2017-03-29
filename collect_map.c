//
// Created by Denys Burtnjak on 3/24/17.
//

#include "lem_in.h"

void	add_connections(t_rooms *first, t_rooms *second)
{
	str_lst_add(&(first->n_room), new_str_lst((char*)second));
	str_lst_add(&(second->n_room), new_str_lst((char*)first));
}

t_rooms	*find_the_room(char *buf, t_info *info, size_t b_len)
{
	t_rooms	*p;
	size_t	len;

	p = info->start;
	len = ft_strlen(p->name);
	if (ft_strncmp(p->name, buf, b_len > len ? b_len : len) == 0)
		return (info->start);
	p = info->rooms;
	while (p)
	{
		len = ft_strlen(p->name);
		if (ft_strncmp(p->name, buf, b_len > len ? b_len : len) == 0)
			return (p);
		p = p->next;
	}
	return (NULL);
}

void	collect_map(char *buf, t_info *info)
{
	t_rooms	*first;
	t_rooms	*second;

	if ((first = find_the_room(buf, info, (size_t)ft_lentoc(buf, '-'))) == NULL)
		error(-2);
	buf = buf + ft_strlen(first->name) + 1;
	if (buf[-1] != '-')
		error(-2);
	if ((second = find_the_room(buf, info, ft_strlen(buf))) == NULL)
		error(-2);
	add_connections(first, second);
}