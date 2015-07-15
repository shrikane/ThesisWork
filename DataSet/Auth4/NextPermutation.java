package next_permutation;

public class NextPermutation {

    public class Solution {
        private void swap(int[] num, int i, int j) {
            int temp = num[i];
            num[i] = num[j];
            num[j] = temp;
        }

        private void reverse(int[] num, int begin, int end) {
            end--;
            while (begin < end) {
                swap(num, begin++, end--);
            }
        }

        public void nextPermutation(int[] num) {
            if (num.length <= 1) {
                return;
            }
            int i = num.length - 1;
            while (i > 0) {
                i--;
                if (num[i] < num[i + 1]) {
                    int j = num.length;
                    while (num[--j] <= num[i]) {
                    }
                    swap(num, i, j);
                    reverse(num, i + 1, num.length);
                    return;
                }
            }
            reverse(num, 0, num.length);
        }
    }

    public static class UnitTest {

    }
}
