/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:17:59 by mgama             #+#    #+#             */
/*   Updated: 2022/09/01 14:55:44 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_result(int a)
{
	int	b;

	if (a < 10)
	{
		a += 48;
		write(1, "0", 1);
		write(1, &a, 1);
	}
	else
	{
		b = a % 10 + 48;
		a = a / 10 + 48;
		write(1, &a, 1);
		write(1, &b, 1);
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (a < 99)
	{
		while (b <= 99)
		{
			print_result(a);
			write(1, " ", 1);
			print_result(b);
			if (a < 98 && b <= 99)
			{
				write(1, ", ", 2);
			}			
			b++;
		}
		a++;
		b = a + 1;
	}	
}
