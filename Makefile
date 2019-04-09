# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchapman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/09 00:20:30 by bchapman          #+#    #+#              #
#    Updated: 2019/04/09 00:20:35 by bchapman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = puzzle

SRC = 	puzzle.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(OBJ):
		@gcc -c -Wall -Werror $(SRC)

$(NAME): LIB $(OBJ)
	@gcc $(OBJ) ./includes/libft.a -o $(NAME)

LIB:
	@$(MAKE) -C ./includes/

clean:
	/bin/rm -f $(OBJ)
	@$(MAKE) -C ./includes/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@$(MAKE) -C ./includes/ fclean

re: fclean all
