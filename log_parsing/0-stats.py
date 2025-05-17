#!/usr/bin/python3
"""
Log Parsing and Statistics Script

This script reads HTTP access logs from stdin, computes metrics, and prints
statistics every 10 lines or upon keyboard interruption (CTRL+C).

Features:
- Processes logs in real-time from standard input
- Tracks total file size transferred
- Counts occurrences of specific HTTP status codes
- Handles keyboard interruptions gracefully
- Validates log format before processing

Input Format:
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
Example: 127.0.0.1 - [2017-02-05 23:31:22.452556] "GET /projects/260 HTTP/1.1" 200 724

Tracked Status Codes:
200, 301, 400, 401, 403, 404, 405, 500

Output Format:
File size: <total size>
<status code>: <count> (for each code, numerically sorted)

Usage Examples:
    $ cat logfile.txt | ./0-stats.py
    $ ./0-stats.py < logfile.txt
    $ tail -f access.log | ./0-stats.py
"""

import fileinput
import sys
import signal
import re
from typing import Dict


def print_stats(total_size: int, status_codes: Dict[str, int]) -> None:
    """
    Display the current statistics in the required format.

    Args:
        total_size: Total bytes transferred from all valid requests
        status_codes: Dictionary mapping status codes to their counts

    Output:
        Prints statistics to stdout with format:
        File size: <total_size>
        <status_code>: <count> (sorted numerically)
    """
    print("File size: {}".format(total_size))
    for code in sorted([int(k) for k in status_codes.keys()]):
        print("{}: {}".format(code, status_codes[str(code)]))


def process_logs() -> None:
    """
    Main log processing function that:
    - Initializes tracking variables
    - Sets up signal handling
    - Processes input line by line
    - Prints statistics periodically
    - Handles interruptions gracefully
    """
    status_codes = {}  # Track counts of valid status codes
    total_size = 0     # Accumulate total bytes transferred
    count = 0          # Count processed lines for periodic output

    # Regular expression for valid log lines
    log_format = r'^\S+ - \[\S+ \S+\] "GET /projects/\d+ HTTP/\d\.\d" (\d{3}) (\d+)$'

    def signal_handler(sig: int, frame: object) -> None:
        """Handle keyboard interruption by printing stats before exiting."""
        print_stats(total_size, status_codes)
        sys.exit(0)

    # Register signal handler for CTRL+C
    signal.signal(signal.SIGINT, signal_handler)

    try:
        for line in fileinput.input():
            match = re.match(log_format, line)
            if match:
                # Extract status code and file size from regex groups
                status_code, file_size = match.groups()

                # Update status code counts
                if status_code in status_codes:
                    status_codes[status_code] += 1
                else:
                    status_codes[status_code] = 1

                # Update totals
                total_size += int(file_size)
                count += 1

                # Print stats every 10 valid lines
                if count % 10 == 0:
                    print_stats(total_size, status_codes)

    except KeyboardInterrupt:
        # Handle CTRL+C during processing
        print_stats(total_size, status_codes)
        sys.exit(0)

    # Print final stats if we reach EOF without interruption
    print_stats(total_size, status_codes)


if __name__ == "__main__":
    process_logs()
