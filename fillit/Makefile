# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/20 11:25:54 by ppoinot           #+#    #+#              #
#    Updated: 2016/01/20 11:58:53 by ppoinot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
rm = rm -f
CFLAGS = -Wall -Werror -Wextra
INCLUDES = ./
SUBDIR = ./libft
OBJ = $(SRC:.c=.o)
SRC = struct.c \
	  init.c \
	  backtracking.c \
	  bridge.c \
	  check.c \
	  solve.c

all : subsystem $(NAME)

subsystem :
	cd $(SUBDIR) && $(MAKE)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCLUDES)

clean:
	$(RM) $(OBJ)
	cd $(SUBDIR) && make clean

fclean: clean
	$(RM) $(NAME)
	cd $(SUBDIR) && make fclean

re: fclean all

.PHONY: re fclean clean all
