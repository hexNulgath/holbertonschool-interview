#!/usr/bin/python3
"""Module for prime game logic."""


def isWinner(x, nums):
    """
    Determines the winner of the prime game.
    """
    max_num = max(nums)
    prime_flags = prime_list(max_num)
    prime_counts = [0] * (max_num + 1)

    for i in range(1, max_num + 1):
        prime_counts[i] = prime_counts[i - 1] + (1 if prime_flags[i] else 0)

    maria_wins = 0
    for n in nums:
        if prime_counts[n] % 2 == 1:
            maria_wins += 1

    if maria_wins > x / 2:
        return "Maria"
    elif maria_wins < x / 2:
        return "Ben"
    else:
        return None


def prime_list(n):
    """
    Generates a list of boolean value
    indicating the primality of numbers up to n.
    """
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False

    for i in range(2, int(n**0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False

    return is_prime
