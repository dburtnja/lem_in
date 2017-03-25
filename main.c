//
// Created by Denys Burtnjak on 3/23/17.
//

#include "lem_in.h"

void	error(int nbr)
{
	if (nbr == -1)
		ft_printf("ERROR\n");
	else
		ft_printf("ERROR reading\n");
	exit(nbr);
}

int		main(void)
{
	t_info	info;

	ft_bzero(&info, sizeof(info));
	info.ants = -1;
	read_define(&info);
	return (0);
}