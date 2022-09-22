/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:53:24 by mgama             #+#    #+#             */
/*   Updated: 2022/09/17 13:53:25 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

void		print_error(char *error);
void		ft_print(char *msg);
int			can_num_be_written(char *num);

int			check_separator(char c, char *charset);
int			count_strings(char *str, char *charset);
int			ft_strlen_sep(char *str, char *charset);
char		*ft_word(char *str, char *charset);
char		**ft_split(char *str, char *charset);

void		swap(t_numbers_name *p1, t_numbers_name *p2);
int			is_first_bigger(char *s1, char *s2);
void		ft_sort_int_tab(t_numbers_name *tab, int ac);

t_element	*create_element(char *name);
t_list		*init(void);
void		insert_elem(t_list *list, char *name);
void		print_elem(t_list *list);
void		free_elem(t_list *list);

#endif