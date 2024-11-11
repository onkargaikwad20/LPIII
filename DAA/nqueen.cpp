#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, int board[], int n) {
    for (int i = 0; i < row; ++i) {
        if (board[i] == col || abs(i - row) == abs(board[i] - col)) {
            return false;
        }
    }
    return true;
}

void printBoard(int board[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i] == j) {
                cout << "Q ";
            } else {
                cout << "_ ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void solveNQueensBacktracking(int row, int board[], int n, int& count) {
    if (row == n) {
        count++;
        cout << "Solution " << count << ":\n";
        printBoard(board, n);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(row, col, board, n)) {
            board[row] = col;
            solveNQueensBacktracking(row + 1, board, n, count);
            board[row] = -1; 
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the board (n): ";
    cin >> n;

    int board[n]; 
    int count = 0;

    
    for (int i = 0; i < n; ++i) {
        board[i] = -1;
    }

   
    int initialRow, initialCol;
    cout << "Enter the row (0 to " << n-1 << ") for the first queen: ";
    cin >> initialRow;
    cout << "Enter the column (0 to " << n-1 << ") for the first queen: ";
    cin >> initialCol;

    
    if (initialRow < 0 || initialRow >= n || initialCol < 0 || initialCol >= n) {
        cout << "Invalid position for the first queen.\n";
        return 1;
    }

    board[initialRow] = initialCol;

    cout << "\nBacktracking Solutions:\n";
    solveNQueensBacktracking(initialRow + 1, board, n, count); // Start from the next row

    if (count == 0) {
        cout << "No solutions found with the first queen placed at (" << initialRow << ", " << initialCol << ").\n";
    }
    return 0;
}