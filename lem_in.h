//
// Created by Denys Burtnjak on 3/23/17.
//

#ifndef LEM_IN
# define LEM_IN

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

# define INT_MAX 2147483647

typedef struct		s_str
{
	char			*str;
	struct s_str	*next;
}					t_str;

typedef struct		s_rooms
{
	char			*name;
	int				x;
	int				y;
	int				ant;
	int				nbr;
	struct s_rooms	*next;
	int				conn;
	t_list			*n_room;
}					t_rooms;

typedef struct		s_info
{
	int				ants;
	t_str			*p;
	t_str			*head;
	t_rooms			*start;
	t_rooms			*rooms;
}					t_info;

void				error(int nbr);
void				process_info_list(t_info *info);
void				read_rooms(char *buf, char **name, int *x, int *y);
t_rooms				*room_to_lst(char *buf);
void				collect_map(char *buf, t_info *info);


void				rooms_add_back(t_rooms **alst, t_rooms *new);
t_rooms				*new_room(void);
void				room_add(t_rooms **alst, t_rooms *new);
int					word_nbr(char *buf);

t_str				*new_str_lst(char *str);
void				str_lst_add_back(t_str **head, t_str *new);
void				print_and_dell_str_lst(t_str *head);

#endif
