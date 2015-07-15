package wildcard_matching;

public class WildcardMatching {

    public class Solution {

        private int minLength(String p) {
            int len = 0;
            for (int i = 0; i < p.length(); i++) {
                if (p.charAt(i) != '*') {
                    len++;
                }
            }
            return len;
        }

        public boolean isMatch(String s, String p) {
            if (s.length() < minLength(p)) {
                return false;
            }
            boolean[] dp = new boolean[s.length() + 1];
            dp[0] = true;
            for (int i = 1; i <= p.length(); i++) {
                for (int j = s.length(); j > 0; j--) {
                    if (p.charAt(i - 1) == '*') {
                        for (int k = 0; k <= j; k++) {
                            if (dp[k]) {
                                dp[j] = true;
                                break;
                            }
                        }
                    } else {
                        dp[j] = dp[j - 1]
                                && (p.charAt(i - 1) == '?' || p.charAt(i - 1) == s
                                        .charAt(j - 1));
                    }
                }
                dp[0] = p.charAt(i - 1) == '*' && dp[0];
            }
            return dp[s.length()];
        }
    }

    public static class UnitTest {
    }
}
