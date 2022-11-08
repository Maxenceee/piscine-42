# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgama <mgama@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 15:24:10 by mgama             #+#    #+#              #
#    Updated: 2022/11/08 19:43:36 by mgama            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

rm -f libft.a

gcc -c ft_putchar.c
gcc -c ft_strcmp.c
gcc -c ft_swap.c
gcc -c ft_putstr.c
gcc -c ft_strlen.c

ar rc libft.a ft_putchar.o ft_strcmp.o ft_swap.o ft_putstr.o ft_strlen.o