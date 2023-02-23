#!/usr/bin/python3
"""The Change Making Problem -
Fewest Coins To Make Change
Solved using Bottom-UP Dynamic Programming"""


def makeChange(coins, total):
    """Given a pile of coins of different values,
    determine the fewest number of coins needed
    to meet a given amount total.

    Return: fewest number of coins needed to meet total
    If total is 0 or less, return 0
    If total cannot be met by any number of coins you have, return -1
    """
    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for coin in coins:
        for i in range(coin, total + 1):
            dp[i] = min(dp[i], dp[i - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1
