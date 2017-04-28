/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:11:54 by dburtnja          #+#    #+#             */
/*   Updated: 2017/04/28 19:04:50 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error(int nbr)
{
	if (nbr == -1)
		ft_printf("ERROR\n");
	else if (nbr == -10)
		ft_printf("ERROR: can't find path\n");
	else if (nbr == -15)
		ft_printf("ERROR: no ants\n");
	else
		ft_printf("ERROR reading\n");
	exit(nbr);
}

void	read_into_list(t_info *info)
{
	int		gnl;
	char	*buf;

	while ((gnl = get_next_line(0, &buf)) > 0)
	{
		if (*buf == 0)
		{
			ft_strdel(&buf);
			error(-2);
		}
		str_lst_add_back(&(info->head), new_str_lst(buf));
	}
	if (buf && *buf == 0)
		ft_strdel(&buf);
	if (gnl == -1)
		error(-2);
}

int		main(int argc, char **argv)
{
	t_info	info;

	ft_bzero(&info, sizeof(info));
	info.ants = -1;
	read_into_list(&info);
	info.p = info.head;
	process_info_list(&info);
	info.start->ant = info.ants;
	find_path(&info);
	if (info.start->ant < 1)
		error(-15);
	print_and_dell_str_lst(info.head);
	if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'p')
		print_list(info.paths, &info);
	move_ants(&info);
	return (0);
}
