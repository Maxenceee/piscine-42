/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:28:38 by mgama             #+#    #+#             */
/*   Updated: 2022/09/13 19:28:39 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_fill_fnl(char *buffer, char **fnl, int string_index, unsigned int j)
{
	char	*str;
	int		i;

	if (ft_strlen(buffer) > 0)
	{
		buffer[j] = '\0';
		str = malloc(ft_strlen(buffer) * sizeof(char));
		i = 0;
		while (buffer[i] != '\0')
		{
			str[i] = buffer[i];
			i++;
		}
		str[i] = '\0';
		fnl[string_index] = malloc(sizeof(char) * ft_strlen(buffer));
		fnl[string_index] = str;
		j = 0;
	}
}

int	is_charset_from_pos(char *str, char *charset, int pos)
{
	unsigned int	i;

	i = 0;
	while (str[i + pos] == charset[i] && str[i + pos] != '\0')
	{
		i++;
	}
	if (charset[i] == '\0')
		return (1);
	return (0);
}

void	put_fnl(char *str, char *charset, char **fnl, int len)
{
	int				i;
	unsigned int	j;
	int				string_index;
	char			buffer[16384];

	i = 0;
	j = 0;
	string_index = -1;
	while (i <= len)
	{
		if (is_charset_from_pos(str, charset, i) || (i == len \
		&& !is_charset_from_pos(str, charset, i - ft_strlen(charset))))
		{
			while (is_charset_from_pos(str, charset, i))
				i += ft_strlen(charset);
			ft_fill_fnl(buffer, fnl, string_index++, j);
			j = 0;
		}
		if (i == len)
			break ;
		if (i < len)
			buffer[j++] = str[i++];
	}
	fnl[string_index] = 0;
}

char	**ft_split(char *str, char *charset)
{
	char			**fnl;
	unsigned int	wnum;
	int				len;
	unsigned int	i;

	wnum = 0;
	i = 0;
	while (str[i] != '\0' && str[i + 1] != '\0')
	{
		if (is_charset_from_pos(str, charset, i))
			wnum++;
		i++;
	}
	fnl = malloc(sizeof(char *) * (wnum + 2));
	if (!fnl)
		return (0);
	len = ft_strlen(str);
	put_fnl(str, charset, fnl, len);
	return (fnl);
}

/*#include <stdio.h>

*
*	This is a variant of ft_split
*	This one is not valid for the moulinette
*
*	However this variant might be intersting,
*	it takes all charset characters as the separator
*	and split the string depending on this full charset
*

int	main(int argc, char **argv)
{
	int		index;
	char	**split;
	(void)	argc;
	split = ft_split(argv[1], argv[2]);
	index = 0;
	while (split[index])
	{
		printf("%s\n", split[index]);
		index++;
	}
}*/