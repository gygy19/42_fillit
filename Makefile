# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 18:20:41 by frmarinh          #+#    #+#              #
#    Updated: 2015/12/15 00:49:10 by frmarinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = srcs/main.c srcs/check_all.c srcs/do_struct.c srcs/ft_lstaddendtrix.c srcs/check_suite.c srcs/tetrixcmp.c srcs/tetrixcmp_suite.c srcs/do_struct_bytes.c srcs/system.c srcs/formulas.c srcs/path_finding.c srcs/output.c

O_FILE = main.o check_all.o do_struct.o ft_lstaddendtrix.o check_suite.o tetrixcmp.o tetrixcmp_suite.o do_struct_bytes.o system.o formulas.o path_finding.o output.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc -c $(SRCS) $(FLAGS) -I includes/
	@gcc $(O_FILE) $(FLAGS) -I includes/ -o $(NAME) -L includes/ -lft

clean :
	@rm -rf $(O_FILE)

fclean : clean
	@rm -rf $(NAME)

re:		fclean all
