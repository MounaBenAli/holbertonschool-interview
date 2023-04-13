#!/usr/bin/python3
"""The Change Making Problem -
Fewest Coins To Make Change
"""


def makeChange(coins, total):
    """Given a pile of coins of different values,
    determine the fewest number of coins needed
    to meet a given amount total.

    Return: fewest number of coins needed to meet total
    If total is 0 or less, return 0
    If total cannot be met by any number of coins you have, return -1
    """
    if total <= 0:
        return 0

    coins.sort()
    coins_used = 0
    
    for coin in coins[::-1]:
        while total >= coin:
            total -= coin
            coins_used += 1
    
    if total > 0:
        return -1
    
    return coins_used
