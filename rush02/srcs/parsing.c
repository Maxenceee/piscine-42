/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:11:24 by mgama             #+#    #+#             */
/*   Updated: 2022/09/17 14:11:27 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "structs.h"
#include "parsing.h"
#include "functions.h"

t_parsed_dict	parse_dict(char *dict_name)
{
	t_dict			dict;
	t_parsed_dict	parsed_dict;

	dict = read_file(dict_name);
	printf("size of dict: %d\ncontent: \n%s\n", dict.size, dict.content);
	parsed_dict = parse_to_tab(dict);
	return (parsed_dict);
}

t_dict	read_file(char *dict_name)
{
	int 	of;
	int 	c;
    char 	ch[30000];
	t_dict	dict;

    of = open(dict_name, O_RDONLY);
	if (of < 0)
	{
		printf("Dict Error\n");
		dict.size = 0;
		return (dict);
    }
	c = read(of, ch, 30000);
	if (close(of) < 0) 
    {
		printf("Dict Error\n");
		dict.size = 0;
		return (dict);
    }
	dict.content = ch;
	dict.size = ft_strlen(ch);
	return (dict);
}

t_parsed_dict	parse_to_tab(t_dict dict)
{
	t_numbers_name	*fnl;
	char			**tmp;
	int 			i;
	int 			j;
	char			**sub_split;
	t_numbers_name	temp_num;
	int				kcount;
	t_parsed_dict	parsed_dict;

	kcount = count_key_word(dict.content);
	fnl = malloc(sizeof(t_numbers_name) * kcount);
	if (!fnl)
	{
		parsed_dict.size = 0;
		return (parsed_dict);
	}
	tmp = ft_split(dict.content, "\n");
	i = 0;
	j = 0;
	while (tmp[j])
	{
		sub_split = ft_split(tmp[j], ": ");
		if (is_first_bigger(sub_split[0], "4294967295") <= 0)
		{
			temp_num.value = ft_atoi(sub_split[0]);
			temp_num.name = sub_split[1];
			fnl[i++] = temp_num;
		}
		j++;
	}
	parsed_dict.size = i;
	parsed_dict.content = fnl;
	return (parsed_dict);
}