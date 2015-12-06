# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 18:20:41 by frmarinh          #+#    #+#              #
#    Updated: 2015/12/04 03:15:54 by frmarinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = srcs/main.c srcs/ft_putstr.c srcs/check_all.c srcs/ft_strlen.c srcs/ft_strnew.c

O_FILE = main.o ft_putstr.o check_all.o ft_strlen.o ft_strnew.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc -c $(SRCS) $(FLAGS) -I includes/
	@gcc $(O_FILE) $(FLAGS) -I includes/ -o $(NAME)

clean :
	@rm -rf $(O_FILE)

fclean : clean
	@rm -rf $(NAME)

re:		fclean all
