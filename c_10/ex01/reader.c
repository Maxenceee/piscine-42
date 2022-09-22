/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:36:59 by mgama             #+#    #+#             */
/*   Updated: 2022/09/21 11:37:01 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

char	*read_file(char *board_name)
{
	int		of;
	int		c;
	char	ch[30000];
	char	*res;
	int		i;
	
	of = open(board_name, O_RDONLY);
	if (of < 0)
	{
		return (0);
	}
	c = read(of, ch, 30000);
	if (close(of) < 0)
	{
		return (0);
	}
	res = malloc(sizeof(char) * ft_strlen(ch));
	if (!res)
		return (0);
	i = -1;
	while (ch[++i] != '\0')
	{
		res[i] = ch[i];
	}
	res[i] = '\0';
	return (res);
}

int	write_in_file(char **content, char *file_name)
{
	int		of;
	int		len;
	int		i;

	of = open(file_name, O_RDONLY);
	if (of < 0)
	{
		of = open(file_name, O_CREAT);
		if (of < 0)
		{
			return (0);
		}
	}
	i = 0;
	while (content[i])
	{
		len = ft_strlen(*content[i]);
		write(of, *content[i], len);
	}
	return (1);
}