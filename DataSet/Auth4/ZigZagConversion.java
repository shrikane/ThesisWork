package zigzag_conversion;

public class ZigZagConversion {

    public class Solution {
        public String convert(String s, int nRows) {
            assert nRows >= 1;
            if (nRows == 1) {
                return s;
            }
            String ans = "";
            for (int j = 0; j < nRows; j++) {
                for (int i = 0; i + j < s.length(); i += 2 * (nRows - 1)) {
                    ans += s.charAt(i + j);
                    if (j == 0 || j == nRows - 1) {
                        continue;
                    }
                    int anotherIndex = i + j + (nRows - j - 1) * 2;
                    if (anotherIndex < s.length()) {
                        ans += s.charAt(anotherIndex);
                    }
                }
            }
            return ans;
        }
    }

    public static class UnitTest {

    }
}
