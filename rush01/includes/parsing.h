/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:22:50 by mgama             #+#    #+#             */
/*   Updated: 2022/09/11 18:22:53 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

int		check_arguments(int argc, char *argv[]);

int		*convert_pattern(char *str);

void	print_puzzle_grid(int grid[4][4]);

#endif