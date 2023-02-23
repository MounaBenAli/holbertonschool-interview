#!/usr/bin/python3
"""The Change Making Problem -
Fewest Coins To Make Change
Solved using Bottom-UP Dynamic Programming"""


def make_change(coins, total):
    """Given a pile of coins of different values,
    determine the fewest number of coins needed
    to meet a given amount total.

    Return: fewest number of coins needed to meet total
    If total is 0 or less, return 0
    If total cannot be met by any number of coins you have, return -1
    """
    if total <= 0:
        return 0

    # Create a table to store the minimum number of coins required
    # to make up each value from 0 to the target value
    table = [float('inf')] * (total + 1)
    # Initialize the first entry of the table to 0
    table[0] = 0

    # Iterate over the coins and update the table entries
    for coin in coins:
        for i in range(coin, total + 1):
            if table[i - coin] != float('inf'):
                table[i] = min(table[i], table[i - coin] + 1)

    # Return the last entry in the table, which represents the
    # minimum number of coins required to make up the target value
    if table[total] == float('inf'):
        return -1
    else:
        return table[total]
