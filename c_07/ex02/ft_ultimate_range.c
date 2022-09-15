/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:59:11 by mgama             #+#    #+#             */
/*   Updated: 2022/09/11 19:59:13 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	i = 0;
	*range = malloc((max - min) * sizeof(int));
	if (!*range)
		return (-1);
	while (min + i < max)
	{
		(*range)[i] = min + i;
		i++;
	}
	(*range)[i] = '\0';
	return (i);
}
