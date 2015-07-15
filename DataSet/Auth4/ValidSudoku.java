package valid_sudoku;

public class ValidSudoku {

    public class Solution {
        public boolean isValidSudoku(char[][] board) {
            boolean[][] rows = new boolean[9][9];
            boolean[][] columns = new boolean[9][9];
            boolean[][] cells = new boolean[9][9];
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] == '.') {
                        continue;
                    }
                    int num = board[i][j] - '1';
                    if (rows[i][num] || columns[j][num]
                            || cells[i / 3 * 3 + j / 3][num]) {
                        return false;
                    }
                    rows[i][num] = columns[j][num] = cells[i / 3 * 3 + j / 3][num] = true;
                }
            }
            return true;
        }
    }

    public static class UnitTest {

    }
}
