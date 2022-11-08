# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgama <mgama@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 19:45:08 by mgama             #+#    #+#              #
#    Updated: 2022/11/08 19:45:09 by mgama            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFILES		=	$(shell find . -name "*.c")
HEADERS_DIR	=	/
CFLAGS		=	-Wall -Wextra -Werror -I $(HEADERS_DIR)
NAME		=	ft_cat
OBJS		=	${CFILES:.c=.o}

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)
