package n_queens_ii;

public class NQueensII {

    public class Solution {
        private int search(int row, int lDiag, int rDiag, int upper) {
            if (row == upper) {
                return 1;
            }
            int count = 0;
            int allow = upper & ~(row | lDiag | rDiag);
            while (allow != 0) {
                int pos = (-allow) & allow;
                count += search(row + pos, (lDiag + pos) >> 1,
                        (rDiag + pos) << 1, upper);
                allow = allow - pos;
            }
            return count;
        }

        public int totalNQueens(int n) {
            return search(0, 0, 0, (1 << n) - 1);
        }
    }

    public static class UnitTest {

    }
}
