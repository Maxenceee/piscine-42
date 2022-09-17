#include "parsing.h"
#include "generic.h"
#include <stdlib.h>

int check_arguments(int argc, char *argv[])
{
	if (argc != 2)
	{
		return (1);
	}
	/* check if the partern is correct */
	if (ft_strlen(argv[1]) != 31)
	{
		return (1);
	}
	return (0);
}

int *convert_pattern(char *str)
{
	int *tab;
	int i;
	int j;

	i = 0;
	j = 0;
	/* creates an array with malloc of size 16, if not return 0 as error */
	if (!(tab = malloc(sizeof(int) * 16)))
	{
		return (0);
	}
	while (str[i] != '\0')
	{
		/* for each char at index i check if it is number, then convert it to `int` */
		if (str[i] >= '0' && str[i] <= '9')
			tab[j++] = ft_atoi(str + i);
		i++;
	}
	return (tab);
}

void print_puzzle_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	/* loop inside rows and columns */
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			/* display each cell */
			ft_putnbr(grid[i][j]);
			if (j < 3)
			{
				ft_putchar(' ');
			}
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
