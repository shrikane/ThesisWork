package restore_ip_addresses;

import java.util.ArrayList;

public class RestoreIPAddresses {

    public class Solution {
        private String toAddr(ArrayList<Integer> solution) {
            String addr = "";
            addr += solution.get(0);
            addr += ".";
            addr += solution.get(1);
            addr += ".";
            addr += solution.get(2);
            addr += ".";
            addr += solution.get(3);
            return addr;
        }

        private void search(String s, int begin, ArrayList<Integer> solution,
                ArrayList<String> solutions) {
            if (begin == s.length() && solution.size() == 4) {
                solutions.add(toAddr(solution));
                return;
            }
            if (s.length() - begin > (4 - solution.size()) * 3) {
                return;
            }
            if (s.length() - begin < 4 - solution.size()) {
                return;
            }
            int num = 0;
            for (int i = begin; i < Math.min(begin + 3, s.length()); i++) {
                num = num * 10 + s.charAt(i) - '0';
                if (num < 256) {
                    solution.add(num);
                    search(s, i + 1, solution, solutions);
                    solution.remove(solution.size() - 1);
                }
                if (num == 0) {
                    break;
                }
            }
        }

        public ArrayList<String> restoreIpAddresses(String s) {
            ArrayList<String> solutions = new ArrayList<String>();
            search(s, 0, new ArrayList<Integer>(), solutions);
            return solutions;
        }
    }

    public static class UnitTest {
    }
}
