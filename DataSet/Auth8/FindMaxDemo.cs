using System;
class FindMaxDemo
{
    // Return max item in a.
    // Precondition: a.length > 0
    public static IComparable FindMax( IComparable[ ] a )
    {
        int maxIndex = 0;

        for( int i = 1; i < a.Length; i++ )
            if( a[ i ].CompareTo( a[ maxIndex ] ) > 0 )
                maxIndex = i;

        return a[ maxIndex ];
    }

    // Test findMax on Shape and String objects.
    public static void Main( String[ ] args )
    {
        Shape[ ] sh1 = { new Circle(  2.0 ),
                        new Square(  3.0 ),
                        new Rectangle( 3.0, 4.0 ) };

        string[ ] st1 = { "Joe", "Bob", "Bill", "Zeke" };

        Console.WriteLine( FindMax( sh1 ) );
        Console.WriteLine( FindMax( st1 ) );
    }
}
