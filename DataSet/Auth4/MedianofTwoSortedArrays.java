package median_of_two_sorted_arrays;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class MedianofTwoSortedArrays {

    public class Solution {

        private int findKth(int A[], int m, int B[], int n, int k) {
            if (m == 0) {
                return B[k - 1];
            }
            if (n == 0) {
                return A[k - 1];
            }
            if (m + n == k) {
                return Math.max(A[m - 1], B[n - 1]);
            }
            if (m > n) {
                return findKth(B, n, A, m, k);
            }
            int x = Math.min(m, k / 2 + 1);
            int y = k + 1 - x;
            if (A[x - 1] < B[y - 1]) {
                return findKth(A, m, B, y - 1, k);
            } else if (A[x - 1] > B[y - 1]) {
                return findKth(A, x - 1, B, n, k);
            } else {
                return A[x - 1];
            }
        }

        public double findMedianSortedArrays(int A[], int B[]) {
            int n = A.length + B.length;
            if (n % 2 == 1) {
                return findKth(A, A.length, B, B.length, n / 2 + 1);
            }
            return (findKth(A, A.length, B, B.length, n / 2) +
                    findKth(A, A.length, B, B.length, n / 2 + 1)) / 2.0;
        }
    }

    public static class UnitTest {

        @Test
        public void testFindMedianSortedArrays() {
            Solution s = new MedianofTwoSortedArrays().new Solution();
            assertEquals(2.5, s.findMedianSortedArrays(new int[]{3, 4}, new int[]{1, 2}), 1E-6);
        }
    }
}
