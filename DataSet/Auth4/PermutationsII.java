package permutations_ii;

import java.util.ArrayList;
import java.util.Arrays;

public class PermutationsII {

    public class Solution {
        private void swap(int[] num, int i, int j) {
            int temp = num[i];
            num[i] = num[j];
            num[j] = temp;
        }

        private void reverse(int[] num, int begin, int end) {
            end--;
            while (begin < end) {
                swap(num, begin++, end--);
            }
        }

        private boolean nextPermutation(int[] num) {
            if (num.length <= 1) {
                return false;
            }
            int i = num.length - 1;
            while (true) {
                i--;
                if (num[i] < num[i + 1]) {
                    int j = num.length;
                    while (num[i] >= num[--j]) {
                    }
                    swap(num, i, j);
                    reverse(num, i + 1, num.length);
                    return true;
                }
                if (i == 0) {
                    reverse(num, 0, num.length);
                    return false;
                }
            }
        }

        public ArrayList<ArrayList<Integer>> permuteUnique(int[] num) {
            Arrays.sort(num);
            ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
            do {
                ArrayList<Integer> l = new ArrayList<Integer>();
                for (int n : num) {
                    l.add(n);
                }
                ans.add(l);
            } while (nextPermutation(num));
            return ans;
        }
    }

    public static class UnitTest {

    }
}
