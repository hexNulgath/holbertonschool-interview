#include "sandpiles.h"

/**
 * sand_disperse - Disperses sand grains in a sandpile
 * @grid: 3x3 grid representing the sandpile
 */
void sand_disperse(int grid[3][3])
{
	int i, j;
	int temp[3][3] = {{0}};

	/* Create a copy to read from while we modify the original */
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			temp[i][j] = grid[i][j];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (temp[i][j] > 3)
			{
				grid[i][j] -= 4;
				if (i > 0)
					grid[i - 1][j]++;
				if (i < 2)
					grid[i + 1][j]++;
				if (j > 0)
					grid[i][j - 1]++;
				if (j < 2)
					grid[i][j + 1]++;
			}
		}
	}
}

/**
 * is_stable - Checks if a sandpile is stable
 * @grid: 3x3 grid to check
 * Return: true if stable, false otherwise
 */
bool is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (false);
	return (true);
}

/**
 * print - Prints a 3x3 grid
 * @grid: Grid to print
 */
void print(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: First 3x3 grid
 * @grid2: Second 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	/* Add the two grids */
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	/* Stabilize the pile */
	while (!is_stable(grid1))
	{
		printf("=\n");
		print(grid1);
		sand_disperse(grid1);
	}
}