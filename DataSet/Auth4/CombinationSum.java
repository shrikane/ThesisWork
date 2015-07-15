package combination_sum;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;

public class CombinationSum {

    public class Solution {
        private void search(int[] n, int index, int target,
                ArrayDeque<Integer> s, ArrayList<ArrayList<Integer>> ans) {
            if (target == 0) {
                ans.add(new ArrayList<Integer>(s));
                return;
            }
            if (index == n.length || target < n[index]) {
                return;
            }

            for (int i = 0; i <= target / n[index]; i++) {
                search(n, index + 1, target - i * n[index], s, ans);
                s.offerLast(n[index]);
            }
            for (int i = 0; i <= target / n[index]; i++) {
                s.removeLast();
            }
        }

        public ArrayList<ArrayList<Integer>> combinationSum(int[] candidates,
                int target) {
            ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
            Arrays.sort(candidates);
            search(candidates, 0, target, new ArrayDeque<Integer>(), ans);
            return ans;
        }
    }

    public static class UnitTest {

    }
}
