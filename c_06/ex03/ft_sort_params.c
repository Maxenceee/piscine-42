/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 23:32:17 by mgama             #+#    #+#             */
/*   Updated: 2022/11/08 19:41:23 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	swap(char **xp, char **yp)
{
	char	*temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void	ft_putstr(char	*str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort_int_tab(char **tab, int ac)
{
	int	a;
	int	s;

	a = 1;
	while (ac > a)
	{
		s = a + 1;
		while (s < ac)
		{
			if (ft_strcmp(tab[a], tab[s]) > 0)
				swap(&tab[a], &tab[s]);
			s++;
		}
		a++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	ft_sort_int_tab(argv, argc);
	while (argv[i])
	{
		ft_putstr(argv[i++]);
		write(1, "\n", 1);
	}
	return (0);
}
