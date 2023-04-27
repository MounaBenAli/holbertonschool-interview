#!/usr/bin/python3
"""
Prime Game
"""


def isWinner(x, nums):
    """ Prime Game """

    if not nums:
        # if nums is an empty list, return None
        return None
    if x < 1:
        # if x is less than 1, return None
        return None

    # create a list of prime numbers for each value of n in nums
    primes = [set() for _ in range(max(nums) + 1)]
    for i in range(2, len(primes)):
        if len(primes[i]) == 0:
            for j in range(i, len(primes), i):
                primes[j].add(i)
    # determine the winner for each round
    maria_wins = 0
    for n in nums:
        if len(primes[n]) == 0:
            # if there are no primes, Ben wins
            maria_wins += 0
        elif len(primes[n]) % 2 == 0:
            # if the number of primes is even, Maria wins
            maria_wins += 1
        else:
            # if the number of primes is odd, Ben wins
            maria_wins += 0
    if maria_wins > x - maria_wins:
        # Maria wins the overall game
        return "Maria"
    elif maria_wins < x - maria_wins:
        # Ben wins the overall game
        return "Ben"
    else:
        # the winner cannot be determined
        return None
