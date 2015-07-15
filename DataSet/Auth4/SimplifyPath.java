package simplify_path;

import java.util.ArrayDeque;

public class SimplifyPath {

    public class Solution {
        public String simplifyPath(String path) {
            String[] splits = path.split("/");
            ArrayDeque<String> stack = new ArrayDeque<String>();
            for (String split : splits) {
                if (!split.isEmpty()) {
                    if (split.equals("..")) {
                        if (!stack.isEmpty()) {
                            stack.removeLast();
                        }
                    } else if (split.equals(".")) {
                        continue;
                    } else {
                        stack.offerLast(split);
                    }
                }
            }
            StringBuilder newPath = new StringBuilder();
            for (String s : stack) {
                newPath.append('/');
                newPath.append(s);
            }
            return newPath.length() == 0 ? "/" : newPath.toString();
        }
    }

    public static class UnitTest {

    }
}
