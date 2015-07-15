/*
Given an int array which might contain duplicates, find the largest subset of it which form a sequence. 
Eg. {1,6,10,5,7,9,4} 
then ans is 4,5,6,7 

Sorting is an obvious solution. Can this be done in O(n) time
*/

public static void LongestContiguousSubArr(int[] arr) {
		Dictionary<int, int> map = new Dictionary<int, int>();
		int f = 0;
		int l = 0;
		for (int i = 0; i < arr.Length; i++) {
                int num = arr[i];
                
                int beg = num;
                int end = num;
				
                if (map.ContainsKey(num))
						continue;//already processed

                map[num] = num;

                int numm1 = num - 1;
                int nump1 = num + 1;

                if (map.ContainsKey(numm1))
                    beg = map[numm1];
                if (map.ContainsKey(nump1))
                    end = map[nump1];
                
                int temp = map[beg];
                map[beg] = map[end];
                map[end] = temp;

                if (f - l <= end - beg)
                {
                    f = beg;
                    l = end;
                }
            }

            for (int i = f; i < l; i++)
            {
                Console.WriteLine(i);
            }
}
