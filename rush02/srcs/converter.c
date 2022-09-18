/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:08:22 by mgama             #+#    #+#             */
/*   Updated: 2022/09/18 14:08:24 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "parsing.h"
#include "converter.h"
#include "functions.h"

void	add_name(t_list *dest, unsigned int n, t_parsed_dict dict)
{
	insert_elem(dest, get_name_from_value(n, dict));
}

int	separate_word(t_list *mylist, t_parsed_dict dict, \
unsigned int div, unsigned int temp)
{
	if (div == 10)
		add_name(mylist, temp, dict);
	else if ((get_num_len(div / 100) - 1) % 3 == 0)
	{
		add_name(mylist, temp / div, dict);
		add_name(mylist, 100, dict);
		div /= 100;
	}
	else if ((get_num_len(div / 10) - 1) % 3 == 0)
	{
		add_name(mylist, temp / div * 10, dict);
		div /= 10;
		if ((get_num_len(div) - 1) % 3 == 0)
			add_name(mylist, div, dict);
	}
	return (div);
}

int	dispatch_sub(t_list *mylist, t_parsed_dict dict, \
unsigned int num, unsigned int temp)
{
	unsigned int	div;
	unsigned int	sub;

	div = 1;
	while (num / div >= 10)
	{
		div *= 10;
	}
	temp = (num / div) * div;
	sub = temp;
	if ((get_num_len(div) - 1) % 3 != 0)
	{
		div = separate_word(mylist, dict, div, temp);
	}
	else if ((get_num_len(div) - 1) % 3 == 0)
	{
		add_name(mylist, num / div, dict);
		temp = div;
		add_name(mylist, temp, dict);
	}
	if (num - sub == 0 && div > 10 && temp / div > 1 && is_decimal_divider(sub))
		add_name(mylist, div, dict);
	return (num - sub);
}

void	dispacth_num(t_list *mylist, t_parsed_dict dict, unsigned int num)
{
	unsigned int	temp;

	temp = 0;
	while (num > 0)
	{
		if (num < 10)
		{
			add_name(mylist, num, dict);
			num = 0;
		}
		else
			num = dispatch_sub(mylist, dict, num, temp);
	}
}

void	convert_num_to_letters(unsigned int num, t_parsed_dict dict)
{
	unsigned int	len_of_num;
	t_list			*mylist;

	mylist = init();
	if (!mylist)
		return ;
	len_of_num = get_num_len(num);
	if (len_of_num == 1 && num == 0)
		add_name(mylist, num, dict);
	else
		dispacth_num(mylist, dict, num);
	print_elem(mylist);
	free_elem(mylist);
}
