package n_queens;

import java.util.ArrayDeque;
import java.util.ArrayList;

public class NQueens {

    public class Solution {
        private boolean isValid(int row, int column, ArrayDeque<Integer> columns) {
            int r = 0;
            for (int c : columns) {
                if (c == column || Math.abs(c - column) == Math.abs(r - row)) {
                    return false;
                }
                r++;
            }
            return true;
        }

        private String[] toSolution(ArrayDeque<Integer> columns) {
            int n = columns.size();
            String[] s = new String[n];
            int row = 0;
            for (int column : columns) {
                String line = "";
                for (int i = 0; i < n; i++) {
                    if (i != column) {
                        line += '.';
                    } else {
                        line += 'Q';
                    }
                }
                s[row++] = line;
            }
            return s;
        }

        private void search(int row, int n, ArrayDeque<Integer> columns,
                ArrayList<String[]> ans) {
            if (row == n) {
                ans.add(toSolution(columns));
                return;
            }
            for (int i = 0; i < n; i++) {
                if (isValid(row, i, columns)) {
                    columns.offerLast(i);
                    search(row + 1, n, columns, ans);
                    columns.removeLast();
                }
            }
        }

        public ArrayList<String[]> solveNQueens(int n) {
            ArrayList<String[]> ans = new ArrayList<String[]>();
            search(0, n, new ArrayDeque<Integer>(), ans);
            return ans;
        }
    }

    public static class UnitTest {

    }
}
