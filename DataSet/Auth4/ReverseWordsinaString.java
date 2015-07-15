package reverse_words_in_a_string;

public class ReverseWordsinaString {

    public class Solution {
        public String reverseWords(String s) {
            String[] tokens = s.split(" +");
            StringBuilder r = new StringBuilder();
            boolean isFirst = true;
            for (int i = tokens.length - 1; i >= 0; i--) {
                String token = tokens[i];
                if (token.isEmpty()) {
                    continue;
                }
                if (isFirst) {
                    isFirst = false;
                } else {
                    r.append(' ');
                }
                r.append(token);
            }
            return r.toString();
        }
    }

    public static class UnitTest {

    }
}
