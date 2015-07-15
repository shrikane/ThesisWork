using System;
public interface IComparator<AnyType>
{
    // Return the result of comparing lhs and rhs.
    // returns < 0 if lhs is less than rhs,
    //           0 if lhs is equal to rhs,
    //         > 0 if lhs is greater than rhs.
    int Compare( AnyType lhs, AnyType rhs );
}
public class SimpleRectangle
{
    public SimpleRectangle( int l, int w )
    {
        length = l; width = w;
    }
    public int GetLength( )
    {
        return length;
    }
    public int GetWidth( )
    {
        return width;
    }
    public override string ToString( )
    {
        return "Rectangle " + GetLength( ) + " by " + GetWidth( );
    }
    private int length;
    private int width;
}

public class CompareTest
{
    public static AnyType findMax<AnyType>( AnyType[ ] a, IComparator<AnyType> cmp )
    {
        int maxIndex = 0;

        for( int i = 1; i < a.Length; i++ )
            if( cmp.Compare( a[ i ], a[ maxIndex ] ) > 0 )
                maxIndex = i;

        return a[ maxIndex ];
    }
    class OrderRectByArea : IComparator<SimpleRectangle>
    {
        public int Compare( SimpleRectangle r1, SimpleRectangle r2 )
        {
            return r1.GetWidth( ) * r1.GetLength( ) - r2.GetWidth( ) * r2.GetLength( );
        }
    }
    class OrderRectByWidth : IComparator<SimpleRectangle>
    {
        public int Compare( SimpleRectangle r1, SimpleRectangle r2 )
        {
            return ( r1.GetWidth( ) - r2.GetWidth( ) );
        }
    }
    public static void Main( string[ ] args )
    {
        SimpleRectangle[ ] rects = new SimpleRectangle[ 4 ];

        rects[ 0 ] = new SimpleRectangle( 1, 10 );
        rects[ 1 ] = new SimpleRectangle( 20, 1 );
        rects[ 2 ] = new SimpleRectangle( 4, 6 );
        rects[ 3 ] = new SimpleRectangle( 5, 5 );
        Console.WriteLine( "MAX WIDTH: " + findMax( rects, new OrderRectByWidth( ) ) );
        Console.WriteLine( "MAX AREA: " + findMax( rects, new OrderRectByArea( ) ) );
    }
}
