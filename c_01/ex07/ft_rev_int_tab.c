/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:49:53 by mgama             #+#    #+#             */
/*   Updated: 2022/11/08 19:37:19 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	count;
	int	d;
	int	e;

	count = 0;
	while (count < size / 2)
	{
		d = tab[count];
		e = tab[size - count - 1];
		tab[size - count - 1] = d;
		tab[count] = e;
		count++;
	}
}
