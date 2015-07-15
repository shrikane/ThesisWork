package palindrome_partitioning;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class PalindromePartitioning {

    public class Solution {
        private boolean isPalindromic(String s) {
            for (int i = 0; i < s.length() / 2; i++) {
                if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
                    return false;
                }
            }
            return true;
        }

        private Map<String, ArrayList<ArrayList<String>>> cache = new HashMap<String, ArrayList<ArrayList<String>>>();

        public ArrayList<ArrayList<String>> partition(String s) {
            ArrayList<ArrayList<String>> ans = cache.get(s);
            if (ans != null) {
                return ans;
            }
            ans = new ArrayList<ArrayList<String>>();
            for (int i = 1; i < s.length(); i++) {
                String prefix = s.substring(0, i);
                if (isPalindromic(prefix)) {
                    for (ArrayList<String> subans : partition(s.substring(i))) {
                        ArrayList<String> temp = new ArrayList<String>();
                        temp.add(prefix);
                        temp.addAll(subans);
                        ans.add(temp);
                    }
                }
            }
            if (isPalindromic(s)) {
                ArrayList<String> temp = new ArrayList<String>();
                temp.add(s);
                ans.add(temp);
            }
            cache.put(s, ans);
            return ans;
        }
    }

    public static class UnitTest {

    }
}
