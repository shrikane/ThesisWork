package plus_one;

public class PlusOne {

    public class Solution {
        public int[] plusOne(int[] digits) {
            int carry = 1;
            for (int i = digits.length - 1; i >= 0; i--) {
                int sum = digits[i] + carry;
                carry = sum / 10;
                digits[i] = sum % 10;
            }
            if (carry == 1) {
                int[] re = new int[digits.length + 1];
                System.arraycopy(digits, 0, re, 1, digits.length);
                re[0] = 1;
                return re;
            } else {
                return digits;
            }
        }
    }

    public static class UnitTest {

    }
}
