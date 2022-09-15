/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 21:50:57 by mgama             #+#    #+#             */
/*   Updated: 2022/09/11 21:50:58 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

int	is_in(char *sr, char pr, int gap)
{
	int	i;

	i = gap;
	while (sr[i] != '\0')
	{
		if (pr == sr[i])
			return (1);
		i++;
	}
	return (0);
}

int	convert_base_in_int(char *src, char *base, int base_len)
{
	int	count;
	int	res;
	int	tmp;
	int	i;

	count = 0;
	i = 0;
	while (src[count] != '\0' && is_in(base, src[count], 0))
		if (src[count])
			count++;
	res = 0;
	if (count == 0)
		return (0);
	while (i < count)
	{
		tmp = 0;
		while (base[tmp] != src[i])
			tmp++;
		res += tmp * ft_pow(base_len, count - i - 1);
		i++;
	}
	return (res);
}

int	is_correct_base(char *base)
{
	int	i;

	i = 0;
	if (base == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+' \
		|| (base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (0);
		if (is_in(base, base[i], i + 1))
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	nbr;
	int	sign;
	int	count;

	if (!is_correct_base(base))
		return (0);
	i = 0;
	nbr = 0;
	sign = 0;
	count = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign++;
	while (base[count] != '\0')
		if (base[count])
			count++;
	nbr = convert_base_in_int(str + i, base, count);
	if (sign % 2 == 1)
		return (nbr * -1);
	return (nbr);
}
