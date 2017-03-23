//
// Created by Denys Burtnjak on 3/23/17.
//

#include "lem_in.h"

void	read_commands(t_info *info, char *buf)
{
	int		gnl;

	if (ft_strcmp("start", buf) == 0)
	{
		if ((gnl = get_next_line(0, &buf)) > 0)


	}
	else if (ft_strcmp("end", buf) == 0)
	{

	}
}

void	read_define(t_info *info)
{
	int		gnl;
	char	*buf;

	while ((gnl = get_next_line(0, &buf)) > 0)
	{
		if (buf[0] == '#' && buf[1] == '#')
			read_commands(info, buf + 2);
	}
	if (gnl == -1)
		exit(-1);
}