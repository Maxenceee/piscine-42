/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:11:24 by mgama             #+#    #+#             */
/*   Updated: 2022/11/08 19:32:46 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "parsing.h"
#include "functions.h"

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

int	is_correct_params(char *line)
{
	int	i;
	int	u;

	i = 0;
	u = ft_strlen(line);
	if (u < 4)
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] < 32 || line[i] > 126)
			return (0);
		if (is_in(line, line[i], i + 1))
			return (0);
		i++;
	}
	return (1);
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

unsigned int	ft_atoin(char *str, unsigned int n)
{
	unsigned int	i;
	unsigned int	nbr;

	i = 0;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9' && i < n)
		nbr = nbr * 10 + (str[i++] - '0');
	return (nbr);
}
