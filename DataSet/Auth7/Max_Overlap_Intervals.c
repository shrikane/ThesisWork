/*
giving lots of intervals [ai, bi], find a point intersect with the most number of intervals
*/

/*
store each boundary value as a separate element in an array with the information whether it's the start boundary or end boundary. 
Sort this array by boundary value. 
initialize an integer overLapCount = 0; 
Traverse this array from start to finish 
whenever you cross a "Start" boundary, increment overlapCount 
whenever you cross an "End" boundary, decrement overlapCount 
store the maxOverLapCountSoFar 
at the end of the traversal you will have the information about what is the maximum possible overlap for a range. 
You can easily modify this to store the range information as well.
*/

/*Also make sure when you are sorting, if boundary value are same then a start should come before end. 
my boundary class looks like this
*/

enum BoundaryType
{
    Start = 0,
    End = 1
}

class Boundary : IComparable<Boundary>
{
    public int Value { get; set; }
    public BoundaryType BoundaryType { get; set; }
    public int CompareTo(Boundary other)
    {
        if (Value == other.Value)
        {
            return BoundaryType.CompareTo(other.BoundaryType);
        }
        else
            return Value.CompareTo(other.Value);
    }
}
