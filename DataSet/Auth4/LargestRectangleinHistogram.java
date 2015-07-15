package largest_rectangle_in_histogram;

import java.util.ArrayDeque;
import java.util.Deque;

public class LargestRectangleinHistogram {

    public class Solution {
        public int largestRectangleArea(int[] height) {
            int maxArea = 0;
            Deque<Integer> p = new ArrayDeque<Integer>();
            int i = 0;
            while (i < height.length) {
                if (p.isEmpty() || height[p.peekLast()] <= height[i]) {
                    p.offerLast(i++);
                } else {
                    int pos = p.removeLast();
                    maxArea = Math.max(maxArea,
                            (p.isEmpty() ? i : i - p.peekLast() - 1)
                                    * height[pos]);
                }
            }
            while (!p.isEmpty()) {
                int pos = p.removeLast();
                maxArea = Math.max(maxArea, (p.isEmpty() ? i : i - p.peekLast()
                        - 1)
                        * height[pos]);
            }
            return maxArea;
        }
    }

    public static class UnitTest {
    }
}
