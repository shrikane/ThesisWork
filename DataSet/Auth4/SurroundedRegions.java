package surrounded_regions;

import java.util.ArrayDeque;

public class SurroundedRegions {

    public class Solution {
        private class Pos {
            int x;
            int y;

            Pos(int x, int y) {
                this.x = x;
                this.y = y;
            }
        }

        private boolean isOutOfBound(int x, int y, int rows, int columns) {
            return x < 0 || y < 0 || x >= rows || y >= columns;
        }

        public void solve(char[][] board) {
            if (board.length == 0 || board[0].length == 0) {
                return;
            }
            int rows = board.length;
            int columns = board[0].length;

            ArrayDeque<Pos> stack = new ArrayDeque<Pos>();
            for (int i = 0; i < rows; i++) {
                stack.offerLast(new Pos(i, 0));
                stack.offerLast(new Pos(i, columns - 1));
            }
            for (int i = 0; i < columns; i++) {
                stack.offerLast(new Pos(0, i));
                stack.offerLast(new Pos(rows - 1, i));
            }

            while (!stack.isEmpty()) {
                Pos pos = stack.removeLast();
                int x = pos.x;
                int y = pos.y;
                if (isOutOfBound(x, y, rows, columns) || board[x][y] != 'O') {
                    continue;
                }
                board[x][y] = 'N';
                stack.offerLast(new Pos(x - 1, y));
                stack.offerLast(new Pos(x + 1, y));
                stack.offerLast(new Pos(x, y - 1));
                stack.offerLast(new Pos(x, y + 1));
            }

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    if (board[i][j] == 'O') {
                        board[i][j] = 'X';
                    } else if (board[i][j] == 'N') {
                        board[i][j] = 'O';
                    }
                }
            }
        }
    }

    public static class UnitTest {

    }
}
