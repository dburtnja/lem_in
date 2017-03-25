//
// Created by Denys Burtnjak on 3/24/17.
//

#include "lem_in.h"

void	read_rooms(char *buf, char **name, int *x, int *y)
{
	int		i;
	int		err;

	if (*buf == 0)
		error(-2);
	if (!(*name = ft_strsub(buf, 0, (size_t)(i = ft_lentoc(buf, ' ')))))
		error(-1);
	if (**name == 0)
		error(-2);
	buf = buf + i;
	*x = ft_atoi_move(&buf, &err, 1);
	if (err)
		error(-2);
	*y = ft_atoi_move(&buf, &err, 1);
	if (err)
		error(-2);
}

t_rooms	*room_to_lst(char *buf)
{
	t_rooms	*ret;

	if (!(ret = new_room()))
		exit(-1);
	read_rooms(buf, &(ret->name), &(ret->x), &(ret->y));
	return (ret);
}