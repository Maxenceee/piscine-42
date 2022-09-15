/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:09:29 by mgama             #+#    #+#             */
/*   Updated: 2022/09/04 18:09:32 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (j == 1)
				str[i] -= 32;
			    j = 0;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			j = 0;
		else
			j = 1;
		i++;
	}
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char a[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("%s", ft_strcapitalize(a));
	return (0);
}
*/