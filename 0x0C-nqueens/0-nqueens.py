#!/usr/bin/python3
"""
N-queens problem solve with backtracking algorithm
so that no queen can attack another.
"""

import sys


def backtracking(n, row, board):
    """
    Method: uses a recursive backtracking algorithm -
            places N queens on a N*N chessboard
            satisfying the constraint that
            no two queens should be in the same row,
            same column, or in same diagonal.
    Parameters: n is the size of the chessboard
                and number of queens to be placed
                r is the row that we are currently placing a queen on.
                Board is a list of lists that holds all positions of queens
                already placed on the board.
    Return: All possible solutions to
            placement, in a list of lists
    """
    for col in range(n):
        x = 0
        for q in board:
            if col == q[1]:
                x = 1
                break
            if row - col == q[0] - q[1]:
                x = 1
                break
            if col - q[1] == q[0] - row:
                x = 1
                break
        if x == 0:
            board.append([row, col])
            if row != n - 1:
                backtracking(n, row + 1, board)
            else:
                print(board)
            del board[-1]


def main():
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    try:
        n = int(sys.argv[1])
    except Exception:
        print('N must be a number')
        sys.exit(1)
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    backtracking(n, 0, [])


if __name__ == '__main__':
    main()
