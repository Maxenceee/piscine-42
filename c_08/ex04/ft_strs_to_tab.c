/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:27:33 by mgama             #+#    #+#             */
/*   Updated: 2022/09/14 13:27:35 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

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

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;

	str = malloc(ft_strlen(src) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	tmp;
	t_stock_str	*fnl;

	fnl = malloc((ac + 1) * sizeof(t_stock_str));
	if (!fnl)
	{
		free(fnl);
		return (0);
	}
	while (ac-- > 0)
	{
		tmp.size = ft_strlen(av[ac]);
		tmp.str = av[ac];
		tmp.copy = ft_strdup(av[ac]);
		if (!tmp.copy)
			return (0);
		fnl[ac] = tmp;
	}
	tmp.size = 0;
	tmp.str = 0;
	tmp.copy = 0;
	fnl[ac + 1] = tmp;
	return (0);
}
