#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/16 11:33:12 by tde-roqu          #+#    #+#              #
#    Updated: 2016/02/25 16:35:48 by tde-roqu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

SRC = main.c ft_errorlem.c get_next_line.c ft_arg.c ft_isalnum.c ft_isalpha.c\
ft_isdigit.c ft_detector.c ft_strndup.c ft_lstft.c ft_strcmp.c ft_roomconf.c\
ft_reso.c ft_passing.c ft_pathfounder.c ft_cleaner.c ft_optinorme.c

OBJ = $(SRC:.c=.o)

HEAD = ft_printf/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C ft_printf/ fclean && make -C ft_printf/
	gcc $(FLAGS) -I $(HEAD) -c $(SRC)
	gcc -o $(NAME) $(OBJ) -I $(HEAD) -L ft_printf/ -lftprintf

clean:
	make -C ft_printf/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C ft_printf/ fclean
	rm -f $(NAME)

re: fclean all