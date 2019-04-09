# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrameau <jrameau@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/21 14:58:27 by jrameau           #+#    #+#              #
#    Updated: 2019/04/08 11:50:01 by bchapman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CFLAGS= -I $(INCLUDES) -Wall -Wextra -Werror
INCLUDES = includes/

FILES		= ft_strdup.c \
				ft_strlen.c \
				ft_memalloc.c \
				ft_strchr.c \
				ft_memdel.c \
				ft_strnew.c \
				ft_strdel.c \
				ft_strsub.c \
				ft_strjoin.c \
				ft_strsplit.c \
				ft_wc.c \
				get_next_line.c

OBJ=$(FILES:.c=.o)

$(NAME):
	gcc $(CFLAGS) -c $(FILES)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
