def print_sol(board):
    for row in board:
        print(' '.join(map(str, row)))

def is_safe(row, col, rows, left_diagonals, right_diagonals):
    if rows[row] or left_diagonals[row + col] or right_diagonals[col - row + N - 1]:
        return False
    return True

def solve(board, col, rows, left_diagonals, right_diagonals):
    if col >= N:
        return True
    for i in range(N):
        if is_safe(i, col, rows, left_diagonals, right_diagonals):
            rows[i] = True
            left_diagonals[i + col] = True
            right_diagonals[col - i + N - 1] = True
            board[i][col] = 1

            if solve(board, col + 1, rows, left_diagonals, right_diagonals):
                return True
            
            rows[i] = False
            left_diagonals[i + col] = False
            right_diagonals[col - i + N - 1] = False
            board[i][col] = 0

    return False

if __name__ == "__main__":
    N = int(input("Enter the number of rows for the square board: "))
    
    # Take the position for the first queen as input
    first_row = int(input("Enter the row position of the first queen (0-based index): "))
    first_col = int(input("Enter the column position of the first queen (0-based index): "))

    board = [[0] * N for _ in range(N)]
    rows = [False] * N
    left_diagonals = [False] * (2 * N - 1)
    right_diagonals = [False] * (2 * N - 1)

    # Place the first queen and update the tracking arrays
    board[first_row][first_col] = 1
    rows[first_row] = True
    left_diagonals[first_row + first_col] = True
    right_diagonals[first_col - first_row + N - 1] = True

    # Start solving from the next column after the initial position of the first queen
    ans = solve(board, first_col + 1, rows, left_diagonals, right_diagonals)

    if ans:
        print_sol(board)
    else:
        print("Solution does not exist")
