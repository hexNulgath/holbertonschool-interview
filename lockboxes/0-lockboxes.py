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
    keys = [0]
    opened = []

    while keys:
        current = keys.pop(0)
        if current not in opened and current < len(boxes):
            opened.append(current)
            keys += boxes[current]

    if len(opened) == len(boxes):
        return True
    else:
        return False
