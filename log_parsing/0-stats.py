#!/usr/bin/python3
"""
Log Parsing Script

This script reads HTTP access logs from stdin and computes metrics.
It processes input line by line and outputs statistics every 10 lines.

Input format:
Each line should follow this format:
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
Example: 127.0.0.1 - [2017-02-05 23:31:22.452556] 
        "GET /projects/260 HTTP/1.1" 200 724

The script extracts and tracks:
- Total file size (sum of all file sizes encountered)
- Count of HTTP status codes (200, 301, 400, 401, 403, 404, 405, 500)

Output:
After every 10 lines and/or a keyboard interruption (CTRL + C), 
print these statistics from the beginning:
- File size: <total size>
- <status code>: <number of occurrences> (for each status code, sorted)

Usage:
    $ cat logfile.txt | ./0-stats.py
    $ ./0-stats.py < logfile.txt
"""
import fileinput
import sys
import signal


def print_stats(total_size, status_codes):
    """
    Print the current statistics.

    Args:
        total_size (int): Total file size processed so far
        status_codes (dict): Dictionary with status codes and their counts
    """
    print("File size: {}".format(total_size))
    for code in sorted([int(k) for k in status_codes.keys()]):
        print("{}: {}".format(code, status_codes[str(code)]))


def process_logs():
    """
    Processes the log file line by line, extracting and aggregating data.
    """
    # Variables to store aggregated data
    status_codes = {}  # Dictionary to count occurrences of each status code
    total_size = 0     # Accumulator for total file size
    count = 0          # Counter for number of lines processed

    # Define signal handler for keyboard interruption
    def signal_handler(sig, frame):
        print_stats(total_size, status_codes)
        sys.exit(0)

    # Register the signal handler
    signal.signal(signal.SIGINT, signal_handler)

    try:
        # Main processing loop
        for line in fileinput.input():
            # Split the line into components
            line = line.split(' ')

            # Check if this is a GET request (simplified condition)
            try:
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
            except IndexError:
                # If the line does not match the expected format, skip it
                continue

    except KeyboardInterrupt:
        # Handle keyboard interruption (CTRL+C)
        print_stats(total_size, status_codes)
        sys.exit(0)
    print_stats(total_size, status_codes)


if __name__ == "__main__":
    process_logs()
