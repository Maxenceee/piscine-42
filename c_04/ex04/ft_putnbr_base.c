/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:04:24 by mgama             #+#    #+#             */
/*   Updated: 2022/11/08 19:40:08 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_plus_minus(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] != '+' && base[i] != '-')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_same_characters(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_putnbr(int nbr, unsigned int len_base, char *base)
{
	unsigned int	a;

	if (nbr < 0)
	{
		a = -nbr;
		write(1, "-", 1);
	}
	else
		a = nbr;
	if (a >= len_base)
	{
		ft_putnbr((a / len_base), len_base, base);
		ft_putnbr((a % len_base), len_base, base);
	}
	else
		write(1, &base[a], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	len_base;

	len_base = ft_strlen(base);
	if (len_base < 2)
		return ;
	if (ft_str_plus_minus(base) == 0)
		return ;
	if (ft_same_characters(base) == 0)
		return ;
	ft_putnbr(nbr, len_base, base);
}
