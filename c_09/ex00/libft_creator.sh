# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgama <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 15:24:10 by mgama             #+#    #+#              #
#    Updated: 2022/09/14 15:24:12 by mgama            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

gcc -c ft_putchar.c
gcc -c ft_strcmp.c
gcc -c ft_swap.c
gcc -c ft_putstr.c
gcc -c ft_strlen.c

ar rc libft.a ft_putchar.o ft_strcmp.o ft_swap.o ft_putstr.o ft_strlen.o