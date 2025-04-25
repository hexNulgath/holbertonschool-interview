#!/usr/bin/python3
"""
    Calculates the fewest number of operations
    needed to result in exactly n H characters.

    In a text file, there is a single character H.
    Your text editor can execute only
    two operations in this file: Copy All and Paste.
    This function calculates the minimum
    number of operations needed to get exactly n H characters in the file.

    Args:
        n (int): The desired number of H characters

    Returns:
        int: The minimum number of operations needed, or 0 if n is impossible
"""


def minOperations(n):
    """
    Calculates the fewest number of operations
    needed to result in exactly n H characters.
    """
    operations = 0
    if n <= 1:
        return operations
    factor = 2
    while n > 1:
        if n % factor == 0:
            operations += factor
            n //= factor
        else:
            factor += 1
    return operations
