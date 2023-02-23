#!/usr/bin/python3
"""The Change Making Problem -
Fewest Coins To Make Change
Solved using dynamic programming with memoization & recursion
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

    memo = {0: 0}

    def dp(amount):
        """Recursive helper function that finds the minimum number of coins needed for the given amount
        """
        if amount in memo:
            return memo[amount]

        min_coins = float('inf')
        for coin in coins:
            if coin > amount:
                continue
            sub_min_coins = dp(amount - coin)
            if sub_min_coins == -1:
                continue
            min_coins = min(min_coins, sub_min_coins + 1)

        memo[amount] = -1 if min_coins == float('inf') else min_coins
        return memo[amount]

    return dp(total)