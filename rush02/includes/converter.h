/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:09:54 by mgama             #+#    #+#             */
/*   Updated: 2022/11/08 19:30:56 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

void	add_name(t_list *dest, unsigned int n, t_parsed_dict dict);
int		separate_word(t_list *mylist, t_parsed_dict dict, \
		unsigned int div, unsigned int temp);
int		dispatch_sub(t_list *mylist, t_parsed_dict dict, \
		unsigned int num, unsigned int temp);
void	dispacth_num(t_list *mylist, t_parsed_dict dict, \
		unsigned int num);
void	convert_num_to_letters(unsigned int num, t_parsed_dict dict);

int		ft_power(int nb, int power);
char	*get_name_from_value(unsigned int value, t_parsed_dict dict);
void	show(t_element *c);
int		is_decimal_divider(int num);

#endif