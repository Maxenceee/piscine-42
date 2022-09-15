/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:39:08 by mgama             #+#    #+#             */
/*   Updated: 2022/09/14 23:39:09 by mgama            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "ft_display_file.h"

void	read_file(char *file)
{
	int of;
	int c;
    char *ch[256];

    of = open(file, O_RDONLY);

    printf("opened the file = %d\n", of); 

	c = read(of, ch, 256);
	printf("%d %d\n", c, of);
	printf("%s\n", *ch);
	while (ch[c])
	{
		printf("%s", ch[c]);
		c++;
	}

	if (close(of) < 0) 
    {
		printf("%s", CANNOT_READ);
		return ;
    }
}

int	main(int ac, char *av[])
{
	if (ac < 2)
		// return (FILE_MISSING);
		return (1);
	else if (ac > 2)
		// return (TOO_MANY_ARGUMENT);
		return (1);
	read_file(av[1]);
	return (0);
}
