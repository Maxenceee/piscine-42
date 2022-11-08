/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:38:07 by acarlott          #+#    #+#             */
/*   Updated: 2022/11/08 19:31:32 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "parsing.h"
#include "converter.h"
#include "functions.h"

t_element	*create_element(char *name)
{
	t_element	*element;

	element = malloc(sizeof(element));
	if (!element)
	{
		print_error("Error");
		return (0);
	}
	element->name = name;
	element->next = NULL;
	return (element);
}

t_list	*init(void)
{
	t_list		*list;
	t_element	*element;

	list = malloc(sizeof(*list));
	element = malloc(sizeof(element));
	if (list == NULL || element == NULL)
	{
		print_error("Error");
		return (0);
	}
	element->name = NULL;
	element->next = NULL;
	list->data = element;
	return (list);
}

void	insert_elem(t_list *list, char *name)
{
	t_element	*new;

	new = create_element(name);
	if (list == NULL || new == NULL)
	{
		print_error("Error");
		return ;
	}
	new->name = name;
	new->next = list->data;
	list->data = new;
}

void	print_elem(t_list *list)
{
	t_element	*current;

	if (list == NULL)
	{
		print_error("Error");
		return ;
	}
	current = list->data;
	show(current);
}

void	free_elem(t_list *list)
{
	t_element	*delete;

	if (list == NULL)
	{
		print_error("Error");
		return ;
	}
	if (list->data != NULL)
	{
		delete = list->data;
		list->data = list->data->next;
		free(delete);
	}
}
