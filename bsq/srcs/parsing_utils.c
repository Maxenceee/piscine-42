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
#include "functions.h"

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

int	ft_tablen(char	**str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

t_display_characters	parse_diplay_characters(char *line)
{
	int	i;
	int	u;
	t_display_characters	res;

	i = 0;
	u = ft_strlen(line);
	if (!is_correct_params(line))
	{
		res.nb_lines = 0;
		return (res);
	}
	while (u - i - 1 >= 0)
	{
		if (u - i == u - 3)
			res.empty = line[u - i];
		else if (u - i == u - 2)
			res.obscacle = line[u - i];
		else if (u - i == u - 1)
			res.complete = line[u - i];
		i++;
	}
	res.nb_lines = ft_atoin(line, u - 3);
	if (res.nb_lines <= 0)
		return (res);
	return (res);
}

int	check_lines_len(char **lines_split)
{
	int	first_len;
	int	i;

	i = 1;
	first_len = ft_strlen(lines_split[1]);
	while (lines_split[i])
	{
		if (ft_strlen(lines_split[i]) != first_len)
			return (0);
		i++;
	}
	return (first_len);
}
