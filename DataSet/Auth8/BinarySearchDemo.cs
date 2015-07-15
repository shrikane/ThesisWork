using System;
using System.IO;

public class BinarySearchDemo
{
    public const int NOT_FOUND = -1;

    // Performs the standard binary search
    // using two comparisons per level.
    // returns index where item is found, or NOT_FOUND.
    public static int BinarySearch<AnyType>( AnyType[ ] a, AnyType x ) where AnyType : IComparable
    {
        int low = 0;
        int high = a.Length - 1;
        int mid;

        while( low <= high )
        {
            mid = ( low + high ) / 2;

            if( a[ mid ].CompareTo( x ) < 0 )
                low = mid + 1;
            else if( a[ mid ].CompareTo( x ) > 0 )
                high = mid - 1;
            else
                return mid;
        }

        return NOT_FOUND;     // NOT_FOUND = -1
    }

    // Test program
    public static void Main( string[ ] args )
    {
        int SIZE = 8;
        int[ ] a = new int[ SIZE ];
        for( int i = 0; i < SIZE; i++ )
            a[ i ] = i * 2;

        for( int i = 0; i < SIZE * 2; i++ )
            Console.WriteLine( "Found " + i + " at " +
                                 BinarySearch( a, i ) );

    }
}