/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:54:02 by mgama             #+#    #+#             */
/*   Updated: 2022/09/08 14:54:06 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	c;
	int	d;

	if (power == 0)
	{
		return (1);
	}
	if (power < 0)
	{
		return (0);
	}
	c = 1;
	d = nb;
	while (c < power)
	{
		d *= nb;
		c++;
	}
	return (d);
}
