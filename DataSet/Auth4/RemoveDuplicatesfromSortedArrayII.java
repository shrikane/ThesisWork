package remove_duplicates_from_sorted_array_ii;

public class RemoveDuplicatesfromSortedArrayII {

    public class Solution {
        public int removeDuplicates(int[] A) {
            int len = 0;
            boolean twice = false;
            for (int i = 0; i < A.length; i++) {
                if (i == 0 || A[i] != A[i - 1]) {
                    twice = false;
                    A[len++] = A[i];
                } else if (!twice) {
                    A[len++] = A[i];
                    twice = true;
                }
            }
            return len;
        }
    }

    public static class UnitTest {

    }
}
