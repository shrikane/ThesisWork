package longest_consecutive_sequence;

import java.util.HashSet;

public class LongestConsecutiveSequence {

    public class Solution {
        public int longestConsecutive(int[] num) {
            HashSet<Integer> nums = new HashSet<Integer>();
            for (int n : num) {
                nums.add(n);
            }
            int ans = 0;
            for (int n : num) {
                int i = n - 1;
                while (nums.contains(i)) {
                    nums.remove(i);
                    i--;
                }
                int j = n + 1;
                while (nums.contains(j)) {
                    nums.remove(j);
                    j++;
                }
                ans = Math.max(ans, j - i - 1);
            }
            return ans;
        }
    }

    public static class UnitTest {

    }
}
