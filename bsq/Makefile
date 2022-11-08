# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgama <mgama@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 19:33:10 by mgama             #+#    #+#              #
#    Updated: 2022/11/08 19:33:11 by mgama            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFILES		=	srcs/ft_split.c srcs/parsing_utils.c srcs/solver.c srcs/main.c srcs/parsing_utils2.c srcs/parsing.c srcs/printer.c
HEADERS_DIR	=	includes/
CFLAGS		=	-Wall -Wextra -Werror -I $(HEADERS_DIR)
NAME		=	bsq
OBJS		=	${CFILES:.c=.o}

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)
