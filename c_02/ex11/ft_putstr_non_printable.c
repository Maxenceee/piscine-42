/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:45:43 by mgama             #+#    #+#             */
/*   Updated: 2022/09/05 13:45:49 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*src != '\0')
	{
		dest[i] = *src;
		src++;
		i++;
	}
	while (dest[i])
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

void	dec_to_hexa(int str)
{
	int		r;
	int		i;
	char	base[16];
	char	hexa[3];

	ft_strcpy(base, "0123456789abcdef");
	i = 0;
	hexa[0] = '\\';
	if (str < 16)
	{
		hexa[1] = '0';
	}
	while (str > 0)
	{
		r = str % 16;
		hexa[3 - i - 1] = base[r];
		str = str / 16;
		i++;
	}
	i = 0;
	while (hexa[i])
	{
		write(1, &hexa[i], 1);
		i++;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			dec_to_hexa(str[i]);
			i++;
		}
		if (str[i] == '\0')
			return ;
		write(1, &str[i], 1);
		i++;
	}
}
