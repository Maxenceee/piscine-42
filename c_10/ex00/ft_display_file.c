/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:39:08 by mgama             #+#    #+#             */
/*   Updated: 2022/09/14 23:39:09 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "ft_display_file.h"

void	ft_print(char *msg)
{
	while (*msg)
	{
		write(1, msg++, 1);
	}
}

void	read_file(char *file_name)
{
	int				of;
	int				c;
	char			ch[30000];

	of = open(file_name, O_RDONLY);
	if (of < 0)
	{
		ft_print(CANNOT_READ);
		return ;
	}
	c = read(of, ch, 30000);
	if (close(of) < 0)
	{
		return ;
	}
	ft_print(ch);
}

int	main(int ac, char *av[])
{
	if (ac < 2)
	{
		ft_print(FILE_MISSING);
		return (1);
	}
	else if (ac > 2)
	{
		ft_print(TOO_MANY_ARGUMENT);
		return (1);
	}
	read_file(av[1]);
	return (0);
}
