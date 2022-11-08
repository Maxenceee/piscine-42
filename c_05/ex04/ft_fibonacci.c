/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:09:34 by mgama             #+#    #+#             */
/*   Updated: 2022/11/08 19:40:42 by mgama            ###   ########.fr       */
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
