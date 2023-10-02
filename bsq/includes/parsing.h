/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:38:57 by mgama             #+#    #+#             */
/*   Updated: 2023/10/02 13:34:44 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdlib.h>

t_board					parse_board(char *board_name);
t_board					parse_map(char *map);
t_board_parsed			read_file(char *board_name);
int						string_to_object(char **lines_split, \
t_board *parsed_board, t_cell **fnl);
t_board					parse_to_tab(t_board_parsed board);

int						ft_tablen(char **str);
t_display_characters	parse_diplay_characters(char *line);
void					parse_rows_cols(t_board *parsed_board, \
t_display_characters line_sett, char **lines_split);
int						check_lines_len(char **lines_split);

int						is_in(char *sr, char pr, int gap);
int						is_correct_params(char *line);
unsigned int			get_num_len(int num);
unsigned int			ft_atoi(char *str);
unsigned int			ft_atoin(char *str, unsigned int n);

int						ft_strlen(const char *str);
char					*ft_read_file(int fd, char *file);

#endif
