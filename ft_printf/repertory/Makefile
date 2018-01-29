# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 04:57:12 by ppoinot           #+#    #+#              #
#    Updated: 2016/11/12 13:56:53 by ppoinot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
CC = gcc
rm = rm -f
CFLAGS = -Wall -Werror -Wextra
INCLUDES = ./libft.h
OBJ = $(SRC:.c=.o)
SRC = ft_printf.c \
	  ft_printf_checkflag.c \
	  get_flags.c \
	  init_flags.c \
	  inscribe.c \
	  inscribe_medium_var.c \
	  inscribe_simple_var.c \
	  is_a_thing.c \
	  is_there_precision.c \
	  is_there_an_attribute.c \
	  is_there_wof.c \
	  select_flag.c

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCLUDES)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all
