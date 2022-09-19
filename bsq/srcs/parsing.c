/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:11:24 by mgama             #+#    #+#             */
/*   Updated: 2022/09/17 14:11:27 by mgama            ###   ########lyon.fr   */
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

t_board_parsed	read_file(char *dict_name)
{
	int				of;
	int				c;
	char			ch[30000];
	t_board_parsed	board;

	of = open(dict_name, O_RDONLY);
	if (of < 0)
	{
		print_error("map error\n");
		board.size = 0;
		return (board);
	}
	c = read(of, ch, 30000);
	if (close(of) < 0)
	{
		print_error("map error\n");
		board.size = 0;
		return (board);
	}
	board.content = ch;
	board.size = ft_strlen(ch);
	return (board);
}

int	string_to_object(char **lines_split, t_board *parsed_board, t_cell	**fnl)
{
	int		i;
	int		j;
	t_cell	temp_cell;

	i = 0;
	while (lines_split[i])
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
			fnl[i][j] = temp_cell;
			j++;
		}
		i++;
	}
	parsed_board->content = fnl;
	return (1);
}

t_board	parse_to_tab(t_board_parsed board)
{
	t_cell					**fnl;
	t_display_characters	line_sett;
	int						line_len;
	char					**lines_split;
	t_board					parsed_board;

	lines_split = ft_split(board.content, "\n");
	line_sett = parse_diplay_characters(lines_split[0]);
	if (!line_sett.nb_lines)
	{
		parsed_board.nb_rows = 0;
		return (parsed_board);
	}
	parsed_board.empty = line_sett.empty;
	parsed_board.obscacle = line_sett.obscacle;
	parsed_board.complete = line_sett.complete;
	parsed_board.nb_rows = line_sett.nb_lines;
	if (line_sett.nb_lines != ft_tablen(lines_split + 1))
	{
		parsed_board.nb_rows = 0;
		return (parsed_board);
	}
	line_len = check_lines_len(lines_split);
	parsed_board.nb_cols = line_len;

	if (parsed_board.nb_cols == 0 || parsed_board.nb_rows == 0)
		return (parsed_board);

	fnl = malloc(sizeof(t_cell *) * parsed_board.nb_rows);
	if (!fnl)
	{
		parsed_board.nb_rows = 0;
		return (parsed_board);
	}
	if (string_to_object(lines_split + 1, &parsed_board, fnl) == 0)
	{
		parsed_board.nb_rows = 0;
		return (parsed_board);
	}
	return (parsed_board);
}
