package word_break;

import java.util.Set;

public class WordBreak {

    public class Solution {
        public boolean wordBreak(String s, Set<String> dict) {
            assert !s.isEmpty();
            boolean[] dp = new boolean[s.length() + 1];
            dp[0] = true;
            for (int i = 1; i <= s.length(); i++) {
                dp[i] = false;
                for (int j = 0; j < i; j++) {
                    if (dp[j] && dict.contains(s.substring(j, i))) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            return dp[s.length()];
        }
    }

    public static class UnitTest {

    }
}
