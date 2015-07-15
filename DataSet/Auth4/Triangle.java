package triangle;

import java.util.ArrayList;
import java.util.Collections;

public class Triangle {

    public class Solution {
        public int minimumTotal(ArrayList<ArrayList<Integer>> triangle) {
            ArrayList<Integer> sum = new ArrayList<Integer>();
            if (triangle.isEmpty()) {
                return 0;
            }
            sum.add(triangle.get(0).get(0));
            for (int i = 1; i < triangle.size(); i++) {
                sum.add(triangle.get(i).get(i) + sum.get(i - 1));
                for (int j = i - 1; j >= 1; j--) {
                    sum.set(j, Math.min(sum.get(j - 1), sum.get(j))
                            + triangle.get(i).get(j));
                }
                sum.set(0, sum.get(0) + triangle.get(i).get(0));
            }
            return Collections.min(sum);
        }
    }

    public static class UnitTest {

    }
}
