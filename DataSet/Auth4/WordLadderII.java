package word_ladder_ii;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

public class WordLadderII {

    /**
     * "Time Limit Exceeded". Is there a perfect Java solution to pass the
     * tests?
     */
    public class Solution {

        private HashMap<Integer, List<Integer>> searchNeighbors(String[] nodes) {
            HashMap<String, Integer> indices = new HashMap<String, Integer>(
                    nodes.length);
            int i = 0;
            for (String word : nodes) {
                indices.put(word, i++);
            }

            HashMap<Integer, List<Integer>> neighbors = new HashMap<Integer, List<Integer>>();

            i = 0;
            for (String word : nodes) {
                List<Integer> neighbor = neighbors.get(word);
                if (neighbor == null) {
                    neighbor = new ArrayList<Integer>();
                    neighbors.put(i, neighbor);
                }
                char[] temp = word.toCharArray();
                for (int j = 0; j < temp.length; j++) {
                    char oldC = temp[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c != oldC) {
                            temp[j] = c;
                            String newS = new String(temp);
                            Integer index = indices.get(newS);
                            if (index != null) {
                                neighbor.add(index);
                            }
                        }
                    }
                    temp[j] = oldC;
                }
                i++;
            }
            return neighbors;
        }

        public ArrayList<ArrayList<String>> findLadders(String start,
                String end, HashSet<String> dict) {
            ArrayList<ArrayList<String>> ans = new ArrayList<ArrayList<String>>();

            if (start.equals(end)) {
                ArrayList<String> l = new ArrayList<String>();
                l.add(start);
                ans.add(l);
                return ans;
            }

            ArrayList<Integer> queue = new ArrayList<Integer>();
            ArrayList<Integer> prev = new ArrayList<Integer>();

            dict.add(start);
            dict.add(end);

            String[] nodes = new String[dict.size()];
            int j = 0;
            int startIndex = 0;
            int endIndex = 0;
            for (String word : dict) {
                if (word.equals(start)) {
                    startIndex = j;
                }
                if (word.equals(end)) {
                    endIndex = j;
                }
                nodes[j++] = word;
            }
            HashMap<Integer, List<Integer>> neighbors = searchNeighbors(nodes);
            System.gc(); // To avoid "Memory Limit Exceeded"

            queue.add(startIndex);
            prev.add(-1);
            boolean[] used = new boolean[nodes.length];
            used[startIndex] = true;
            int begin = 0;
            boolean find = false;
            while (!find && begin < queue.size()) {
                int tail = queue.size();
                for (int i = begin; i < tail; i++) {
                    int s = queue.get(i);
                    for (int indexInNode : neighbors.get(s)) {
                        if (indexInNode == endIndex) {
                            find = true;
                            ArrayList<String> path = new ArrayList<String>();
                            path.add(end);
                            int index = i;
                            while (index >= 0) {
                                path.add(nodes[queue.get(index)]);
                                index = prev.get(index);
                            }
                            Collections.reverse(path);
                            ans.add(path);
                            break;
                        }
                        if (!find && !used[indexInNode]) {
                            queue.add(indexInNode);
                            prev.add(i);
                        }
                    }
                }
                begin = tail;
                for (int i = begin; i < tail; i++) {
                    used[queue.get(i)] = true;
                }
            }
            return ans;
        }
    }

    public static class UnitTest {
    }
}
