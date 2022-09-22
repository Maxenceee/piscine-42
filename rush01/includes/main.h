/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:22:50 by mgama             #+#    #+#             */
/*   Updated: 2022/09/11 18:22:53 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

int	check_adjacent_cell(int grid[4][4], int gap, int num);

int	puzzle_solver(int grid[4][4], int pattern[16], int gap);

#endif
