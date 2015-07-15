/*
Given a matrix with 1's and 0's, a rectangle can be made with 1's. What is the maximum area of the rectangle. 

00010 
11100 
11110 
11000 
11010 In this test case the result needs to be 8. 

How: 
00010 00010 
11100 11 100 
11110 11 110 
11000 11 000 
11010 11 010 

If you see above the 11's are used from the first two columns and last four rows making the area or count of 1's to be 8.
*/

// time complexity: O(n^2)

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// time complexity: O(n)
int maxAreaInHistogram(vector<int> &histogram)
{
	int length = histogram.size();
	//assert(length > 0);

	stack<int> heightStack;
	heightStack.push(0);
	stack<int> indexStack;
	indexStack.push(-1);

	int maxArea = 0;

	for (int i = 0; i < length; i++)
	{
		int curHeight = histogram[i];

		if (curHeight > heightStack.top())
		{
			heightStack.push(curHeight);
			indexStack.push(i);
		}
		else if (curHeight == heightStack.top())
		{
			// do nothing
		}
		else
		{
			int topHeight = heightStack.top();
			int topIndex;
			while (curHeight < topHeight)
			{
				topIndex = indexStack.top();
				int tempArea = topHeight * (i - topIndex);
				if (tempArea > maxArea) maxArea = tempArea;
				heightStack.pop();
				indexStack.pop();
				topHeight = heightStack.top();
			}
			if (curHeight > topHeight)
			{
				heightStack.push(curHeight);
				indexStack.push(topIndex);
			}
		}
	}

	while (!heightStack.empty())
	{
		int tempArea = heightStack.top() * (length - indexStack.top());
		if (tempArea > maxArea) maxArea = tempArea;
		heightStack.pop();
		indexStack.pop();
	}

	return maxArea;
}

int maxAreaInMatrix(vector<vector<int> > &matrix)
{
	// check input
	int height = matrix.size();
	//assert(height > 0);
	int width = matrix[0].size();
	//assert(width > 0);
	//for (int i = 0; i < height; i++) assert(width == matrix[i].size());

	vector<int> histogram(width, 0);
	int maxArea = 0;

	for (int h = 0; h < height; h++)
	{
		for (int i = 0; i < width; i++)
		{
			histogram[i] = (matrix[h][i] == 0) ? 0 : histogram[i] + 1;
		}

		int tempArea = maxAreaInHistogram(histogram);
		if (tempArea > maxArea) maxArea = tempArea;
	}

	return maxArea;
}

int main() {
		vector<vector<int>> matrix;
		int area = maxAreaInMatrix(matrix);
				printf("%d\n", area);
}
