package compare_version_numbers;

public class CompareVersionNumbers {

    public class Solution {
        public int compareVersion(String version1, String version2) {
            String[] splits1 = version1.split("\\.");
            String[] splits2 = version2.split("\\.");
            int i = 0;
            for (; i < splits1.length && i < splits2.length; i++) {
                int v1 = Integer.parseInt(splits1[i]);
                int v2 = Integer.parseInt(splits2[i]);
                if (v1 > v2) {
                    return 1;
                } else if (v1 < v2) {
                    return -1;
                }
            }
            if (i == splits1.length) {
                for (int j = i; j < splits2.length; j++) {
                    int v = Integer.parseInt(splits2[j]);
                    if (v != 0) {
                        return -1;
                    }
                }
            } else {
                for (int j = i; j < splits1.length; j++) {
                    int v = Integer.parseInt(splits1[j]);
                    if (v != 0) {
                        return 1;
                    }
                }
            }
            return 0;
        }
    }

    public static class UnitTest {

    }
}

