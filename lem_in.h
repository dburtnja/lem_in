//
// Created by Denys Burtnjak on 3/23/17.
//

#ifndef LEM_IN
# define LEM_IN

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct	s_rooms
{
	char		*name;
	int			x;
	int			y;
	int			ant;
	int			nbr;
}				t_rooms;

typedef struct	s_info
{
	t_rooms		*start;
	t_rooms		*end;
}				t_info;

#endif
