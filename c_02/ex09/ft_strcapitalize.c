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

int	ft_str_is_lowercase(char *str)
{
	if (*str < 'a' || *str > 'z')
		return (0);
	else
		return (1);
}

int	ft_str_is_uppercase(char *str)
{
	if (*str < 'A' || *str > 'Z')
		return (0);
	else
		return (1);
}

int	ft_str_is_alpha(char *str)
{
	if ((*str < 'A' || (*str > 'Z' && *str < 'a') || *str > 'z'))
	{
		if (!(*str >= 48 && *str <= 57))
			return (0);
	}
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (ft_str_is_lowercase(&str[i]) && (ft_str_is_alpha(&str[i - 1]) == 0))
		{
			str[i] -= 32;
		}
		else if (ft_str_is_uppercase(&str[i]) && ft_str_is_alpha(&str[i]))
		{
			str[i] += 32;
		}
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