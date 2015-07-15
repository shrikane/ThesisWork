package single_number_ii;

public class SingleNumberII {

    public class Solution {
        public int singleNumber(int[] A) {
            int[] bits = new int[32];
            for (int a : A) {
                for (int i = 0; i < 32; i++) {
                    if ((a & (1 << i)) != 0) {
                        bits[i]++;
                    }
                }
            }
            int ans = 0;
            for (int i = 0; i < 32; i++) {
                if (bits[i] % 3 == 1) {
                    ans |= (1 << i);
                }
            }
            return ans;
        }
    }

    public static class UnitTest {

    }
}
