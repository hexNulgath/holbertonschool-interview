#!/usr/bin/python3
"""0-stats.py"""

import fileinput
status_codes = {}
total_size = 0
count = 0


def print_stats(total_size, status_codes):
    """Prints the statistics."""
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        print("{}: {}".format(code, status_codes[code]))
    print()


for line in fileinput.input():
    line = line.split(' ')
    if line[4].find('GET'):
        if line[7] in status_codes:
            status_codes[line[7]] += 1
        else:
            status_codes[line[7]] = 1
        total_size += int(line[8])
        count += 1
        if count % 10 == 0:
            print_stats(total_size, status_codes)
    else:
        print("out")
