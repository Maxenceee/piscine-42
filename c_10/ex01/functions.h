/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:37:17 by mgama             #+#    #+#             */
/*   Updated: 2022/11/08 19:44:58 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <stdio.h>

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char	*str);
char	*read_file(char *board_name);

char	*ft_strjoin(int size, char **strs, char *sep);
int		ft_compute_final_length(char **strings, int size, int sep_length);
char	*ft_strcpy(char *dest, char *src);

#endif