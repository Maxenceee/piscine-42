/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:11:24 by mgama             #+#    #+#             */
/*   Updated: 2023/10/02 13:35:19 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "parsing.h"
#include "functions.h"

t_board	parse_board(char *board_name)
{
	t_board_parsed	board;
	t_board			parsed_board;

	board = read_file(board_name);
	if (board.size == 0)
	{
		parsed_board.nb_rows = 0;
		parsed_board.nb_cols = 0;
		return (parsed_board);
	}
	parsed_board = parse_to_tab(board);
	return (parsed_board);
}

t_board	parse_map(char *map)
{
	t_board_parsed	board;
	t_board			parsed_board;

	board.content = map;
	board.size = ft_strlen(map);
	parsed_board = parse_to_tab(board);
	return (parsed_board);
}

t_board_parsed	read_file(char *board_name)
{
	int				fd;
	t_board_parsed	board;

	board.content = NULL;
	board.size = 0;
	fd = open(board_name, O_RDONLY);
	if (fd < 0)
		return (board);
	board.content = ft_read_file(fd, board.content);
	if (!board.content)
		return (board);
	close(fd);
	board.size = ft_strlen(board.content);
	return (board);
}

int	string_to_object(char **lines_split, t_board *parsed_board, t_cell	**fnl)
{
	int		i;
	int		j;
	t_cell	temp_cell;

	i = -1;
	while (lines_split[++i])
	{
		j = 0;
		fnl[i] = malloc(sizeof(t_cell) * parsed_board->nb_cols);
		if (!fnl[i])
			return (0);
		while (lines_split[i][j])
		{
			temp_cell.value = 1;
			if (lines_split[i][j] == parsed_board->empty)
				temp_cell.type = empty;
			else if (lines_split[i][j] == parsed_board->obscacle)
				temp_cell.type = obscacle;
			else
				return (0);
			fnl[i][j++] = temp_cell;
		}
	}
	parsed_board->content = fnl;
	return (1);
}

t_board	parse_to_tab(t_board_parsed board)
{
	t_cell					**fnl;
	t_display_characters	line_sett;
	char					**lines_split;
	t_board					parsed_board;

	parsed_board.nb_rows = 0;
	lines_split = ft_split(board.content, "\n");
	if (!lines_split)
		return (parsed_board);
	line_sett = parse_diplay_characters(lines_split[0]);
	if (!line_sett.nb_lines)
		return (parsed_board);
	parse_rows_cols(&parsed_board, line_sett, lines_split);
	if (parsed_board.nb_cols == 0 || parsed_board.nb_rows == 0)
		return (parsed_board);
	fnl = malloc(sizeof(t_cell *) * parsed_board.nb_rows);
	if (!fnl)
		return (parsed_board);
	if (string_to_object(lines_split + 1, &parsed_board, fnl) == 0)
		parsed_board.nb_rows = 0;
	return (parsed_board);
}
