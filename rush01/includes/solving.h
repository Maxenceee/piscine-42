/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:22:50 by mgama             #+#    #+#             */
/*   Updated: 2022/09/11 18:22:53 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVING_H
# define SOLVING_H

int	check_pattern(int grid[4][4], int gap, int pattern[16]);

int	check_col_up(int grid[4][4], int gap, int pattern[16]);

int	check_row_right(int grid[4][4], int gap, int patern[16]);

int	check_col_down(int grid[4][4], int gap, int pattern[16]);

int	check_row_left(int grid[4][4], int gap, int pattern[16]);

#endif