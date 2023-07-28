#!/usr/bin/python3
"""Defines an island perimeter measuring function."""


def island_perimeter(grid):
    """Return the perimeter of an island described in grid.

    The grid represents water by 0 and land by 1.

    Args:
        grid (list[List[int]]): A list of list of integers representing the island.
    Returns:
        The perimeter of the island defined in grid.
    """
    rows = len(grid)
    tols = len(grid[0])
    perimeter = 0

    for i in range(rows):
        for j in range(tols):
            if grid[i][j] == 1:

                # count top edge
                if i == 0 or grid[i-1][j] == 0:
                     perimeter += 1

                # count bottom edge
                if i == rows-1 or grid[i][j-1] == 0:
                    perimeter += 1

                # count left edge
                if j == 0 or grid[i][j-1] == 0:
                    perimeter += 1

                # count right edge
                if j == tols-1 or grid[i][j+1] == 0:
                    perimeter += 1

    return perimeter
