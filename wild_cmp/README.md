
# wild_cmp

Simple C project that implements `wildcmp`, a function to compare two
strings where the second string may contain the wildcard `*` which matches
any sequence of characters (including the empty sequence).

## Files

- `0-wildcmp.c` - implementation of `wildcmp` with a recursive algorithm.
- `0-main.c` - sample main used to test the function (example usage).
- `holberton.h` - header declaring the `wildcmp` prototype.

## Function contract

- Prototype: `int wildcmp(char *s1, char *s2);`
- Inputs: two null-terminated strings `s1` and `s2`.
- Behavior: `s2` may contain `*` wildcards. Each `*` can match any
	sequence of characters (including zero characters).
- Return: `1` when the strings can be considered identical taking wildcards
	into account, otherwise `0`.

Edge cases handled by the implementation:

- Both strings empty -> match (returns 1).
- `*` at end of `s2` can match empty remainder of `s1`.
- Multiple `*` and overlapping matches are resolved by recursion.

## Build

Compile the sample main and the implementation using GCC with recommended
flags (treat warnings as errors):

```bash
gcc -Wall -Wextra -Werror 0-main.c 0-wildcmp.c -o 0-wildcmp
```

## Run

After building, run the produced executable:

```bash
./0-wildcmp
```

Sample output (from the repository test run):

```
1
1
1
1
1
1
1
0
1
1
0
0
```
