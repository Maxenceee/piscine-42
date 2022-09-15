/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 21:50:47 by mgama             #+#    #+#             */
/*   Updated: 2022/09/11 21:50:49 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int				ft_pow(int a, int b);
int				is_in(char *sr, char pr, int gap);
int				convert_base_in_int(char *src, char *base, int base_len);
int				is_correct_base(char *base);
int				ft_atoi_base(char *str, char *base);
void			ft_rev_int_tab(char *tab, int size);
unsigned int	ft_strlen(char *str);
void			ft_putnbr_base(int nbr, char *base, char *v);
char			*ft_convert_base(char *nbr, char *base_from, char *base_to);

void	ft_rev_int_tab(char *tab, int size)
{
	int	count;
	int	d;
	int	e;

	count = 0;
	while (count < size / 2)
	{
		d = tab[count];
		e = tab[size - count - 1];
		tab[size - count - 1] = d;
		tab[count] = e;
		count++;
	}
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

void	ft_putnbr_base(int nbr, char *base, char *v)
{
	unsigned int	len_base;
	unsigned int	a;
	unsigned int	i;

	i = 0;
	len_base = ft_strlen(base);
	if (nbr < 0)
	{
		a = -nbr;
	}
	else
		a = nbr;
	while (a != 0)
	{
		v[i] = base[a % len_base];
		a /= len_base;
		i++;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int					i;
	unsigned int		len;
	char				*v;

	if (!is_correct_base(base_from) || !is_correct_base(base_to))
		return (0);
	v = malloc(sizeof(char));
	if (!v)
		return (0);
	i = ft_atoi_base(nbr, base_from);
	ft_putnbr_base(i, base_to, v);
	len = ft_strlen(v);
	if (i < 0)
	{
		v[len] = '-';
		len = ft_strlen(v);
	}
	v[len] = '\0';
	ft_rev_int_tab(v, ft_strlen(v));
	return (v);
}
