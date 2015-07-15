package spiral_matrix_ii;

public class SpiralMatrixII {

    public class Solution {
        public int[][] generateMatrix(int n) {
            int[][] matrix = new int[n][n];
            int num = 0;
            int begin = 0;
            int end = n - 1;
            while (begin <= end) {
                for (int i = begin; i <= end; i++) {
                    matrix[begin][i] = ++num;
                }
                for (int i = begin + 1; i < end; i++) {
                    matrix[i][end] = ++num;
                }
                if (begin != end) {
                    for (int i = end; i >= begin; i--) {
                        matrix[end][i] = ++num;
                    }
                    for (int i = end - 1; i > begin; i--) {
                        matrix[i][begin] = ++num;
                    }
                }
                begin++;
                end--;
            }
            return matrix;
        }
    }

    public static class UnitTest {

    }
}
