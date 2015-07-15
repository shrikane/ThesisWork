package longest_substring_without_repeating_characters;

import java.util.Arrays;

public class LongestSubstringWithoutRepeatingCharacters {

    public class Solution {
        public int lengthOfLongestSubstring(String s) {
            int[] prevPos = new int[Character.MAX_VALUE + 1];
            Arrays.fill(prevPos, -1);
            int substringBegin = 0;
            int maxSubstringLen = 0;
            for (int i = 0; i < s.length(); i++) {
                substringBegin = Math.max(substringBegin,
                        prevPos[s.charAt(i)] + 1);
                prevPos[s.charAt(i)] = i;
                maxSubstringLen = Math.max(maxSubstringLen, i - substringBegin
                        + 1);
            }
            return maxSubstringLen;
        }
    }

    public static class UnitTest {

    }
}
