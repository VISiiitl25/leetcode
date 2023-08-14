class Solution {
public:
    bool matrixFound = false;

    bool isValid(int num, int row, int col, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num + '0' || board[i][col] == num + '0') {
                return false;
            }
        }

        int startRow = row / 3 * 3;
        int startCol = col / 3 * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == num + '0') {
                    return false;
                }
            }
        }

        return true;
    }

    void solveSudokuHelper(vector<vector<char>>& board, int row, int col) {
        if (matrixFound) return;
        
        if (row == 9) {
            matrixFound = true;
            return;
        }

        if (col == 9) {
            solveSudokuHelper(board, row + 1, 0);
            return;
        }

        if (board[row][col] != '.') {
            solveSudokuHelper(board, row, col + 1);
            if (matrixFound) return;
        }
        else {
            for (int num = 1; num <= 9; num++) {
                if (isValid(num, row, col, board)) {
                    board[row][col] = num + '0';
                    solveSudokuHelper(board, row, col + 1);
                    if (matrixFound) return;
                    board[row][col] = '.';
                }
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuHelper(board, 0, 0);
    }
};
