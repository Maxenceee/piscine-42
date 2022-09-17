#include "solving.h"

int check_col_up(int grid[4][4], int gap, int pattern[16])
{
	int i;
	int max;
	int count;

	i = 0;
	max = 0;
	count = 0;
	/* check if the current gap represent the good column  */
	if (gap / 4 == 3)
	{
		/* start from i = 0 to go from top to bottom */
		while (i < 4)
		{
			/* for each cell of the column get max and count */
			if (grid[i][gap % 4] > max)
			{
				/* change max value to new max */
				max = grid[i][gap % 4];
				count++;
			}
			i++;
		}
		/* compare if the result is as expected */
		if (pattern[gap % 4] != count)
			return (1);
	}
	return (0);
}

int check_row_right(int grid[4][4], int gap, int pattern[16])
{
	int i;
	int max_size;
	int visible_towers;

	i = 4;
	max_size = 0;
	visible_towers = 0;
	/* check if the current gap represent the good row */
	if (gap % 4 == 3)
	{
		/* start from i = 4 to go from right to left */
		while (--i >= 0)
		{
			/* for each cell of the row get max and count */
			if (grid[gap / 4][i] > max_size)
			{
				/* change max value to new max */
				max_size = grid[gap / 4][i];
				visible_towers++;
			}
		}
		/* compare if the result is as expected */
		if (pattern[12 + gap / 4] != visible_towers)
			return (1);
	}
	return (0);
}

int check_col_down(int grid[4][4], int gap, int pattern[16])
{
	int i;
	int max;
	int count;

	i = 3;
	max = 0;
	count = 0;
	/* check if the current gap represent the good column */
	if (gap / 4 == 3)
	{
		/* start from i = 3 to go from bottom to top */
		while (i >= 0)
		{
			/* for each cell of the column get max and count */
			if (grid[i][gap % 4] > max)
			{
				/* change max value to new max */
				max = grid[i][gap % 4];
				count++;
			}
			i--;
		}
		/* compare if the result is as expected */
		if (pattern[4 + gap % 4] != count)
			return (1);
	}
	return (0);
}

int check_row_left(int grid[4][4], int gap, int pattern[16])
{
	int i;
	int max;
	int count;

	i = 0;
	max = 0;
	count = 0;
	/* check if the current gap represent the good row */
	if (gap % 4 == 3)
	{
		/* start from i = 0 to go from left to right */
		while (i < 4)
		{
			/* for each cell of the row get max and count */
			if (grid[gap / 4][i] > max)
			{
				/* change max value to new max */
				max = grid[gap / 4][i];
				count++;
			}
			i++;
		}
		/* compare if the result is as expected */
		if (pattern[8 + gap / 4] != count)
			return (1);
	}
	return (0);
}

int check_cell(int grid[4][4], int gap, int pattern[16])
{
	/* test for all possibilities if current case if good */
	if (check_row_left(grid, gap, pattern) == 1)
		return (1);
	if (check_row_right(grid, gap, pattern) == 1)
		return (1);
	if (check_col_down(grid, gap, pattern) == 1)
		return (1);
	if (check_col_up(grid, gap, pattern) == 1)
		return (1);
	return (0);
}
