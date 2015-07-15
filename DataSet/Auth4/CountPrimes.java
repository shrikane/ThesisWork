package count_primes;

public class CountPrimes {

    public class Solution {
        public int countPrimes(int n) {
            if (n < 3) {
                return 0;
            }
            boolean[] a = new boolean[n];
            a[0] = true;
            a[1] = true;
            int i = 2;
            while (i * i < n) {
                if (!a[i]) {
                    int j = i * i;
                    while (j < n) {
                        a[j] = true;
                        j += i;
                    }
                }
                i++;
            }
            int count = 0;
            for (boolean _a : a) {
                if (!_a) {
                    count++;
                }
            }
            return count;
        }
    }

}

