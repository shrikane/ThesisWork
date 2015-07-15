package repeated_dna_sequences;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class RepeatedDNASequences {

    public class Solution {
        public List<String> findRepeatedDnaSequences(String s) {
            Set<String> sequences = new HashSet<String>();
            Set<String> result = new HashSet<String>();
            for (int i = 0; i + 10 <= s.length(); i++) {
                String substring = s.substring(i, i + 10);
                if (sequences.contains(substring)) {
                    result.add(substring);
                } else {
                    sequences.add(substring);
                }
            }
            System.gc();
            return new ArrayList<String>(result);
        }
    }
}

