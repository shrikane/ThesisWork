package spiral_matrix;

import java.util.ArrayList;

public class SpiralMatrix {

    public class Solution {
        public ArrayList<Integer> spiralOrder(int[][] matrix) {
            ArrayList<Integer> ans = new ArrayList<Integer>();
            if (matrix.length == 0 || matrix[0].length == 0) {
                return ans;
            }
            int beginX = 0;
            int beginY = 0;
            int endX = matrix.length - 1;
            int endY = matrix[0].length - 1;
            while (beginX <= endX && beginY <= endY) {
                for (int i = beginY; i <= endY; i++) {
                    ans.add(matrix[beginX][i]);
                }
                for (int i = beginX + 1; i < endX; i++) {
                    ans.add(matrix[i][endY]);
                }
                if (beginX != endX) {
                    for (int i = endY; i >= beginY; i--) {
                        ans.add(matrix[endX][i]);
                    }
                }
                if (beginY != endY) {
                    for (int i = endX - 1; i > beginX; i--) {
                        ans.add(matrix[i][beginY]);
                    }
                }
                beginX++;
                endX--;
                beginY++;
                endY--;
            }
            return ans;
        }
    }

    public static class UnitTest {

    }
}
