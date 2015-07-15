package _3sum;

import java.util.ArrayList;
import java.util.Arrays;

public class _3Sum {

    public class Solution {

        private ArrayList<Integer> makeTriplet(int a, int b, int c) {
            ArrayList<Integer> ans = new ArrayList<Integer>();
            ans.add(a);
            ans.add(b);
            ans.add(c);
            return ans;
        }

        private void twoSum(ArrayList<ArrayList<Integer>> ans, int a,
                int[] num, int begin) {
            int i = begin;
            int j = num.length - 1;
            while (i < j) {
                int sum = num[i] + num[j];
                if (sum < -a) {
                    i++;
                } else if (sum > -a) {
                    j--;
                } else {
                    ans.add(makeTriplet(a, num[i], num[j]));
                    do {
                        i++;
                    } while (i < j && num[i] == num[i - 1]);
                    do {
                        j--;
                    } while (i < j && num[j] == num[j + 1]);
                }
            }
        }

        public ArrayList<ArrayList<Integer>> threeSum(int[] num) {
            Arrays.sort(num);
            ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
            for (int i = 0; i < num.length - 2; i++) {
                if (i > 0 && num[i] == num[i - 1]) {
                    continue;
                }
                twoSum(ans, num[i], num, i + 1);
            }
            return ans;
        }
    }

    public static class UnitTest {

    }
}
