package regular_expression_matching;


public class RegularExpressionMatching {

    public class Solution {
        public boolean isMatch(String s, String p) {
            boolean[][] dp = new boolean[p.length() + 1][s.length() + 1];
            dp[0][0] = true;
            for (int i = 1; i <= p.length(); i++) {
                dp[i][0] = p.charAt(i - 1) == '*' && dp[i - 2][0];
                for (int j = 1; j <= s.length(); j++) {
                    if (p.charAt(i - 1) == '*') {
                        if (dp[i - 2][j]) {
                            dp[i][j] = true;
                            continue;
                        }
                        char prev = p.charAt(i - 2);
                        for (int k = j; k > 0; k--) {
                            if (prev != '.' && prev != s.charAt(k - 1)) {
                                break;
                            }
                            if (dp[i - 2][k - 1]) {
                                dp[i][j] = true;
                                break;
                            }
                        }
                    } else {
                        dp[i][j] = dp[i - 1][j - 1]
                                && (p.charAt(i - 1) == '.' || p.charAt(i - 1) == s
                                        .charAt(j - 1));
                    }
                }

            }
            return dp[p.length()][s.length()];
        }
    }

    public static class UnitTest {
    }
}
