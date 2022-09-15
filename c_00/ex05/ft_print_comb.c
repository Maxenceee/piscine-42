/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:12:53 by mgama             #+#    #+#             */
/*   Updated: 2022/09/03 00:12:25 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	end_separator(int a, int b, int c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (a < 55)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int		a;
	int		b;
	int		c;

	a = 48;
	b = 49;
	c = 50;
	while (a <= 55)
	{
		while (b <= 56)
		{
			while (c <= 57)
			{
				end_separator(a, b, c);
				c++;
			}
			b++;
			c = b + 1;
		}
		a++;
		b = a + 1;
		c = b + 1;
	}	
}
