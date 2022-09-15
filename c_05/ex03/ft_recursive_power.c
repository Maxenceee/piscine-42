/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:56:46 by mgama             #+#    #+#             */
/*   Updated: 2022/09/08 14:56:47 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
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
	return (d * ft_recursive_power(nb, power));
}
