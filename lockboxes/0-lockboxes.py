#!/usr/bin/python3
"""
This script is a simple implementation of a lockbox system using Python.
"""


def canUnlockAll(boxes):
    """
    Determines if all boxes can be opened.
    Each box contains a list of keys to other boxes.
    """
    n = len(boxes)
    if n == 0:
        return True

    unlocked = {0}
    to_process = [0]

    while to_process:
        current_box = to_process.pop()

        for key in boxes[current_box]:
            if 0 <= key < n and key not in unlocked:
                unlocked.add(key)
                to_process.append(key)

    return len(unlocked) == n
