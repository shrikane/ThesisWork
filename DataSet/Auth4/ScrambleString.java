package scramble_string;

public class ScrambleString {

    public class Solution {
        public boolean isScramble(String s1, String s2) {
            if (s1.equals(s2)) {
                return true;
            }
            int len = s1.length();
            boolean[][][] dp = new boolean[len][len][len + 1];
            for (int i = 0; i < len; i++) {
                for (int j = 0; j < len; j++) {
                    dp[i][j][1] = s1.charAt(i) == s2.charAt(j);
                }
            }

            for (int l = 2; l <= len; l++) {
                for (int i = 0; i <= len - l; i++) {
                    for (int j = 0; j <= len - l; j++) {
                        for (int p = 1; p < l; p++) {
                            if ((dp[i][j][p] && dp[i + p][j + p][l - p])
                                    || (dp[i][j + l - p][p] && dp[i + p][j][l
                                            - p])) {
                                dp[i][j][l] = true;
                                break;
                            }
                        }
                    }
                }
            }
            return dp[0][0][len];
        }
    }

    public static class UnitTest {

    }
}
