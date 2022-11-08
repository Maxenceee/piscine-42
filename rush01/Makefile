# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgama <mgama@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 19:33:38 by mgama             #+#    #+#              #
#    Updated: 2022/11/08 19:34:57 by mgama            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFILES		= sources/generic.c sources/main.c sources/parsing.c sources/solving.c
HEADERS_DIR	= includes/
CFLAGS		= -Wall -Wextra -Werror -I $(HEADERS_DIR)
NAME		= rush-01
OBJS		= ${CFILES:.c=.o}

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf sources/generic.o sources/main.o sources/parsing.o sources/solving.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re