using System;
using weiss.nonstandard;

public class TestBinaryHeap
{
    // Test program
    public static void Main( string[ ] args )
    {
        int numItems = 10000;
        BinaryHeap<int> h1 = new BinaryHeap<int>( );
        int[ ] items = new int[ numItems - 1 ];

        int i = 37;
        int j;

        for( i = 37, j = 0; i != 0; i = ( i + 37 ) % numItems, j++ )
        {
            h1.Insert( i );
            items[ j ] = i;
        }

        for( i = 1; i < numItems; i++ )
            if( h1.DeleteMin( ) != i )
                Console.WriteLine( "Oops! " + i );

        BinaryHeap<int> h2 = new BinaryHeap<int>( items );
        for( i = 1; i < numItems; i++ )
            if( h2.DeleteMin( ) != i )
                Console.WriteLine( "Oops! " + i );

        Console.WriteLine( "Binary Heap Test over" );
    }
}