/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:49:53 by mgama             #+#    #+#             */
/*   Updated: 2022/11/08 19:37:24 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void	ft_sort_int_tab(int	*tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				swap(&tab[j], &tab[j + 1]);
			}
			j++;
		}
		i++;
	}
}
