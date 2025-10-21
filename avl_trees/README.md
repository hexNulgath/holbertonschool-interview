# avl_trees

Small collection of AVL tree utilities used for Holberton School interview tasks. Contains functions to create, insert, remove and navigate balanced binary search trees in C.

## Contents
- Source files (.c) implementing AVL behavior
- Header(s) (.h) with node/type definitions and function prototypes
- Example main for quick manual tests

## Requirements
- GCC (or compatible C compiler)
- POSIX-compatible shell (for build/test commands)

## Build
Compile sources with recommended flags:
```
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o avl_test
```
Or provide a Makefile target:
```
make
```

## Usage
Include the project header and link the compiled objects:
```c
#include "avl.h"  /* or binary_trees.h */

avl_t *root = NULL;
root = avl_insert(root, 42);
root = avl_insert(root, 27);
/* use traversal helpers to verify balance */
```

## Testing
Run the provided example or unit tests:
```
./avl_test
```