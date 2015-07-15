package majority_element;

public class MajorityElement {

    public class Solution {
        public int majorityElement(int[] num) {
            int majority = num[0];
            int count = 1;
            for (int i = 1; i < num.length; i++) {
                if (majority != num[i]) {
                    count--;
                    if (count == 0) {
                        // the majority element always exist in the array
                        majority = num[++i];
                        count = 1;
                    }
                } else {
                    count++;
                }
            }
            return majority;
        }
    }

    public static class UnitTest {

    }
}

