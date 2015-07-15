package sudoku_solver;

public class SudokuSolver {

    public class Solution {
        private boolean isValid(char[][] board, int row, int column, char c) {
            int cellRow = row - row % 3;
            int cellColumn = column - column % 3;
            for (int i = 0; i < 9; i++) {
                if (board[i][column] == c || board[row][i] == c
                        || board[cellRow + i / 3][cellColumn + i % 3] == c) {
                    return false;
                }
            }
            return true;
        }

        private boolean search(char[][] board, int pos) {
            while (pos < 81) {
                if (board[pos / 9][pos % 9] == '.') {
                    break;
                }
                pos++;
            }
            if (pos == 81) {
                return true;
            }
            int row = pos / 9;
            int column = pos % 9;
            for (char c = '1'; c <= '9'; c++) {
                if (isValid(board, row, column, c)) {
                    board[row][column] = c;
                    if (search(board, pos + 1)) {
                        return true;
                    }
                }
            }
            board[row][column] = '.';
            return false;
        }

        public void solveSudoku(char[][] board) {
            search(board, 0);
        }
    }

    public static class UnitTest {

    }
}
