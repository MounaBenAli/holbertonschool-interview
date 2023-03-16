#!/usr/bin/python3
"""Island perimeter function"""


def island_perimeter(grid):
    """
    Returns the perimeter of an island,
    that is represented by a 2D matrix grid of 1s and 0s,
    where 1s represent land and 0s represent water.
    The perimeter is calculated by counting the total length
    of the boundary between the land and the water,
    taking into account the shared edges between adjacent land cells.
    Overall time complexity of the function is O(rows*cols).
    Space complexity of the island_perimeter function is O(1).
    """

    if not grid or not grid[0]:
        return 0

    rows, cols = len(grid), len(grid[0])
    land = 1
    perimeter = 0

    for row in range(rows):
        for col in range(cols):
            if grid[row][col] is land:
                perimeter += 4
                if row > 0 and grid[row - 1][col] is land:
                    perimeter -= 2
                if col > 0 and grid[row][col - 1] is land:
                    perimeter -= 2
    return perimeter
