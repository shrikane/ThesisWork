package subsets;

import java.util.ArrayList;
import java.util.Arrays;

public class Subsets {

    public class Solution {
        public ArrayList<ArrayList<Integer>> subsets(int[] S) {
            Arrays.sort(S);
            ArrayList<ArrayList<Integer>> subsets = new ArrayList<ArrayList<Integer>>();
            for (int i = 0; i < 1 << S.length; i++) {
                ArrayList<Integer> subset = new ArrayList<Integer>();
                int n = i;
                int idx = 0;
                while (n > 0) {
                    if ((n & 1) == 1) {
                        subset.add(S[idx]);
                    }
                    n >>= 1;
                    idx++;
                }
                subsets.add(subset);
            }
            return subsets;
        }
    }

    public static class UnitTest {

    }
}
