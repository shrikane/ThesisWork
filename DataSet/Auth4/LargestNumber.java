package largest_number;

import java.util.Arrays;
import java.util.Comparator;

public class LargestNumber {

    public class Solution {

        private int skipLendingZeros(String s) {
            int i = 0;
            for (; i < s.length(); i++) {
                if (s.charAt(i) != '0') {
                    return i;
                }
            }
            return i;
        }

        public String largestNumber(int[] num) {
            String[] nums = new String[num.length];
            for (int i = 0; i < nums.length; i++) {
                nums[i] = Integer.toString(num[i]);
            }
            Arrays.sort(nums, new Comparator<String>() {
                @Override
                public int compare(String s1, String s2) {
                    return -(s1 + s2).compareTo(s2 + s1);
                }
            });
            StringBuilder builder = new StringBuilder();
            boolean skip = true;
            for (String n : nums) {
                if (skip) {
                    int start = skipLendingZeros(n);
                    if (start != n.length()) {
                        skip = false;
                        builder.append(n, start, n.length());
                    }
                } else {
                    builder.append(n);
                }
            }
            String r = builder.toString();
            return r.isEmpty() ? "0" : r;
        }
    }

    public static class UnitTest {

    }
}

