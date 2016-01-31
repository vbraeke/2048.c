# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbraeke <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/30 18:41:59 by vbraeke           #+#    #+#              #
#    Updated: 2016/01/30 18:42:01 by vbraeke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = game.c
CC = gcc
FLAG = -lncurses 
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
	