# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/28 14:21:40 by vcharles          #+#    #+#              #
#    Updated: 2016/01/04 18:43:16 by vcharles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME =	ft_abs.c				\
			ft_atoi.c				\
			ft_bzero.c				\
			ft_isalnum.c			\
			ft_isalpha.c			\
			ft_isascii.c			\
			ft_isdigit.c			\
			ft_isprime.c			\
			ft_isprint.c			\
			ft_isspace.c			\
			ft_itoa.c				\
			ft_lstadd.c				\
			ft_lstdel.c				\
			ft_lstdelone.c			\
			ft_lstiter.c			\
			ft_lstmap.c				\
			ft_lstnew.c				\
			ft_memalloc.c			\
			ft_memccpy.c			\
			ft_memchr.c				\
			ft_memcmp.c				\
			ft_memcpy.c				\
			ft_memdel.c				\
			ft_memmove.c			\
			ft_memset.c				\
			ft_power.c				\
			ft_putchar.c			\
			ft_putchar_fd.c			\
			ft_putendl.c			\
			ft_putendl_fd.c			\
			ft_putnbr.c				\
			ft_putnbr_fd.c			\
			ft_putstr.c				\
			ft_putstr_fd.c			\
			ft_realloc.c			\
			ft_strcat.c				\
			ft_strchr.c				\
			ft_strclr.c				\
			ft_strcmp.c				\
			ft_strcpy.c				\
			ft_strdup.c				\
			ft_strdel.c				\
			ft_strequ.c				\
			ft_striter.c			\
			ft_striteri.c			\
			ft_strlcat.c			\
			ft_strlen.c				\
			ft_strjoin.c			\
			ft_strmap.c				\
			ft_strmapi.c			\
			ft_strncat.c			\
			ft_strncmp.c			\
			ft_strncpy.c			\
			ft_strnequ.c			\
			ft_strnew.c				\
			ft_strnstr.c			\
			ft_strrchr.c			\
			ft_strsplit.c			\
			ft_strstr.c				\
			ft_strsub.c				\
			ft_strtrim.c			\
			ft_swap.c				\
			ft_tolower.c			\
			ft_toupper.c

SRCPATH = ./

SRC = $(addprefix $(SRCPATH), $(SRCNAME))

OBJNAME = $(SRCNAME:.c=.o)

OBJPATH = ./obj/

OBJ = $(addprefix $(OBJPATH), $(OBJNAME))

LIBPATH = ./

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJPATH)%.o:	$(SRCPATH)%.c
	@mkdir -p $(OBJPATH)
	@gcc $(FLAGS) -I $(LIBPATH) -c $< -o $@

clean:
	@rm -rf $(OBJPATH)

fclean: clean
	@rm -f $(NAME)

re:		fclean	all

.PHONY: all clean fclean re
