/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:44:34 by mgama             #+#    #+#             */
/*   Updated: 2022/09/04 19:46:57 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	count;

	count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

unsigned int	ft_strnlen(char	*str, unsigned int maxlen)
{
	unsigned int	len;

	len = 0;
	while (len < maxlen)
	{
		if (!*str)
			return (len);
		len++;
		str++;
	}
	return (len);
}

void	*ft_memcpy(void *dest, void *src, unsigned int len)
{
	char	*d;
	char	*s;

	d = dest;
	s = src;
	while (len--)
		*d++ = *s++;
	return (dest);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*s;
	int		ss;

	s = dest;
	dest += ft_strlen(dest);
	ss = ft_strnlen(src, nb);
	dest[ss] = '\0';
	ft_memcpy(dest, src, ss);
	return (s);
}
