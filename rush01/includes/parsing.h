/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:30:19 by mgama             #+#    #+#             */
/*   Updated: 2022/11/08 19:30:21 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

int		check_arguments(int argc, char *argv[]);

int		*convert_pattern(char *str);

void	print_puzzle_grid(int grid[4][4]);

#endif