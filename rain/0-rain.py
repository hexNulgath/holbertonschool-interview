#!/usr/bin/python3
"""
0-rain
"""


def rain(walls):
    """
    Given a list of non-negative integers
    representing the heights of walls with
    unit width 1, as if viewing the cross-section
    of a relief map, calculate how many square
    units of water will be retained after it rains
    """
    n = len(walls)
    if n == 0:
        return 0
    left_max = [0] * n
    right_max = [0] * n

    # Fill left_max array
    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i-1], walls[i])

    # Fill right_max array
    right_max[-1] = walls[-1]
    for i in range(n-2, -1, -1):
        right_max[i] = max(right_max[i+1], walls[i])

    # Calculate the trapped water
    water = 0
    for i in range(n):
        water += min(left_max[i], right_max[i]) - walls[i]

    return water
