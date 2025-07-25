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
    water = 0
    max_wall = 0
    pool = 0
    for i in range(0, len(walls)):
        if walls[i] == 0 and max_wall != 0:
            pool += 1
        elif walls[i] > max_wall:
            water += max_wall * pool
            pool = 0
            max_wall = walls[i]
        else:
            water += walls[i] * pool
            pool = 0

    return water
