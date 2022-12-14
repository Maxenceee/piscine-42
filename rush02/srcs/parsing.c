/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:11:24 by mgama             #+#    #+#             */
/*   Updated: 2022/11/08 19:31:52 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "parsing.h"
#include "functions.h"

t_parsed_dict	parse_dict(char *dict_name)
{
	t_dict			dict;
	t_parsed_dict	parsed_dict;

	dict = read_file(dict_name);
	if (dict.size == 0)
	{
		parsed_dict.size = 0;
		return (parsed_dict);
	}
	parsed_dict = parse_to_tab(dict);
	return (parsed_dict);
}

t_dict	read_file(char *dict_name)
{
	int		of;
	char	ch[30000];
	t_dict	dict;

	of = open(dict_name, O_RDONLY);
	if (of < 0)
	{
		print_error("Dict Error\n");
		dict.size = 0;
		return (dict);
	}
	read(of, ch, 30000);
	if (close(of) < 0)
	{
		print_error("Dict Error\n");
		dict.size = 0;
		return (dict);
	}
	dict.content = ch;
	dict.size = ft_strlen(ch);
	return (dict);
}

void	string_to_object(t_dict dict, t_parsed_dict *parsed_dict, \
t_numbers_name	*fnl)
{
	char			**tmp;
	char			**sub_split;
	t_numbers_name	temp_num;
	int				i;
	int				j;

	tmp = ft_split(dict.content, "\n");
	i = 0;
	j = 0;
	while (tmp[j])
	{
		sub_split = ft_split(tmp[j], ": ");
		if (is_first_bigger(sub_split[0], "4294967295") <= 0)
		{
			temp_num.value = ft_atoi(sub_split[0]);
			temp_num.len = get_num_len(temp_num.value);
			temp_num.name = sub_split[1];
			fnl[i++] = temp_num;
		}
		j++;
	}
	parsed_dict->size = i;
	parsed_dict->content = fnl;
}

t_parsed_dict	parse_to_tab(t_dict dict)
{
	t_numbers_name	*fnl;
	int				kcount;
	t_parsed_dict	parsed_dict;

	kcount = count_key_word(dict.content);
	fnl = malloc(sizeof(t_numbers_name) * kcount);
	if (!fnl)
	{
		parsed_dict.size = 0;
		print_error("Dict Error\n");
		return (parsed_dict);
	}
	string_to_object(dict, &parsed_dict, fnl);
	return (parsed_dict);
}
