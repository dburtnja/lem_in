//
// Created by Denys Burtnjak on 3/23/17.
//

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
			break ;//error(-2);
		str_lst_add_back(&(info->head), new_str_lst(buf));
	}
	if (gnl == -1)
		error(-2);
}

int		main(void)
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
	print_and_dell_str_lst(info.head, 1, 1);
	print_list(info.paths, &info);
	move_ants(&info);
	free_list(&(info.paths));
	rooms_free(&(info.start));
	rooms_free(&(info.rooms));
	return (0);
}