package generate_parentheses;

import java.util.ArrayList;
import java.util.Arrays;

public class GenerateParentheses {

    public class Solution {
        private void generateParenthesis(ArrayList<String> ans, char[] s,
                int left, int right, int n) {
            if (left == n) {
                Arrays.fill(s, left + right, n << 1, ')');
                ans.add(new String(s));
                return;
            }
            s[left + right] = '(';
            generateParenthesis(ans, s, left + 1, right, n);
            if (left > right) {
                s[left + right] = ')';
                generateParenthesis(ans, s, left, right + 1, n);
            }
        }

        public ArrayList<String> generateParenthesis(int n) {
            ArrayList<String> ans = new ArrayList<String>();
            generateParenthesis(ans, new char[n << 1], 0, 0, n);
            return ans;
        }
    }

    public static class UnitTest {

    }
}
