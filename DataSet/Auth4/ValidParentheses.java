package valid_parentheses;

import java.util.ArrayDeque;

public class ValidParentheses {

    public class Solution {
        public boolean isValid(String s) {
            ArrayDeque<Character> stack = new ArrayDeque<Character>();
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                if (c == '(' || c == '[' || c == '{') {
                    stack.push(c);
                } else if (stack.isEmpty()) {
                    return false;
                } else {
                    char top = stack.pop();
                    if (c == ')' && top != '(') {
                        return false;
                    }
                    if (c == ']' && top != '[') {
                        return false;
                    }
                    if (c == '}' && top != '{') {
                        return false;
                    }
                }
            }
            return stack.isEmpty();
        }
    }

    public static class UnitTest {

    }
}
