package trapping_rain_water;

public class TrappingRainWater {

    public class Solution {
        public int trap(int[] A) {
            if (A.length == 0) {
                return 0;
            }
            int maxIndex = 0;
            for (int i = 1; i < A.length; i++) {
                if (A[i] > A[maxIndex]) {
                    maxIndex = i;
                }
            }
            int height = A[0];
            int water = 0;
            for (int i = 1; i < maxIndex; i++) {
                if (A[i] > height) {
                    height = A[i];
                } else {
                    water += height - A[i];
                }
            }
            height = A[A.length - 1];
            for (int i = A.length - 2; i > maxIndex; i--) {
                if (A[i] > height) {
                    height = A[i];
                } else {
                    water += height - A[i];
                }
            }
            return water;
        }
    }

    public static class UnitTest {

    }
}
