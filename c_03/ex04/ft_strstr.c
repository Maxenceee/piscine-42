/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:54:38 by mgama             #+#    #+#             */
/*   Updated: 2022/11/08 19:39:15 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_in(char *sr, char *pr, int idx)
{
	int	i;

	i = 0;
	while (pr[i] != '\0' && sr[idx + i] != '\0')
	{
		if (pr[i] != sr[idx + i])
			return (0);
		i++;
	}
	if (sr[idx + i] == '\0' && pr[i] != '\0')
		return (0);
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (is_in(str, to_find, i))
		{
			return (str + i);
		}
		i++;
	}
	return (0);
}
