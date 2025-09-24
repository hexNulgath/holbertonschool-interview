#!/usr/bin/python3
"""module for making change problem"""


def makeChange(coins, total):
    """
    Determines the fewest number of coins
    needed to make change for a given amount.
    """
    if total <= 0:
        return 0

    # Initialize DP array with impossible values
    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for amount in range(1, total + 1):
        for coin in coins:
            if coin <= amount:
                dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1
