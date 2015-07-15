package pascals_triangle;

import java.util.ArrayList;

public class PascalsTriangle {

    public class Solution {
        public ArrayList<ArrayList<Integer>> generate(int numRows) {
            ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
            if (numRows == 0) {
                return ans;
            }
            ArrayList<Integer> lastRow = new ArrayList<Integer>();
            lastRow.add(1);
            ans.add(lastRow);
            for (int r = 2; r <= numRows; r++) {
                ArrayList<Integer> row = new ArrayList<Integer>();
                row.add(1);
                for (int j = 1; j <= r - 2; j++) {
                    row.add(lastRow.get(j - 1) + lastRow.get(j));
                }
                row.add(1);
                lastRow = row;
                ans.add(lastRow);
            }
            return ans;
        }
    }

    public static class UnitTest {

    }
}
