package integer_to_roman;

public class IntegertoRoman {

    public class Solution {

        private final char[] symbols = new char[] { 'M', 'D', 'C', 'L', 'X',
                'V', 'I' };

        private String repeat(char c, int times) {
            String re = "";
            for (int i = 0; i < times; i++) {
                re += c;
            }
            return re;
        }

        public String intToRoman(int num) {
            String roman = "";
            int scala = 1000;
            for (int i = 0; i < symbols.length; i += 2) {
                int digit = num / scala;
                num %= scala;
                scala /= 10;
                if (digit == 9) {
                    roman += symbols[i];
                    roman += symbols[i - 2];
                } else if (digit >= 5) {
                    roman += symbols[i - 1];
                    roman += repeat(symbols[i], digit - 5);
                } else if (digit == 4) {
                    roman += symbols[i];
                    roman += symbols[i - 1];
                } else {
                    roman += repeat(symbols[i], digit);
                }
            }
            return roman;
        }
    }

    public static class UnitTest {

    }
}
