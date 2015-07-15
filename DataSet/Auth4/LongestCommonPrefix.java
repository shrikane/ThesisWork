package longest_common_prefix;

public class LongestCommonPrefix {

    public class Solution {
        public String longestCommonPrefix(String[] strs) {
            if (strs.length == 0) {
                return "";
            }

            int longest = strs[0].length();
            for (int i = 1; i < strs.length; i++) {
                longest = Math.min(strs[i].length(), longest);
                for (int j = 0; j < longest; j++) {
                    if (strs[i].charAt(j) != strs[0].charAt(j)) {
                        longest = j;
                        break;
                    }
                }
            }
            return strs[0].substring(0, longest);
        }
    }

    public static class UnitTest {

    }
}
