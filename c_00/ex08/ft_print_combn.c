/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:29:23 by mgama             #+#    #+#             */
/*   Updated: 2022/09/03 00:07:56 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_pow(int a, int b)
{
	int	c;
	int	d;

	if (b == 0)
	{
		return (1);
	}
	c = 1;
	d = a;
	while (c < b)
	{
		d *= a;
		c++;
	}
	return (d);
}

void	ft_putnbr(int nb)
{
	int	mod;

	if (nb > 9)
	{
		mod = nb % 10 + 48;
		nb = nb / 10;
		ft_putnbr(nb);
		write(1, &mod, 1);
	}
	else
	{
		nb = nb + 48;
		write(1, &nb, 1);
	}
}

int	get_first_num(int n)
{
	int	loop;
	int	nb;
	int	p;

	nb = 0;
	loop = 1;
	while (loop < n)
	{
		p = ft_pow(10, n - loop - 1);
		nb += loop * p;
		loop++;
	}
	return (nb);
}

int	get_last_num(int n)
{
	int	loop;
	int	nb;
	int	p;

	nb = ft_pow(10, n);
	loop = 0;
	while (loop < n)
	{
		p = ft_pow(10, loop);
		if (loop < 2)
		{
			nb -= 1 * p;
		}
		else
		{
			nb -= loop * p;
		}
		loop++;
	}
	return (nb);
}

void	ft_print_combn(int n)
{
	int	nb;
	int	lnb;

	nb = 0;
	if (n < 10 && n > 0)
	{
		nb = get_first_num(n);
		lnb = get_last_num(n);
		while (nb <= lnb)
		{
			if (nb < ft_pow(10, n - 1))
			{
				write(1, "0", 1);
			}
			ft_putnbr(nb);
			if (nb < lnb)
			{
				write(1, ", ", 2);
			}
			nb++;
		}
	}
}

int	main(void)
{
	ft_print_combn(2);
	return (0);
}
