/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:09:43 by mgama             #+#    #+#             */
/*   Updated: 2022/09/19 14:09:45 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

typedef enum cell_type
{
	empty = 0,
	full = 1,
	obscacle = 2,
}	t_cell_type;

typedef struct s_cell
{
	int			value;
	t_cell_type	type;
}	t_cell;

typedef struct s_board_parsed
{
	int		size;
	char	*content;
}	t_board_parsed;

typedef struct s_board
{
	int		nb_rows;
	int		nb_cols;
	char	empty;
	char	obscacle;
	char	complete;
	t_cell	**content;
}	t_board;

typedef struct s_display_characters
{
	int		nb_lines;
	char	empty;
	char	obscacle;
	char	complete;
}	t_display_characters;
