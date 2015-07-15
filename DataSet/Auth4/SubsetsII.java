package subsets_ii;

import java.util.ArrayList;
import java.util.Arrays;

public class SubsetsII {

    public class Solution {
        public ArrayList<ArrayList<Integer>> subsetsWithDup(int[] num) {
            Arrays.sort(num);
            ArrayList<ArrayList<Integer>> subsets = new ArrayList<ArrayList<Integer>>();
            subsets.add(new ArrayList<Integer>());
            int last = 1;
            for (int i = 0; i < num.length; i++) {
                int start = 0;
                if (i != 0 && num[i] == num[i - 1]) {
                    start = last;
                }
                last = subsets.size();
                for (int j = start; j < last; j++) {
                    ArrayList<Integer> subset = new ArrayList<Integer>(
                            subsets.get(j));
                    subset.add(num[i]);
                    subsets.add(subset);
                }
            }
            return subsets;
        }
    }

    public static class UnitTest {

    }
}
