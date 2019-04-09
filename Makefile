# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maparmar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/28 01:27:24 by maparmar          #+#    #+#              #
#    Updated: 2019/04/08 23:04:16 by bchapman         ###   ########.fr        #
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
