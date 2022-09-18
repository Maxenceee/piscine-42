/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:11:24 by mgama             #+#    #+#             */
/*   Updated: 2022/09/17 14:11:27 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "parsing.h"

int	ft_strlen(char	*str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

int	contains(char *str, char f)
{
	while (*str)
	{
		if (*str == f)
			return (1);
		str++;
	}
	return (0);
}

int	count_key_word(char	*content)
{
	int	kcount;

	kcount = 0;
	while (*content)
	{
		if (*content == ':')
			kcount++;
		content++;
	}
	return (kcount);
}

unsigned int	get_num_len(int num)
{
	int	div;
	int	c;

	c = 1;
	div = 1;
	while (num / div >= 10)
	{
		div *= 10;
		c++;
	}
	return (c);
}

unsigned int	ft_atoi(char *str)
{
	int				i;
	unsigned int	nbr;

	i = 0;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + (str[i++] - '0');
	return (nbr);
}
