package letter_combinations_of_a_phone_number;

import java.util.ArrayList;

public class LetterCombinationsofaPhoneNumber {

    public class Solution {

        private final String[] dict = new String[] { " ", // 0
                "", // 1
                "abc", // 2
                "def", // 3
                "ghi", // 4
                "jkl", // 5
                "mno", // 6
                "pqrs", // 7
                "tuv", // 8
                "wxyz" // 9
        };

        private void search(ArrayList<String> ans, String digits, int index,
                char[] letters) {
            if (index == digits.length()) {
                ans.add(new String(letters));
                return;
            }

            String options = dict[digits.charAt(index) - '0'];
            for (int i = 0; i < options.length(); i++) {
                letters[index] = options.charAt(i);
                search(ans, digits, index + 1, letters);
            }
        }

        public ArrayList<String> letterCombinations(String digits) {
            ArrayList<String> ans = new ArrayList<String>();
            char[] letters = new char[digits.length()];
            search(ans, digits, 0, letters);
            return ans;
        }
    }

    public static class UnitTest {

    }
}
