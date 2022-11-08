/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:06:00 by mgama             #+#    #+#             */
/*   Updated: 2022/11/08 19:31:16 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_numbers_name
{
	unsigned int	value;
	unsigned int	len;
	char			*name;
}	t_numbers_name;

typedef struct s_dict
{
	int		size;
	char	*content;
}	t_dict;

typedef struct s_parsed_dict
{
	int				size;
	t_numbers_name	*content;
}	t_parsed_dict;

typedef struct s_Element
{
	char				*name;
	struct s_Element	*next;
}	t_element;

typedef struct s_List
{
	t_element	*data;
}	t_list;

#endif