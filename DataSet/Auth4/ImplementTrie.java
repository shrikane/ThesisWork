package implement_trie;

public class ImplementTrie {

    class TrieNode {
        private TrieNode[] children = new TrieNode[26];

        private boolean end = false;

        private TrieNode getChild(char c) {
            return children[c - 'a'];
        }

        private TrieNode getOrCreateChild(char c) {
            if (children[c - 'a'] == null) {
                children[c - 'a'] = new TrieNode();
            }
            return children[c - 'a'];
        }

        public void insert(int start, String word) {
            if (start == word.length()) {
                end = true;
            } else {
                TrieNode child = getOrCreateChild(word.charAt(start));
                child.insert(start + 1, word);
            }
        }

        public boolean search(int start, String word, boolean prefixSearch) {
            if (start == word.length()) {
                return end || prefixSearch;
            }
            TrieNode child = getChild(word.charAt(start));
            if (child != null) {
                return child.search(start + 1, word, prefixSearch);
            }
            return false;
        }
    }

    public class Trie {
        private TrieNode root = new TrieNode();

        /**
         * Inserts a word into the trie.
         */
        public void insert(String word) {
            root.insert(0, word);
        }

        /**
         * Returns if the word is in the trie.
         */
        public boolean search(String word) {
            return root.search(0, word, false);
        }

        /**
         * Returns if there is any word in the trie
         * that starts with the given prefix.
         */
        public boolean startsWith(String prefix) {
            return root.search(0, prefix, true);
        }
    }

}

