/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:38:57 by mgama             #+#    #+#             */
/*   Updated: 2022/09/17 14:38:59 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/* parsing.c */

t_parsed_dict	parse_dict(char *dict_name);
t_dict			read_file(char *dict_name);
t_parsed_dict	parse_to_tab(t_dict dict);

/* parsing_utils.c */

int				ft_strlen(char	*str);
int				count_key_word(char	*content);
unsigned int	ft_atoi(char *str);
void			ft_putnbr(unsigned int nb);
void			ft_putchar(char c);

#endif
