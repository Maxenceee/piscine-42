/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:52:22 by mgama             #+#    #+#             */
/*   Updated: 2022/09/17 13:52:25 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "structs.h"
#include "parsing.h"
#include "functions.h"

int	main(int ac, char **av)
{
	char			*dict_name;
	t_parsed_dict	dict;
	int				number;

	dict_name = "resources/numbers.dict";
	if (ac == 2)
	{
		printf("default dict\n");
		number = av[1];
	}
	else if (ac == 3)
	{
		printf("custom dict\n");
		dict_name = av[1];
		number = av[2];
	}
	else
	{
		printf("invalid arguments\n");
		return (1);
	}

	printf("number to write %s\n", av[1]);
	dict = parse_dict(dict_name);

	/* temporary */
	printf("size of parsed dict: %d items\ncontent: \n", dict.size);
	int	i = 0;
	while (i < dict.size)
	{
		printf("%u = %s\n", dict.content[i].value, dict.content[i].name);
		i++;
	}

	return (0);
}
