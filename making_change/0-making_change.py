#!/usr/bin/python3
"""module for making change problem"""


def makeChange(coins, total):
    """
    Determines the fewest number of coins
    needed to make change for a given amount.
    """
    if total <= 0:
        return 0

    def helper(remaining, memo={}):
        if remaining in memo:
            return memo[remaining]
        if remaining == 0:
            return 0
        if remaining < 0:
            return float('inf')

        min_coins = float('inf')
        for coin in coins:
            if coin <= remaining:
                result = helper(remaining - coin, memo)
                if result != float('inf'):
                    min_coins = min(min_coins, result + 1)

        memo[remaining] = min_coins
        return min_coins

    result = helper(total)
    return result if result != float('inf') else -1
