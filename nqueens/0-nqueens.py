#!/usr/bin/python3
"""
0-nqueens.py - Solve the N-Queens problem using backtracking.
"""
import sys

def nqueen(N):
    """
    Solve the N-Queens problem using backtracking.
    """
    def is_safe(board, row, col, n):
        """
        Check if it's safe to place a queen at board[row][col]
        """
        # Check this row on left side
        for i in range(col):
            if board[row][i] == 1:
                return False
        
        # Check upper diagonal on left side
        for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
            if board[i][j] == 1:
                return False
        
        # Check lower diagonal on left side
        for i, j in zip(range(row, n, 1), range(col, -1, -1)):
            if board[i][j] == 1:
                return False
        
        return True

    def solve_nqueen(board, col, n, solutions):
        """
        Utility function to solve N Queens problem
        """
        # Base case: If all queens are placed
        if col >= n:
            solution = []
            for i in range(n):
                for j in range(n):
                    if board[i][j] == 1:
                        solution.append([i, j])
            solutions.insert(0, solution)
            solutions.sort(key=lambda x: (x[0][0], x[0][1]))
            return True
        
        res = False
        # Consider this column and try placing this queen in all rows one by one
        for i in range(n):
            if is_safe(board, i, col, n):
                # Place this queen in board[i][col]
                board[i][col] = 1
                
                # Make result true if any placement is possible
                res = solve_nqueen(board, col + 1, n, solutions) or res
                
                # If placing queen in board[i][col] doesn't lead to a solution,
                # then remove queen from board[i][col]
                board[i][col] = 0
        
        return res

    board = [[0 for _ in range(N)] for _ in range(N)]
    solutions = []
    solve_nqueen(board, 0, N, solutions)
    return solutions

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    
    try:
        N = int(sys.argv[1])
        if N < 1:
            raise ValueError
    except ValueError:
        print("N must be a positive integer.")
        sys.exit(1)

    solutions = nqueen(N)
    for solution in solutions:
        print(solution)
