//
// Created by Denys Burtnjak on 3/23/17.
//

#include "lem_in.h"

void	read_commands(t_info *info, char *buf)
{
	t_rooms	*p;

	info->p = info->p->next;
	if (info->p && ft_strcmp("start", buf) == 0)
			info->start = room_to_lst(info->p->str);
	else if (info->p && ft_strcmp("end", buf) == 0)
	{
		p = room_to_lst(info->p->str);
		p->nbr = INT_MAX;
		rooms_add_back(&(info->rooms), p);
	}
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
		info->ants = ft_atoi_move(&buf, &err, 0);
	else if (*buf != '#' && w_nbr == 1)
		collect_map(buf, info);
	else if (*buf != '#')
		error(-2);
	if (err && info->ants < 0)
		error(-2);
}

void	process_info_list(t_info *info)
{
	t_rooms	*p;
	char	*buf;
	int		i;

	i = 1;
	while (info->p)
	{
		buf = info->p->str;
		select_define(buf, info);
		if (info->p)
			info->p = info->p->next;
	}
	if (!(info->start) && info->ants < 0)
		error(-2);
	p = info->rooms;
	while (p && p->next)
	{
		p->nbr = i;
		i++;
		p = p->next;
	}
	info->nbr_rooms = i + 1;
	if (!p || p->nbr != INT_MAX)
		error(-2);
}