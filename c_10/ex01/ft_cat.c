/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:30:14 by mgama             #+#    #+#             */
/*   Updated: 2022/11/08 19:44:50 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <string.h>
#include <errno.h>

void	print_error(char *error)
{
	write(2, "Error: ", 7);
	while (*error)
	{
		write(2, error++, 1);
	}
	write(2, "\n", 1);
}

void	ft_print(char *msg)
{
	while (*msg)
	{
		write(1, msg++, 1);
	}
}

char	**ft_map(char **tab, int length, char *(*f)(char *))
{
	int		i;
	char	**res;
	char	**d;
	char	*temp;

	res = malloc(length + 1 * sizeof(char *));
	d = (res);
	if (!d)
		return (0);
	i = 0;
	while (i < length)
	{
		temp = (*f)(tab[i]);
		if (!temp)
		{
			print_error(strerror(errno));
			i++;
			continue ;
		}
		res[i] = (char *)(malloc(ft_strlen(temp) * sizeof(char)));
		ft_print(temp);
		res[i] = temp;
		i++;
	}
	res[i] = "\0";
	return (res);
}

int	main(int ac, char **av)
{
	char	**res;

	if (ac > 1)
	{
		
		res = ft_map(av + 1, ac - 1, read_file);
		if (ac > 2)
		{
			write_in_file(res, av[3]);
		}
	}
	else
		print_error("At least one argument is required");
	return (0);
}