/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:02:09 by mgama             #+#    #+#             */
/*   Updated: 2022/09/05 17:13:33 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_str(char *str)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (str[i])
		{
			if (str[i] < 32 || str[i] == 127)
			{
				write(1, ".", 1);
			}
			else
			{
				write(1, &str[i], 1);
			}
		}
		else
			return ;
		i++;
	}
}

void	ft_putnbr_base(unsigned long long int nbr, char *base)
{
	unsigned long long int	base_value;
	char					c;
	int						i;

	i = 0;
	while (base[i] != 0)
	{
		i += 1;
	}
	base_value = i;
	if (nbr >= base_value)
	{
		ft_putnbr_base(nbr / base_value, base);
		ft_putnbr_base(nbr % base_value, base);
	}
	else
	{
		c = base[nbr % base_value];
		write(1, &c, 1);
	}
}

void	print_char_in_hex(char *str, char *hexa)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		if (str[i])
			ft_putnbr_base(str[i], hexa);
		else
			write(1, "  ", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char			*str;
	char			*hexa;
	unsigned int	loop;

	loop = 0;
	str = (char *)addr;
	hexa = "0123456789abcdef";
	if (size == 0)
		return (addr);
	while (loop <= (size / 16))
	{
		ft_putnbr_base((unsigned long long) &str[loop * 16], hexa);
		write(1, ":", 1);
		print_char_in_hex(&str[loop * 16], hexa);
		write(1, " ", 1);
		ft_put_str(&str[loop * 16]);
		loop++;
		write(1, "\n", 1);
	}
	return (addr);
}
