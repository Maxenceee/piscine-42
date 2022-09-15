/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:33:28 by mgama             #+#    #+#             */
/*   Updated: 2022/09/08 16:33:30 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	n;
	int	d;

	n = nb;
	d = 2;
	if (n < 0)
		return (0);
	if (n == 0 || n == 1)
		return (0);
	if (n == 2)
		return (1);
	while (d < n && d < 46341)
	{
		if (nb % d == 0)
			return (0);
		d++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		return (2);
	while (!ft_is_prime(nb + i))
	{
		i++;
	}
	return (nb + i);
}
