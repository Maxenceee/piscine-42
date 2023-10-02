/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:33:50 by mgama             #+#    #+#             */
/*   Updated: 2023/10/02 14:02:04 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "parsing.h"
#include "functions.h"

void	ft_board(char *board_name, int l)
{
	t_board	board;

	if (!l)
		board = parse_board(board_name);
	else
	{
		if (ft_strlen(board_name) != 0)
			board = parse_map(board_name);
	}
	if (board.nb_rows == 0 || board.nb_cols == 0)
		print_error("map error\n");
	else
	{
		ft_solver_board(&board);
		ft_final_board(&board, ft_max_cell(&board));
		board_printer(board);
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	char	*buffer;

	i = 0;
	buffer = NULL;
	if (argc == 1)
	{
		buffer = ft_read_file(0, buffer);
		if (ft_strlen(buffer) > 0)
			ft_board(buffer, 1);
		else
			print_error("map error\n");
	}
	else
	{
		while (++i < argc)
			ft_board(argv[i], 0);
	}
	return (0);
}
