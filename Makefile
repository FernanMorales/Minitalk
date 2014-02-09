# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/07 20:10:24 by fmorales          #+#    #+#              #
#    Updated: 2014/02/09 22:19:10 by fmorales         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MKEX     = cc -g -O3 -o
FLAGS 	 = -Wall -Wextra -Werror
CLSRC 	 = main.c
CLOBJECT = $(CLSRC:.c=.o)
SVSRC 	 = server.c
SVOBJECT = $(SVSRC:.c=.o)
COMP     = cc -c
CLIENT   = client
SERVER   = server
NAME	 = minitalk

$(NAME) : all

all : $(CLIENT) $(SERVER)

$(CLIENT) : $(CLOBJECT)
	@$(MKEX) $(CLIENT) $(CLOBJECT) -L libft/ -lft

$(CLOBJECT) :
	@make -C libft/
	@$(COMP) $(CLSRC) $(FLAGS) -I./ -I libft/
	@echo "Compilation of C files succesful"

$(SERVER) : $(SVOBJECT)
	@$(MKEX) $(SERVER) $(SVOBJECT) -L libft/ -lft

$(SVOBJECT) :
	@make -C libft/
	@$(COMP) $(SVSRC) $(FLAGS) -I./ -I libft/
	@echo "Compilation of C files succesful"

clean :
	@/bin/rm -f $(CLOBJECT) $(SVOBJECT)
	@echo "Objects deleted"

fclean : clean
	@/bin/rm -f $(CLIENT) $(SERVER)
	@echo "Folder cleanup successful"

re : fclean all
