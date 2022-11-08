# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgama <mgama@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 19:33:16 by mgama             #+#    #+#              #
#    Updated: 2022/11/08 19:33:33 by mgama            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFILES		= srcs/main.c srcs/parsing.c srcs/parsing_utils.c srcs/ft_split.c srcs/ft_sort.c srcs/create_elem.c srcs/converter.c srcs/converter_utils.c
HEADERS_DIR	= includes/
CFLAGS		= -Wall -Wextra -Werror -I $(HEADERS_DIR)
NAME		= rush-02
OBJS		= ${CFILES:.c=.o}

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf srcs/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re