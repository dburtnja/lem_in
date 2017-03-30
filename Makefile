# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/09 16:49:11 by dburtnja          #+#    #+#              #
#    Updated: 2017/03/29 16:33:28 by dburtnja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft/libft.a
FT_PRINTF = libft/ft_printf/libftprintf.a

NAME = lem_in

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC =	main.c\
        read_define.c\
        read_rooms.c\
        list.c\
        word_nbr.c\
        collect_map.c\
        str_lst.c\
        find_path.c\
        remove_duplicate.c\
        move_ants.c\
        find_the_room_by_nbr.c

OBJ = $(SRC:.c=.o)

all:	$(FT_PRINTF) $(LIB) $(NAME)

$(LIB):
		make -C ./libft

$(FT_PRINTF):
		make -C ./libft/ft_printf

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB) $(FT_PRINTF)
%.o: %.c
		@$(CC) -c $(CFLAGS) -o $@ $<

clean:
		@make clean -C ./libft
		@make clean -C ./libft/ft_printf
		@rm -f $(OBJ)
fclean:
		@make fclean -C ./libft
		@make fclean -C ./libft/ft_printf
		@make clean
		@rm -f $(NAME)
		@rm -f $(BONUS)

re:
		@make fclean
		@make all
