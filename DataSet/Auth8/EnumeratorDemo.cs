using System;
using System.IO;
using System.Collections.Generic;

public class EnumeratorDemo
{
    public static void PrintCollection1<AnyType>( ICollection<AnyType> c )
    {
        IEnumerator<AnyType> itr = c.GetEnumerator( );

        while( itr.MoveNext( ) )
            Console.WriteLine( itr.Current );
    }

    public static void PrintCollection2<AnyType>( ICollection<AnyType> c )
    {
        foreach( AnyType val in c )
            Console.WriteLine( val );
    }


    // Do some inserts and printing.
    public static void Main( string[ ] args )
    {
        List<int> lst = new List<int>( );

        for( int i = 0; i < 5; i++ )
            lst.Add( i );

        Console.WriteLine( "Printing lst using explicit enumerator" );
        PrintCollection1( lst );

        Console.WriteLine( "Printing lst using foreach" );
        PrintCollection2( lst );
    }
}


