package first_missing_positive;

public class FirstMissingPositive {

    public class Solution {
        public int firstMissingPositive(int[] A) {
            int n = A.length;
            for (int i = 0; i < n; i++) {
                if (A[i] <= 0) {
                    A[i] = n + 1;
                }
            }
            for (int i = 0; i < n; i++) {
                int temp = Math.abs(A[i]);
                if (temp <= n && A[temp - 1] > 0) {
                    A[temp - 1] = -A[temp - 1];
                }
            }
            for (int i = 0; i < n; i++) {
                if (A[i] > 0) {
                    return i + 1;
                }
            }
            return n + 1;
        }
    }

    public static class UnitTest {

    }
}
