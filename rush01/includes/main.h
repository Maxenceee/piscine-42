/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:30:12 by mgama             #+#    #+#             */
/*   Updated: 2022/11/08 19:30:15 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

int	check_adjacent_cell(int grid[4][4], int gap, int num);

int	puzzle_solver(int grid[4][4], int pattern[16], int gap);

#endif
