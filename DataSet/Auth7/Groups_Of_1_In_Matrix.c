/*
Given a matrix with 1's and 0's, find the number of groups of 1's. A group is defined by horiz/vertically adjacent 1's.
*/

int groupOf1(int* nums, int rows, int cols)
{
    if(nums == NULL || rows <= 0 || cols <= 0)
        return 0;

    int group = 0;
    for(int i = 0; i < rows * cols; ++i)
    {
        if(nums[i] == 1)
        {
            group++;
            flipAdjacent1(nums, rows, cols, i);
        }
    }

    return group;
}


void flipAdjacent1(int* nums, int rows, int cols, int index)
{
    stack<int> group;
    group.push(index);
    while(!group.empty())
    {
        int topIndex = group.top();
        group.pop();
        nums[topIndex] = 0;

        int row = topIndex / cols;
        int col = topIndex % cols;

        // up
        if(row > 0 && nums[(row - 1) * cols + col] == 1)
            group.push((row - 1) * cols + col);
        // right
        if(col < cols - 1 && nums[row * cols + col + 1] == 1)
            group.push(row * cols + col + 1);
        // down
        if(row < rows - 1 && nums[(row + 1) * cols + col] == 1)
            group.push((row + 1) * cols + col);
        // left
        if(col > 0 && nums[row * cols + col - 1] == 1)
            group.push(row * cols + col - 1);
    }
}
