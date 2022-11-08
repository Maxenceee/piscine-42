/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:38:57 by mgama             #+#    #+#             */
/*   Updated: 2022/11/08 19:31:11 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

t_parsed_dict	parse_dict(char *dict_name);
t_dict			read_file(char *dict_name);
void			string_to_object(t_dict dict, t_parsed_dict *parsed_dict, \
t_numbers_name	*fnl);
t_parsed_dict	parse_to_tab(t_dict dict);

int				ft_strlen(char	*str);
int				contains(char *str, char f);
int				count_key_word(char	*content);
unsigned int	get_num_len(int num);
unsigned int	ft_atoi(char *str);

#endif
