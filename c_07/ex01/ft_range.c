/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:48:51 by mgama             #+#    #+#             */
/*   Updated: 2022/09/11 19:48:53 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
	{
		return (0);
	}
	i = 0;
	tab = malloc((max - min) * sizeof(100));
	if (!tab)
		return (0);
	while (min + i < max)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
