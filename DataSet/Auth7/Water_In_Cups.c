/*
there is a pyramid with 1 cup at level , 2 at level 2 , 3 at level 3 and so on..
It looks something like this 
1 
2 3 
4 5 6 
every cup has capacity C. you pour L liters of water from top . when cup 1 gets filled , it overflows to cup 2,3 equally, and when they get filled , Cup 4 and 6 get water only from 2 and 3 resp but 5 gets water from both the cups and so on. 
Now given C and M .Find the amount of water in ith cup.
*/

/*Solved it with O(k). 
The idea is simple. Pour L into coup 1. Divide into its children if overflows. Do this for subsequent elements, until find k. 
The biggest problem is to find the children. The first child of a coup is the same of last if height does not change. The second one is first + 1. 
For the given example, children would found in the the folowing order (se how children repeats when height repeats (kth is one based!):


Height: 1  2  2  3  3  3
Coup  : 1  2  3  4  5  6
Child : 23 45 56 78 89 910
*/

public static double calculateWaterVol(double c, double l, int kth /* one based */) {
		int [] height = new int[kth];
		double[] water = new double[kth];
		water[0] = l;
		int childIndex = 0;
		for (int i=0; i<(kth-1);++i) {
				double over = 0.0;
				if (water[i] > c) {
						over = (water[i] - c)/2;
						water[i] = c;
				}
				if (i == 0 || height[i-1] < height[i]) {
						++childIndex;
				}
				if (childIndex >= kth) break;
				height[childIndex] = height[i]+1;
				water[childIndex] += over;
				++childIndex;
				if (childIndex >= kth) break;
				height[childIndex] = height[i]+1;
				water[childIndex] += over;
		}
		return water[kth-1] >  c ? c : water[kth-1];
}
