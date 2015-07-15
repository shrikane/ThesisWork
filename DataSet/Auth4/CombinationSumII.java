package combination_sum_ii;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CombinationSumII {

    public class Solution {
        private void search(List<Integer> nums, List<Integer> counts,
                int index, int target, ArrayDeque<Integer> s,
                ArrayList<ArrayList<Integer>> ans) {
            if (target == 0) {
                ans.add(new ArrayList<Integer>(s));
            }
            if (target <= 0 || index == nums.size()) {
                return;
            }
            int n = nums.get(index);
            int count = counts.get(index);
            for (int i = 0; i <= count; i++) {
                search(nums, counts, index + 1, target - i * n, s, ans);
                s.offerLast(n);
            }
            for (int i = 0; i <= count; i++) {
                s.removeLast();
            }
        }

        public ArrayList<ArrayList<Integer>> combinationSum2(int[] num,
                int target) {
            ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
            if (num.length == 0) {
                return ans;
            }
            Arrays.sort(num);
            List<Integer> nums = new ArrayList<Integer>();
            List<Integer> counts = new ArrayList<Integer>();
            int count = 1;
            int i = 1;
            for (; i < num.length; i++) {
                if (num[i] != num[i - 1]) {
                    nums.add(num[i - 1]);
                    counts.add(count);
                    count = 1;
                } else {
                    count++;
                }

            }
            nums.add(num[i - 1]);
            counts.add(count);
            search(nums, counts, 0, target, new ArrayDeque<Integer>(), ans);
            return ans;
        }
    }

    public static class UnitTest {

    }
}
