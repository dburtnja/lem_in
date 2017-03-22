# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/09 16:49:11 by dburtnja          #+#    #+#              #
#    Updated: 2017/03/15 15:19:56 by dburtnja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft/libft.a

NAME = ./resources/players/filler #change to ./
BONUS = ./resources/bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC =	main.c\
        read_map.c\
        find_coordinates.c\
        find_hostile.c\
        read_tokens.c\
        find_place.c\
        help_find_place.c

B_SRC = bonus/check_flag.c\
        bonus/out_filler.c\
        bonus/read_input.c

OBJ = $(SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)

all:	$(LIB) $(NAME) $(BONUS)

$(LIB):
		make -C ./libft

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB)
%.o: %.c
		@$(CC) -c $(CFLAGS) -o $@ $<

$(BONUS): $(B_OBJ)
		@$(CC) $(CFLAGS) $(B_OBJ) -o $(BONUS) $(LIB)
%.o: %.c
		@$(CC) -c $(CFLAGS) -o $@ $<


clean:
		@make clean -C ./libft
		@rm -f $(OBJ)
		@rm -f $(B_OBJ)

fclean:
		@make fclean -C ./libft
		@make clean
		@rm -f $(NAME)
		@rm -f $(BONUS)

re:
		@make fclean
		@make all
