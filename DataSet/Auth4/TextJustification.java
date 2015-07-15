package text_justification;

import java.util.ArrayList;

public class TextJustification {

    public class Solution {
        private void appendSpace(StringBuilder line, int space) {
            for (int i = 0; i < space; i++) {
                line.append(' ');
            }
        }

        public ArrayList<String> fullJustify(String[] words, int L) {
            ArrayList<String> ans = new ArrayList<String>();
            if (words.length == 0) {
                return ans;
            }
            int begin = 0;
            int len = words[0].length();
            int current = 1;
            while (current < words.length) {
                if (len + words[current].length() + 1 <= L) {
                    len += words[current].length() + 1;
                } else {
                    int wordCount = current - begin;
                    int padding = L - len + wordCount - 1;
                    StringBuilder line = new StringBuilder();
                    if (wordCount == 1) {
                        line.append(words[begin]);
                        appendSpace(line, padding);
                    } else {
                        int slotSize = padding / (wordCount - 1);
                        int moreSlotCount = padding % (wordCount - 1);
                        for (int i = 0; i < moreSlotCount; i++) {
                            line.append(words[begin + i]);
                            appendSpace(line, slotSize + 1);
                        }
                        for (int i = moreSlotCount; i < wordCount - 1; i++) {
                            line.append(words[begin + i]);
                            appendSpace(line, slotSize);
                        }
                        line.append(words[current - 1]);
                    }
                    ans.add(line.toString());
                    begin = current;
                    len = words[current].length();
                }
                current++;
            }
            StringBuilder line = new StringBuilder();
            for (int i = begin; i < words.length - 1; i++) {
                line.append(words[i]);
                line.append(' ');
            }
            line.append(words[words.length - 1]);
            appendSpace(line, L - len);
            ans.add(line.toString());
            return ans;
        }
    }

    public static class UnitTest {

    }
}
