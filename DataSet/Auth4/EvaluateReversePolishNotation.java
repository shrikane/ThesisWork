package evaluate_reverse_polish_notation;

import java.util.ArrayDeque;

public class EvaluateReversePolishNotation {

    public class Solution {
        public int evalRPN(String[] tokens) {
            ArrayDeque<Integer> stack = new ArrayDeque<Integer>();
            for (String token : tokens) {
                if (token.equals("+")) {
                    int num2 = stack.removeLast();
                    int num1 = stack.removeLast();
                    stack.offerLast(num1 + num2);
                } else if (token.equals("-")) {
                    int num2 = stack.removeLast();
                    int num1 = stack.removeLast();
                    stack.offerLast(num1 - num2);
                } else if (token.equals("*")) {
                    int num2 = stack.removeLast();
                    int num1 = stack.removeLast();
                    stack.offerLast(num1 * num2);
                } else if (token.equals("/")) {
                    int num2 = stack.removeLast();
                    int num1 = stack.removeLast();
                    stack.offerLast(num1 / num2);
                } else {
                    stack.offerLast(Integer.parseInt(token));
                }
            }
            return stack.removeLast();
        }
    }

    public static class UnitTest {

    }
}
