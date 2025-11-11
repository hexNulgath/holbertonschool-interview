# Pascal's Triangle

Description
- Generate Pascal's Triangle rows for a non-negative integer n.
- Typical outputs: the full triangle up to n rows or a single nth row.

Requirements
- Input: integer n (n >= 0).
- Output format: list of lists, arrays, or printed rows depending on implementation.

Usage examples

Generate full triangle (n = 5)
```
0: 1
1: 1 1
2: 1 2 1
3: 1 3 3 1
4: 1 4 6 4 1
```


Algorithm notes
- Each value is the sum of the two values above it.
- Time complexity: O(n^2) to build n rows.
- Space complexity: O(n^2) for full triangle; O(n) to compute a single row iteratively.

Testing
- Edge cases: n = 0 -> empty triangle; n = 1 -> [[1]].
- Validate with small n values and known sequences.
