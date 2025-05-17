#!/usr/bin/python3
"""
This is the module docstring that describes what 0-stats.py does
"""
import fileinput


# Global variables to store aggregated data
status_codes = {}  # Dictionary to count occurrences of each status code
total_size = 0     # Accumulator for total file size
count = 0          # Counter for number of lines processed
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
            print("File size: {}".format(total_size))
            for code in sorted(status_codes.keys()):
                print("{}: {}".format(code, status_codes[code]))
            print()
