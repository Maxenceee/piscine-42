/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:21:55 by mgama             #+#    #+#             */
/*   Updated: 2022/09/11 18:21:59 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "solving.h"
#include "parsing.h"
#include "generic.h"
#include <stdlib.h>

int	check_adjacent_cell(int grid[4][4], int gap, int size)
{
	int	i;

	i = 0;
	while (i < gap / 4)
	{
		if (grid[i][gap % 4] == size)
			return (1);
		i++;
	}
	i = 0;
	while (i < gap % 4)
	{
		if (grid[gap / 4][i] == size)
			return (1);
		i++;
	}
	return (0);
}

int	puzzle_solver(int grid[4][4], int pattern[16], int gap)
{
	int	size;

	if (gap == 16)
		return (1);
	size = 0;
	while (++size <= 4)
	{
		if (check_adjacent_cell(grid, gap, size) == 0)
		{
			grid[gap / 4][gap % 4] = size;
			if (check_pattern(grid, gap, pattern) == 0)
			{
				if (puzzle_solver(grid, pattern, gap + 1) == 1)
					return (1);
			}
			else
			{
				grid[gap / 4][gap % 4] = 0;
			}
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	grid[4][4];
	int	*pattern;

	if (check_arguments(argc, argv) == 1)
	{
		return (1);
	}
	pattern = convert_pattern(argv[1]);
	if (!pattern)
		return (1);
	if (puzzle_solver(grid, pattern, 0) == 1)
	{
		print_puzzle_grid(grid);
	}
	else
	{
		ft_putstr("Error\n");
	}
	return (0);
}
