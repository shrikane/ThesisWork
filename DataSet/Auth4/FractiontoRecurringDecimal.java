package fraction_to_recurring_decimal;

import org.junit.Test;

import java.util.ArrayList;

import static org.junit.Assert.assertEquals;

public class FractiontoRecurringDecimal {

    public class Solution {

        private String fraction(long mod, long divider) {
            ArrayList<Long> mods = new ArrayList<Long>();
            mods.add(mod);
            ArrayList<Long> remainders = new ArrayList<Long>();
            int i;
            while (true) {
                mod *= 10;
                remainders.add(mod / divider);
                mod = mod % divider;
                if (mod == 0) {
                    i = -1;
                    break;
                }
                i = mods.indexOf(mod);
                if (i >= 0) {
                    break;
                }
                mods.add(mod);
            }
            StringBuilder builder = new StringBuilder();
            if (i < 0) {
                for (long r : remainders) {
                    builder.append(r);
                }
            } else {
                int j = 0;
                for (; j < i; j++) {
                    builder.append(remainders.get(j));
                }
                builder.append('(');
                for (; j < remainders.size(); j++) {
                    builder.append(remainders.get(j));
                }
                builder.append(')');
            }
            return builder.toString();
        }

        public String fractionToDecimal(int numerator, int denominator) {
            boolean negative = (numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0);
            long num = Math.abs((long) numerator);
            long denom = Math.abs((long) denominator);
            long remainder = num / denom;
            long mod = num % denom;
            if (mod == 0) {
                if (negative) {
                    return "-" + remainder;
                } else {
                    return Long.toString(remainder);
                }
            } else {
                if (negative) {
                    return "-" + remainder + "." + fraction(mod, denom);
                } else {
                    return remainder + "." + fraction(mod, denom);
                }
            }

        }
    }

    public static class UnitTest {

        @Test
        public void testFractionToDecimal() {
            Solution s = new FractiontoRecurringDecimal().new Solution();
            assertEquals("3.(3)", s.fractionToDecimal(10, 3));
            assertEquals("0.75", s.fractionToDecimal(3, 4));
            assertEquals("0.(09)", s.fractionToDecimal(1, 11));
            assertEquals("0.0000000004656612873077392578125", s.fractionToDecimal(-1, -2147483648));
        }
    }
}

