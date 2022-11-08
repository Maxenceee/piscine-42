/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:30:24 by mgama             #+#    #+#             */
/*   Updated: 2022/11/08 19:30:26 by mgama            ###   ########.fr       */
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