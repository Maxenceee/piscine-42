/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:21:55 by mgama             #+#    #+#             */
/*   Updated: 2022/09/11 18:21:59 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "generic.h"
#include <stdlib.h>

int	check_arguments(int argc, char *argv[])
{
	if (argc != 2)
	{
		return (1);
	}
	if (ft_strlen(argv[1]) != 31)
	{
		return (1);
	}
	return (0);
}

int	*convert_pattern(char *str)
{
	int	*tab;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tab = malloc(sizeof(int) * 16);
	if (!tab)
	{
		return (0);
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			tab[j++] = ft_atoi(str + i);
		i++;
	}
	return (tab);
}

void	print_puzzle_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putnbr(grid[i][j]);
			if (j < 3)
			{
				ft_putchar(' ');
			}
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
