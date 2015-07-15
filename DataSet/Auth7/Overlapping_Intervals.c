/*
Given a set of non overlapping intervals 
Example 1 :(1,4) (6,10) (14, 19) and another interval (13, 17) merge them as (1,4) (6,10) (13,19) 

Example 2: (1,5) (6, 15) (20, 21) (23, 26) (27, 30) (35, 40) 
New interval (14, 33) 
Output should be 
(1,5) (6, 33) (35, 40) 

This is because the new interval overlaps with (6, 15) (20, 21) (23, 26) (27, 30)
*/

public static Collection<int[]> overlap(int[][] intervals, int[] otherInterval){
		if(intervals.length == 0)
			return Collections.emptyList();
		List<int[]> result = new ArrayList<int[]>();
		boolean found = false;		
		outter:
		for(int i=0; i<intervals.length; i++){	
			
			int lowerBound = intervals[i][0];
			int upperBound = intervals[i][1];

			if(upperBound > otherInterval[0] && !found){
				
				for(int y=i;y<intervals.length;y++){
					
					int _upperBound = intervals[y][1];
					if(y != intervals.length - 1){
						if(otherInterval[1] >= _upperBound && otherInterval[1] <= intervals[y+1][0]){
							result.add(new int[]{Math.min(lowerBound, otherInterval[0]), Math.max(_upperBound, otherInterval[1])});
							found = true;
							continue outter;
						}
					}
					else{
						// if it's the last item, then choose the largest among the upper bound of the interval
						// and the upper bound of the other interval
						result.add(new int[]{Math.min(lowerBound, otherInterval[0]), Math.max(_upperBound, otherInterval[1])});
						found = true;
						continue outter;
					}
					++i;
				}
			}
			result.add(new int[]{lowerBound,upperBound});
		}		
		return result;
	}
