using System;
using System.IO;

public class DuplicateTest
{
    public const int NUM_ITEMS = 50;

    // Return true if array a has duplicates; false otherwise
    public static bool Duplicates<AnyType>( AnyType[ ] a )
    {
        for( int i = 0; i < a.Length; i++ )
            for( int j = i + 1; j < a.Length; j++ )
                if( a[ i ].Equals( a[ j ] ) )
                    return true;   // Duplicate found

        return false;              // No duplicates found
    }

    // Test the duplicates method
    public static void Main( string[ ] args )
    {
        int[ ] a = new int[ NUM_ITEMS ];
        for( int i = 0; i < a.Length; i++ )
            a[ i ] = i;

        Console.WriteLine( "Should be false: " + Duplicates( a ) );

        a[ NUM_ITEMS - 1 ] = a[ 0 ];

        Console.WriteLine( "Should be true: " + Duplicates( a ) );
    }
}

