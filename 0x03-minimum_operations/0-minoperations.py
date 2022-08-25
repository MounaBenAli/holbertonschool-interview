#!/usr/bin/python3
""" Minimum Operations to reduce n to 0 method
"""


def minOperations(n):
    """calculates the fewest number of operations needed to result in
    exactly n H characters in the file.

    Returns an integer

    If n is impossible to achieve, return 0
    """

    i = 0
    n_div = 2
    if n < 1 or type(n) is not int:
        return 0
    while n > 1:
        if n % n_div == 0:
            n = n / n_div
            i = i + n_div
        else:
            n_div = n_div + 1
    return i
