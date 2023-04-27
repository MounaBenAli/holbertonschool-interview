#!/usr/bin/python3
"""
Prime Game
"""


def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True


def isWinner(x, nums):
    # create a list of prime numbers for each value of n in nums
    primes = [set() for _ in range(max(nums) + 1)]
    for i in range(2, len(primes)):
        if len(primes[i]) == 0:
            for j in range(i, len(primes), i):
                primes[j].add(i)
    # determine the winner for each round
    maria_wins = 0
    for n in nums:
        if n < 2 or len(primes[n]) == 0:
            # if the number is less than 2 or has no primes, Ben wins
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
