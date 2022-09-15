/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 21:23:49 by mgama             #+#    #+#             */
/*   Updated: 2022/09/11 21:23:50 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	calc_size_tab(char **strs, int size)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	l = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j++] != '\0')
			l++;
		i++;
	}
	return (l);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		u;
	char	*n;

	i = 0;
	u = 0;
	n = malloc(sizeof(char) * calc_size_tab(strs, size));
	if (!n)
		return (0);
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			n[u++] = strs[i][j++];
		}
		j = 0;
		if (i < size - 1)
			while (sep[j] != '\0')
				n[u++] = sep[j++];
		i++;
	}
	n[u] = '\0';
	return (n);
}

/*
int	main(void)
{
	char	*a[] = {"abcd" ,"efgh", "ijkl"};

	printf("%s", ft_strjoin(3, a, "-a-"));
	return (0);
}
*/