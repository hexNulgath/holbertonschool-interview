#!/usr/bin/python3
"""
Log Statistics Module

This module processes HTTP access logs in the exact format:
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>

It computes and prints statistics including:
- Total file size across all requests
- Count of each HTTP status code encountered

Statistics are printed:
1. Every 10 correctly formatted lines processed
2. On keyboard interruption (CTRL+C)
3. At end of input if no interruption occurs
"""

import sys
import signal
import re


def print_stats(total_size: int, status_codes: dict) -> None:
    """
    Print accumulated statistics in the required format.

    Args:
        total_size: Total bytes transferred from all valid requests
        status_codes: Dictionary of status codes and their counts

    Prints:
        File size: <total_size>
        Followed by status code counts in ascending numerical order
    """
    print(f"File size: {total_size}")
    for code in sorted(status_codes.keys()):
        print(f"{code}: {status_codes[code]}")


def process_logs() -> None:
    """
    Process log lines from stdin with strict format validation.

    Valid line format:
    <IP> - [<date>] "GET /projects/260 HTTP/1.1" <status> <size>

    Where:
    - IP: Valid IPv4 address
    - date: [YYYY-MM-DD HH:MM:SS.MICROS]
    - status: Valid HTTP status code
    - size: Positive integer
    """
    status_codes = {}
    total_size = 0
    line_count = 0

    # Strict regex pattern for input validation
    log_pattern = re.compile(
        r'.*?\b(?P<status>\d*)\s+(?P<size>[1-9]\d*)\s*$'
    )
    valid_status_pattern = re.compile(
        r'.*?\b(?P<status>200|301|400|401|403|404|405|500)\s+'
        r'(?P<size>[1-9]\d*)\s*$')

    def handle_interrupt(sig, frame):
        """Handle keyboard interrupt by printing stats before exiting."""
        print_stats(total_size, status_codes)
        sys.exit(0)

    signal.signal(signal.SIGINT, handle_interrupt)

    try:
        for line in sys.stdin:
            match = log_pattern.match(line.strip())
            if match:
                file_size = match.group('size')
                status_code = match.group('status')
                total_size += int(file_size)
                if valid_status_pattern.match(line.strip()):
                    status_codes[status_code] = status_codes.get(
                        status_code, 0) + 1
                line_count += 1

                if line_count % 10 == 0:
                    print_stats(total_size, status_codes)

    except KeyboardInterrupt:
        print_stats(total_size, status_codes)
        raise

    print_stats(total_size, status_codes)


if __name__ == "__main__":
    process_logs()
