/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:33:50 by mgama             #+#    #+#             */
/*   Updated: 2022/09/19 14:33:51 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "parsing.h"
#include "functions.h"

int	main(void)
{
	char	*board_name;
	t_board	board;

	board_name = "board_test.txt";
	board = parse_board(board_name);
	if (board.nb_rows == 0 || board.nb_cols == 0)
		print_error("map error\n");
	else
	{
		ft_solver_board(&board);
		ft_final_board(&board, ft_max_cell(&board));
		board_printer(board);
	}

	return (0);
}