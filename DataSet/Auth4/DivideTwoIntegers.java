package divide_two_integers;

import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class DivideTwoIntegers {

    public class Solution {
        // Try to implement without long
        public int divide(int dividend, int divisor) {
            if (divisor == 0) {
                throw new IllegalArgumentException("divisor is 0");
            }
            if (divisor == Integer.MIN_VALUE) {
                return dividend == Integer.MIN_VALUE ? 1 : 0;
            }
            boolean negative = (dividend > 0) ^ (divisor > 0);
            divisor = Math.abs(divisor);
            boolean overflow = dividend == Integer.MIN_VALUE;
            if (overflow) {
                dividend += divisor;
            }
            dividend = Math.abs(dividend);
            int pow = divisor;
            while ((pow << 1) > 0 && dividend >= (pow << 1)) {
                pow <<= 1;
            }
            int ans = 0;
            while (pow >= divisor) {
                ans <<= 1;
                if (dividend >= pow) {
                    dividend -= pow;
                    ans += 1;
                }
                pow >>= 1;
            }
            if (overflow) {
                ans += 1;
            }
            return negative ? -ans : ans;
        }
    }

    public static class UnitTest {
        @Test
        public void testDivideWithOverflow() {
            Solution s = new DivideTwoIntegers().new Solution();
            assertEquals(Integer.MIN_VALUE, s.divide(Integer.MIN_VALUE, 1));
        }
    }
}
