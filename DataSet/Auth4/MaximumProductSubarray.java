package maximum_product_subarray;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class MaximumProductSubarray {

    public class Solution {
        public int maxProduct(int[] A) {
            assert A.length != 0;
            int globalMax = A[0];
            int prevMax = A[0];
            int prevMin = A[0];
            for (int i = 1; i < A.length; i++) {
                int max;
                int min;
                if (A[i] > 0) {
                    max = Math.max(A[i], prevMax * A[i]);
                    min = Math.min(A[i], prevMin * A[i]);
                } else {
                    max = Math.max(A[i], prevMin * A[i]);
                    min = Math.min(A[i], prevMax * A[i]);
                }
                globalMax = Math.max(globalMax, max);
                prevMax = max;
                prevMin = min;
            }
            return globalMax;
        }
    }

    public static class UnitTest {

        @Test
        public void testMaxProduct() {
            Solution s = new MaximumProductSubarray().new Solution();
            assertEquals(12, s.maxProduct(new int[]{-4, -3, -2}));
        }
    }
}

