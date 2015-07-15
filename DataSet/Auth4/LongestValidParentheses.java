package longest_valid_parentheses;

public class LongestValidParentheses {

    public class Solution {
        public int longestValidParentheses(String s) {
            int[] dp = new int[s.length()];
            int max = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == ')') {
                    int p = i - 1;
                    while (p >= 0) {
                        if (s.charAt(p) == '(') {
                            dp[i] = i - p + 1 + (p > 0 ? dp[p - 1] : 0);
                            break;
                        } else if (dp[p] == 0) {
                            break;
                        }
                        p = p - dp[p];
                    }
                }
                max = Math.max(max, dp[i]);
            }
            return max;
        }
    }

    public static class UnitTest {

    }
}
