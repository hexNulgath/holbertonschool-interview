# Island Perimeter

## Description

This project contains a Python function that calculates the perimeter of an island represented in a 2D grid. The function analyzes a grid where land is represented by `1` and water is represented by `0`, then computes the total perimeter of the island.

## Problem Statement

Given a 2D grid representing a map where:
- `0` represents water
- `1` represents land
- Each cell is a square with side length of 1
- Cells are connected horizontally/vertically (not diagonally)
- The grid is rectangular with width and height not exceeding 100
- The grid is completely surrounded by water
- There is only one island (or no island at all)
- The island doesn't have "lakes" (water inside that isn't connected to the surrounding water)

Calculate and return the perimeter of the island.

## Algorithm

The solution works by:

1. Iterating through each cell in the grid
2. For each land cell (`1`), initially adding 4 to the perimeter (assuming all sides are exposed)
3. Checking adjacent cells (top and left) to see if they are also land
4. If an adjacent cell is land, subtracting 2 from the perimeter (since that shared edge doesn't contribute to the perimeter)

This approach efficiently calculates the perimeter by only checking each potential shared edge once.

## Files

- `0-island_perimeter.py`: Contains the main `island_perimeter()` function
- `0-main.py`: Test file with example usage
- `README.md`: This documentation file

## Usage

```python
#!/usr/bin/python3
from island_perimeter import island_perimeter

# Example grid
grid = [
    [0, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 1, 1, 0, 0],
    [0, 0, 0, 0, 0, 0]
]

perimeter = island_perimeter(grid)
print(perimeter)  # Output: 12
```

## Function Signature

```python
def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid.
    
    Args:
        grid (list of list of int): 2D grid where 0 = water, 1 = land
        
    Returns:
        int: The perimeter of the island
    """
```

## Example

For the test case in `0-main.py`:

```
Grid visualization:
[0, 0, 0, 0, 0, 0]
[0, 1, 0, 0, 0, 0]  ← Single land cell
[0, 1, 0, 0, 0, 0]  ← Connected below
[0, 1, 1, 1, 0, 0]  ← L-shaped continuation
[0, 0, 0, 0, 0, 0]

Perimeter calculation:
- Total land cells: 5
- Each cell contributes 4 edges initially: 5 × 4 = 20
- Shared edges to subtract: 4 connections × 2 = 8
- Final perimeter: 20 - 8 = 12
```

## Running the Code

To test the function:

```bash
python3 0-main.py
```

Expected output: `12`

## Time Complexity

- **Time Complexity**: O(m × n) where m is the number of rows and n is the number of columns
- **Space Complexity**: O(1) - only using a constant amount of extra space

## Requirements

- Python 3.x
- No external dependencies required
