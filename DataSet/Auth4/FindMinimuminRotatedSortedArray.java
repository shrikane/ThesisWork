package find_minimum_in_rotated_sorted_array;

import java.util.*;

import org.junit.*;

import static org.junit.Assert.*;

public class FindMinimuminRotatedSortedArray {

    public class Solution {
        public int findMin(int[] num) {
            assert (num.length > 0);
            int left = 0;
            int right = num.length - 1;
            while (left < right) {
                if (num[left] < num[right]) {
                    return num[left];
                }
                int mid = left + (right - left) / 2;
                if (num[left] <= num[mid]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            return num[left];
        }
    }

    public static class UnitTest {

    }
}

