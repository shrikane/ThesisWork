package _3sum_closest;

import java.util.Arrays;

public class _3SumClosest {

    public class Solution {
        public int threeSumClosest(int[] num, int target) {
            Arrays.sort(num);
            int minSum = num[0] + num[1] + num[2];
            for (int i = 0; i < num.length - 2; i++) {
                if (i > 0 && num[i] == num[i - 1]) {
                    continue;
                }
                int twoSum = target - num[i];
                int begin = i + 1;
                int end = num.length - 1;
                while (begin < end) {
                    int sum = num[begin] + num[end];
                    if (Math.abs(twoSum - sum) < Math.abs(target - minSum)) {
                        minSum = sum + num[i];
                    }
                    if (sum < twoSum) {
                        begin++;
                    } else if (sum > twoSum) {
                        end--;
                    } else {
                        return target;
                    }
                }
            }
            return minSum;
        }
    }

    public static class UnitTest {

    }
}
