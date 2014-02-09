# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmorales <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/13 14:09:07 by fmorales          #+#    #+#              #
#    Updated: 2014/02/09 13:08:40 by fmorales         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c \
	  ft_strcmp.c \
	  ft_strlen.c \
	  ft_strsplit.c \
	  ft_strjoin.c	\
	  ft_strdup.c	\
	  ft_strcpy.c	\
	  ft_putstr.c	\
	  ft_strstr.c	\
	  ft_putendl.c	\
	  ft_putchar.c	\
	  ft_strncmp.c	\
	  ft_strtrim.c	\
	  ft_bzero.c	\
	  ft_putnbr.c	\
	  ft_itoa.c		\
	  ft_strnew.c	\
	  ft_realloc.c	\
	  ft_memcpy.c	\
	  ft_strsub.c 

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I .

RM = /bin/rm -f

all: $(NAME)

%.o: %.c
	@ gcc -c -o $@ $^ $(CFLAGS)

$(NAME): $(OBJ)
	@ ar rc $(NAME) $(OBJ)
	@ ranlib $(NAME)

clean:
	@ $(RM) $(OBJ)

fclean: clean
	@ $(RM) $(NAME)

re: fclean all
