/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:34:20 by mgama             #+#    #+#             */
/*   Updated: 2022/11/08 19:31:23 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "parsing.h"
#include "converter.h"
#include "functions.h"

int	ft_power(int nb, int power)
{
	int	d;

	d = 1;
	if (power == 0)
	{
		return (1);
	}
	if (power < 0)
	{
		return (0);
	}
	d *= nb;
	power--;
	return (d * ft_power(nb, power));
}

char	*get_name_from_value(unsigned int value, t_parsed_dict dict)
{
	int	i;

	i = 0;
	while (i < dict.size)
	{
		if (dict.content[i].value == value)
			return (dict.content[i].name);
		i++;
	}
	return (0);
}

void	show(t_element *c)
{
	if (c == NULL)
		return ;
	show(c->next);
	if (c->name != NULL)
	{
		ft_print(c->name);
		if (c->name != NULL)
			ft_print(" ");
	}
}

int	is_decimal_divider(int num)
{
	unsigned int	div;

	div = 1;
	while (num / div >= 10)
	{
		div *= 10;
	}
	if (num / div == 1)
		return (1);
	return (0);
}
