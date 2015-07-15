package palindrome_partitioning_ii;


public class PalindromePartitioningII {

    public class Solution {
        public int minCut(String s) {
            if (s.isEmpty()) {
                return 0;
            }
            boolean[][] isPalindrome = new boolean[s.length()][s.length()];
            int[] cuts = new int[s.length() + 1];
            cuts[0] = -1;
            for (int i = 0; i < s.length(); i++) {
                cuts[i + 1] = i;
            }
            for (int i = 0; i < s.length(); i++) {
                for (int j = 0; j <= i; j++) {
                    if (s.charAt(i) == s.charAt(j)
                            && (i - j < 2 || isPalindrome[j + 1][i - 1])) {
                        isPalindrome[j][i] = true;
                        cuts[i + 1] = Math.min(cuts[i + 1], cuts[j] + 1);
                    }
                }
            }
            return cuts[s.length()];
        }
    }

    public static class UnitTest {
    }
}
