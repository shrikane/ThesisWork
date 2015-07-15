using System;
using System.IO;
using weiss.Collections.Generic;

public class TestGenericImplementations
{
    const int LSIZE = 12;
    const int DSIZE = 100;


    public static void Main( string[ ] args )
    {
        List<int> array = new List<int>( );
        IDictionary<int, int> squares = new SortedDictionary<int, int>( );
        IDictionary<int, int> sqrts = new SortedDictionary<int, int>( );

        for( int i = 1; i < LSIZE; i++ )
            array.Add( i );

        array.Insert( 0, 0 );
        for( int i = array.Count - 1; i >= 0; i-- )
            if( i % 3 == 0 )
                array.RemoveAt( i );

        array.Remove( 7 );

        foreach( int val in array )
            Console.WriteLine( val );

        for( int i = 0; i < DSIZE; i++ )
        {
            squares[ i ] = i * i;
            sqrts[ i * i ] = i;
        }

        Console.WriteLine( squares.Count );
        for( int i = 0; i < DSIZE; i++ )
            if( squares[ i ] != i * i || sqrts[ i * i ] != i )
                Console.WriteLine( "OOPS!!" );
        for( int i = 10; i < DSIZE; i++ )
        {
            squares.Remove( i );
            sqrts.Remove( i * i );
        }

        foreach( KeyValuePair<int, int> pair in sqrts )
            Console.WriteLine( pair.Key + " " + pair.Value );

        ICollection<int> keys = sqrts.Keys;

        foreach( int k in keys )
            Console.WriteLine( k );
        sqrts[ 1000000 ] = 1000;

        foreach( int k in keys )
            Console.WriteLine( k );
        Console.WriteLine( sqrts[ 37 ] );

    }
}

