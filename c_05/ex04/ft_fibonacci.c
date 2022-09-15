/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:09:34 by mgama             #+#    #+#             */
/*   Updated: 2022/09/08 15:09:36 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index >= 2)
	{
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
	}
	else
	{
		if (index == 1)
		{
			return (1);
		}
	}
	return (0);
}
