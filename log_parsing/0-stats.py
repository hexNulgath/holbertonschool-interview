#!/usr/bin/python3
"""
Log Parser Module

This module reads log data from stdin, parses it to extract information about
HTTP requests, and prints statistics every 10 lines including:
- Total file size
- Count of each HTTP status code encountered
"""

import fileinput

# Global variables to store aggregated data
status_codes = {}  # Dictionary to count occurrences of each status code
total_size = 0     # Accumulator for total file size
count = 0          # Counter for number of lines processed


def print_stats(total_size, status_codes):
    """
    Print the accumulated statistics.

    Args:
        total_size (int): The total file size accumulated from all requests
        status_codes (dict): Dictionary containing counts of each status code

    Prints:
        - The total file size
        - Counts for each status code in ascending order
    """
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        print("{}: {}".format(code, status_codes[code]))
    print()


# Main processing loop
for line in fileinput.input():
    # Split the line into components
    line = line.split(' ')

    # Check if this is a GET request (simplified condition)
    if line[4].find('GET'):
        # Update status code count
        if line[7] in status_codes:
            status_codes[line[7]] += 1
        else:
            status_codes[line[7]] = 1

        # Update total file size
        total_size += int(line[8])
        count += 1

        # Print stats every 10 lines
        if count % 10 == 0:
            print_stats(total_size, status_codes)
