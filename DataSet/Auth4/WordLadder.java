package word_ladder;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class WordLadder {

    public class Solution {
        public int ladderLength(String start, String end, HashSet<String> dict) {
            if (start.equals(end)) {
                return 1;
            }
            List<String> queue = new ArrayList<String>();
            int level = 1;
            queue.add(start);
            int begin = 0;
            char[] endCharArray = end.toCharArray();
            Set<String> used = new HashSet<String>();
            used.add(start);
            while (begin < queue.size()) {
                int tail = queue.size();
                for (int i = begin; i < tail; i++) {
                    char[] word = queue.get(i).toCharArray();
                    for (int j = 0; j < word.length; j++) {
                        char currentChar = word[j];
                        for (char c = 'a'; c <= 'z'; c++) {
                            if (c == currentChar) {
                                continue;
                            }
                            word[j] = c;
                            if (Arrays.equals(word, endCharArray)) {
                                return level + 1;
                            }
                            String nextWord = new String(word);
                            if (dict.contains(nextWord)
                                    && !used.contains(nextWord)) {
                                used.add(nextWord);
                                queue.add(nextWord);
                            }
                            word[j] = currentChar;
                        }
                    }
                }
                level++;
                begin = tail;
            }
            return 0;
        }
    }

    public static class UnitTest {

    }
}
