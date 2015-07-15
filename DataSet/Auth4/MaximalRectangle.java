package maximal_rectangle;

import java.util.ArrayDeque;

public class MaximalRectangle {

    public class Solution {
        private int largestRectangleArea(int[] height) {
            ArrayDeque<Integer> p = new ArrayDeque<Integer>();
            int i = 0;
            int maxArea = 0;
            while (i < height.length) {
                if (p.isEmpty() || height[p.peekLast()] <= height[i]) {
                    p.offerLast(i++);
                } else {
                    int pos = p.removeLast();
                    maxArea = Math.max(maxArea, height[pos]
                            * (p.isEmpty() ? i : (i - p.peekLast() - 1)));
                }
            }
            return maxArea;
        }

        public int maximalRectangle(char[][] matrix) {
            if (matrix.length == 0 || matrix[0].length == 0) {
                return 0;
            }
            int m = matrix.length;
            int n = matrix[0].length;
            int[] height = new int[n + 1];
            int maxArea = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][j] == '1') {
                        height[j]++;
                    } else {
                        height[j] = 0;
                    }
                }
                maxArea = Math.max(maxArea, largestRectangleArea(height));
            }
            return maxArea;
        }
    }

    public static class UnitTest {

    }
}
