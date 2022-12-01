#!/usr/bin/python3
"""Trapping Rain Water"""


def rain(walls):
    """compute how much water it can trap after raining"""
    stack = []
    size = len(walls)
    result = 0

    if not walls:
        return 0

    for i in range(size):
        while(len(stack) != 0 and (walls[stack[-1]] < walls[i])):
            pop_walls = walls[stack[-1]]
            stack.pop()

            if(len(stack) == 0):
                break

            distance = i - stack[-1] - 1

            min_walls = min(walls[stack[-1]], walls[i]) - pop_walls

            result += distance * min_walls

        stack.append(i)

    return result
