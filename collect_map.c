//
// Created by Denys Burtnjak on 3/24/17.
//

#include "lem_in.h"

void	add_connections(t_rooms *first, t_rooms *second)
{

}

t_rooms	*find_the_room(char *buf, t_info *info)
{
	t_rooms	*p;

	p = info->start;
	if (ft_strncmp(p->name, buf, ft_strlen(p->name)) == 0)
		return (info->start);
	p = info->rooms;
	while (p)
	{
		if (ft_strncmp(p->name, buf, ft_strlen(p->name)) == 0)
			return (p);
		p = p->next;
	}
	return (NULL);
}

void	collect_map(char *buf, t_info *info)
{
	t_rooms	*first;
	t_rooms	*second;

	if ((first = find_the_room(buf, info)) == NULL)
		error(-2);
	buf = buf + ft_strlen(first->name) + 1;
	if (buf[-1] != '-')
		error(-2);
	if ((second = find_the_room(buf, info)) == NULL)
		error(-2);
	add_connections(first, second);
}