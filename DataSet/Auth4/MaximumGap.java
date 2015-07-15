package maximum_gap;

import java.util.*;

import org.junit.*;

import static org.junit.Assert.*;

public class MaximumGap {

    public class Solution {
        public int maximumGap(int[] num) {
            if (num.length < 2) {
                return 0;
            }
            int min = num[0];
            int max = num[0];
            for (int i = 1; i < num.length; i++) {
                min = Math.min(min, num[i]);
                max = Math.max(max, num[i]);
            }
            if (min == max) {
                return 0;
            }
            // ceil( (max - min) / (n - 1) )
            int gap = (max - min + num.length - 2) / (num.length - 1);
            int bucketNum = (max - min) / gap + 1;
            int[] minInBucket = new int[bucketNum];
            int[] maxInBucket = new int[bucketNum];
            Arrays.fill(minInBucket, -1);
            Arrays.fill(maxInBucket, -1);
            for (int i = 0; i < num.length; i++) {
                int bucketId = (num[i] - min) / gap;
                if (minInBucket[bucketId] < 0) {
                    minInBucket[bucketId] = maxInBucket[bucketId] = num[i];
                } else {
                    minInBucket[bucketId] = Math.min(minInBucket[bucketId], num[i]);
                    maxInBucket[bucketId] = Math.max(maxInBucket[bucketId], num[i]);
                }
            }
            int currentMax;
            int i = 0;
            while (i < bucketNum && minInBucket[i] < 0) {
                i++;
            }
            currentMax = maxInBucket[i];
            gap = 0;
            for (i++; i < bucketNum; i++) {
                if (minInBucket[i] >= 0) {
                    gap = Math.max(gap, minInBucket[i] - currentMax);
                    currentMax = maxInBucket[i];
                }
            }
            return gap;
        }
    }

    public static class UnitTest {

    }
}

