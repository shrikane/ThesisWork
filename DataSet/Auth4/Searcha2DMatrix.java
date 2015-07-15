package search_a_2d_matrix;

public class Searcha2DMatrix {

    public class Solution {
        public boolean searchMatrix(int[][] matrix, int target) {
            if (matrix.length == 0 || matrix[0].length == 0) {
                return false;
            }
            int columns = matrix[0].length;
            int left = 0;
            int right = matrix.length * columns - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                int val = matrix[mid / columns][mid % columns];
                if (val < target) {
                    left = mid + 1;
                } else if (val > target) {
                    right = mid - 1;
                } else {
                    return true;
                }
            }
            return false;
        }
    }

    public static class UnitTest {

    }
}
