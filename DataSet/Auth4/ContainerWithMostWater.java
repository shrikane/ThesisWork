package container_with_most_water;

public class ContainerWithMostWater {

    public class Solution {
        public int maxArea(int[] height) {
            int maxArea = 0;
            int start = 0;
            int end = height.length - 1;
            while (start < end) {
                if (height[start] < height[end]) {
                    maxArea = Math.max(maxArea, (end - start) * height[start]);
                    start++;
                } else {
                    maxArea = Math.max(maxArea, (end - start) * height[end]);
                    end--;
                }
            }
            return maxArea;
        }
    }

    public static class UnitTest {

    }
}
