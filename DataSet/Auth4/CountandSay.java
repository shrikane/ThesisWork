package count_and_say;

public class CountandSay {

    public class Solution {
        public String countAndSay(int n) {
            String ans = "1";
            n--;
            while (n > 0) {
                n--;
                StringBuilder builder = new StringBuilder();
                int count = 1;
                for (int i = 1; i < ans.length(); i++) {
                    if (ans.charAt(i - 1) == ans.charAt(i)) {
                        count++;
                    } else {
                        builder.append(count);
                        builder.append(ans.charAt(i - 1));
                        count = 1;
                    }
                }
                builder.append(count);
                builder.append(ans.charAt(ans.length() - 1));
                ans = builder.toString();
            }
            return ans;
        }
    }

    public static class UnitTest {

    }
}
