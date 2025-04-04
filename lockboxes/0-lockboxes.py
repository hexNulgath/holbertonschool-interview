#!/usr/bin/python3
"""
This script is a simple implementation of a lockbox system using Python.
"""


def canUnlockAll(boxes):
    """
    Determines if all boxes can be opened.
    Each box contains a list of keys to other boxes.
    The function uses a breadth-first search approach to explore the boxes.
    """
    n = len(boxes)
    if n == 0:
        return False

    keys = list(boxes[0])
    unlocked = {0}

    while keys:
        current_key = keys.pop(0)
        if 0 <= current_key < n and current_key not in unlocked:
            unlocked.add(current_key)
            keys.extend(boxes[current_key])

    return len(unlocked) == n
