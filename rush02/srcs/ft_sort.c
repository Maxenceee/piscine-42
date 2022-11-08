/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:37:57 by mgama             #+#    #+#             */
/*   Updated: 2022/11/08 19:31:36 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "parsing.h"
#include "functions.h"

void	swap(t_numbers_name *p1, t_numbers_name *p2)
{
	t_numbers_name	temp;

	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int	is_first_bigger(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	l;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	l = 0;
	if (i > j)
		return (1);
	else if (i < j)
		return (0);
	while (s1[l] == s2[l] && s1[l] != '\0' && s2[l] != '\0')
		l++;
	return (s1[l] - s2[l]);
}

void	ft_sort_int_tab(t_numbers_name *tab, int ac)
{
	int	a;
	int	s;

	a = 0;
	while (ac > a)
	{
		s = a + 1;
		while (s < ac)
		{
			if (tab[a].value > tab[s].value)
				swap(&tab[a], &tab[s]);
			s++;
		}
		a++;
	}
}
