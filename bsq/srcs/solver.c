/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ileconte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:17:58 by ileconte          #+#    #+#             */
/*   Updated: 2022/09/20 06:43:21 by ileconte         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "parsing.h"
#include "functions.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max_cell(t_board *board)
{
	int	x;
	int	y;
	int	max;

	x = 0;
	max = -1;
	while (x < board->nb_rows)
	{
		y = 0;
		while (y < board->nb_cols)
		{
			if (board->content[x][y].type == empty)
			{
				if (board->content[x][y].value > max)
					max = board->content[x][y].value;
			}
			y++;
		}
		x++;
	}
	return (max);
}

void	fill_map(t_board *board, int dr, int x, int y)
{
	int	i;

	i = 0;
	while (dr - i > 0)
	{
		board->content[x][y - i].type = full;
		i++;
	}
}

void	ft_final_board(t_board *board, int dr)
{
	int	x;
	int	y;
	int	u;

	x = 1;
	u = dr;
	while (x < board->nb_rows)
	{
		y = 1;
		while (y < board->nb_cols)
		{
			if (board->content[x][y].value == dr)
			{
				while (dr > 0)
				{
					fill_map(board, u, x - dr + 1, y);
					dr--;
				}
				return ;
			}
			y++;
		}
		x++;
	}
}

void	ft_solver_board(t_board *board)
{
	int	x;
	int	y;

	x = 1;
	while (x < board->nb_rows)
	{
		y = 1;
		while (y < board->nb_cols)
		{
			if (board->content[x][y].type == empty)
			{
				if (board->content[x - 1][y].type != empty ||
						board->content[x][y - 1].type != empty ||
						board->content[x - 1][y - 1].type != empty)
					board->content[x][y].value = 1;
				else
					board->content[x][y].value = min(min(
								board->content[x - 1][y].value,
								board->content[x][y - 1].value),
							board->content[x - 1][y - 1].value) + 1;
			}
			y++;
		}
		x++;
	}
}
