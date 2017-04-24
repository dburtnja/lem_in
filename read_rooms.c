/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:12:55 by dburtnja          #+#    #+#             */
/*   Updated: 2017/04/24 13:19:48 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_rooms(char *buf, char **name, int *x, int *y)
{
	int		i;
	int		err;

	i = ft_lentoc(buf, ' ');
	if (*buf == 0)
		error(-2);
	if (!(*name = ft_strsub(buf, 0, (size_t)i)))
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
