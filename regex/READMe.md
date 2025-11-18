# regex

Simple C implementation of a regular-expression matcher.

## Overview
This repository contains a C implementation of a small regex matcher and an example program. The matcher is intended to handle a common subset of regex features suitable for interview exercises and unit tests.

## Features
- Function API: `int regex_match(const char *text, const char *pattern);`
- Typical supported features:
    - Literal characters
    - `.` matches any single character
    - `*` zero-or-more repetition of the preceding element

Return value: non-zero for a match, `0` for no match.

## Build
Compile the example program or the source file with:
```
gcc -Wall -Wextra -Werror -pedantic main.c regex.c
```
