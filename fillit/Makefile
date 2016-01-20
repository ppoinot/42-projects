# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/20 11:25:54 by ppoinot           #+#    #+#              #
#    Updated: 2016/01/20 15:28:40 by ppoinot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
rm = rm -f
CFLAGS = -Wall -Werror -Wextra
INCLUDES = ./
SUBDIR = ./libft
LIBFT = -L libft
OBJ = $(SRC:.c=.o)
SRC = init.c \
	  struct.c \
	  backtracking.c \
	  bridge.c \
	  check.c \
	  solve.c

all : subsystem $(NAME)

subsystem :
	make -C ./libft

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(LIBFT) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c -I $(INCLUDES) $*.c

clean:
	$(RM) $(OBJ)
	cd $(SUBDIR) && make clean

fclean: clean
	$(RM) $(NAME)
	cd $(SUBDIR) && make fclean

re: fclean all

.PHONY: re fclean clean subsystem all
