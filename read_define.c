//
// Created by Denys Burtnjak on 3/23/17.
//

#include "lem_in.h"

void	read_commands(t_info *info, char *buf)
{
	int		gnl;

	gnl = -1;
	if (ft_strcmp("start", buf) == 0)
	{
		if ((gnl = get_next_line(0, &buf)) > 0)
			read_rooms(buf, &(info->start->name), &(info->start->x),
					   &(info->start->y));
	}
	else if (ft_strcmp("end", buf) == 0)
	{
		if ((gnl = get_next_line(0, &buf)) > 0)
			rooms_add_back(&(info->rooms), room_to_lst(buf));
	}
	if (gnl != 1)
		error(-2);
}

int		if_all_num(char *str)
{
	while (*str != 0)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

void	select_define(char *buf, t_info *info)
{
	int		w_nbr;
	int		err;

	err = 0;
	w_nbr = word_nbr(buf);
	if (buf[0] == '#' && buf[1] == '#')
		read_commands(info, buf + 2);
	else if (*buf != '#' && w_nbr == 3)
		room_add(&(info->rooms), room_to_lst(buf));
	else if (if_all_num(buf))
		info->start->ant = ft_atoi_move(&buf, &err, 0);
	else if (*buf != '#' && w_nbr == 1)
		collect_map(buf, info);
	else if (*buf != '#')
		error(-2);
	if (err && info->start->ant < 0)
		error(-2);
}

void	read_define(t_info *info)
{
	int		gnl;
	char	*buf;

	while ((gnl = get_next_line(0, &buf)) > 0)
	{
		if (*buf == 0)
			error(-2);
		select_define(buf, info);
		ft_printf("%s\n", buf);
		ft_strdel(&buf);
	}
	if (gnl == -1)
		error(-2);
}