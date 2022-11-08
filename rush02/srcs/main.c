/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:52:22 by mgama             #+#    #+#             */
/*   Updated: 2022/11/08 19:31:44 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "parsing.h"
#include "converter.h"
#include "functions.h"

void	print_error(char *error)
{
	while (*error)
	{
		write(2, error++, 1);
	}
}

void	ft_print(char *msg)
{
	while (*msg)
	{
		write(1, msg++, 1);
	}
}

int	can_num_be_written(char *num)
{
	if (is_first_bigger(num, "4294967295") || contains(num, '.'))
	{
		print_error("Error\n");
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	char			*dict_path;
	t_parsed_dict	dict;
	unsigned int	number;

	dict_path = "resources/numbers.dict";
	if (ac == 2)
	{
		if (!can_num_be_written(av[1]))
			return (1);
		number = ft_atoi(av[1]);
	}
	else if (ac == 3)
	{
		if (!can_num_be_written(av[2]))
			return (1);
		dict_path = av[1];
		number = ft_atoi(av[2]);
	}
	else
		return (1);
	dict = parse_dict(dict_path);
	if (dict.size == 0)
		return (1);
	convert_num_to_letters(number, dict);
	return (0);
}
