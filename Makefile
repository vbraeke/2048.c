# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbraeke <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/31 19:56:33 by vbraeke           #+#    #+#              #
#    Updated: 2016/01/31 20:15:17 by vbraeke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c\
	tools.c\
	replace.c\
	sum.c\
	map_comp.c\
	print.c\
	load_game.c\
	replace_all.c \

CC = gcc
FLAG = -lncurses -Wall -Wextra -Werror
NAME = 2048
LIB = libft.a
OBJ = $(SRC:.c=.o)

all:
	$(CC) $(FLAG) -o $(NAME) $(SRC) $(LIB)

clean:
	@rm -fv $(OBJ)

fclean:
	@rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
