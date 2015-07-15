package minimum_window_substring;

public class MinimumWindowSubstring {

    public class Solution {
        public String minWindow(String S, String T) {
            int[] tCount = new int[256];
            for (int i = 0; i < T.length(); i++) {
                tCount[T.charAt(i)]++;
            }
            int[] sCount = new int[256];
            int i = 0;
            for (; i < S.length(); i++) {
                sCount[S.charAt(i)]++;
                boolean find = true;
                for (int j = 0; j < 256; j++) {
                    if (sCount[j] < tCount[j]) {
                        find = false;
                        break;
                    }
                }
                if (find) {
                    break;
                }
            }
            if (i == S.length()) {
                return "";
            }
            int windowStart = 0;
            int windowEnd = i;
            int minWindowStart = windowStart;
            int minWindowEnd = windowEnd;
            while (windowStart < S.length()) {
                char c = S.charAt(windowStart);
                sCount[c]--;
                windowStart++;
                if (sCount[c] < tCount[c]) {
                    windowEnd++;
                    while (windowEnd < S.length()) {
                        char endC = S.charAt(windowEnd);
                        sCount[endC]++;
                        if (c == endC) {
                            break;
                        }
                        windowEnd++;
                    }
                    if (windowEnd == S.length()) {
                        break;
                    }
                }
                if (windowEnd - windowStart < minWindowEnd - minWindowStart) {
                    minWindowStart = windowStart;
                    minWindowEnd = windowEnd;
                }
            }
            return S.substring(minWindowStart, minWindowEnd + 1);
        }
    }

    public static class UnitTest {

    }
}
