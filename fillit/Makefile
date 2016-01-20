# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/20 11:25:54 by ppoinot           #+#    #+#              #
#    Updated: 2016/01/20 15:22:03 by ppoinot          ###   ########.fr        #
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
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

subsystem :
	make -C ./libft

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

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
