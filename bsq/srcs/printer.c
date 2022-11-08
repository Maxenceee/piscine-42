/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:01:10 by mgama             #+#    #+#             */
/*   Updated: 2022/11/08 19:32:57 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "parsing.h"
#include "functions.h"

void	print_error(char *error)
{
	while (*error)
	{
		write(2, error++, 1);
	}
}

void	ft_print(char *msg)
{
	while (*msg)
	{
		write(1, msg++, 1);
	}
}

void	ft_print_char(char msg)
{
	write(1, &msg, 1);
}

void	board_printer(t_board board)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < board.nb_rows)
	{
		j = 0;
		while (j < board.nb_cols)
		{
			if (board.content[i][j].type == empty)
				ft_print_char(board.empty);
			else if (board.content[i][j].type == full)
				ft_print_char(board.complete);
			else if (board.content[i][j].type == obscacle)
				ft_print_char(board.obscacle);
			j++;
		}
		ft_print("\n");
		i++;
	}
	ft_print("\n");
}
