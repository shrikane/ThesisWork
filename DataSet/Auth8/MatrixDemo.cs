using System;
using System.IO;

public class MatrixDemo
{
    public static void PrintMatrix( int[ ][ ] m )
    {
        for( int i = 0; i < m.Length; i++ )
        {
            if( m[ i ] == null )
                Console.WriteLine( "(null)" );
            else
            {
                for( int j = 0; j < m[ i ].Length; j++ )
                    Console.Write( m[ i ][ j ] + " " );

                Console.WriteLine( );
            }
        }
    }

    public static void Main( string[ ] args )
    {
        int[ ][ ] a = new int[ 3 ][ ];

        a[ 0 ] = new int[ ] { 1, 2 };
        a[ 1 ] = new int[ ] { 3, 4 };
        a[ 2 ] = new int[ ] { 5, 6 };

        int[ ][ ] b = new int[ 3 ][ ];

        b[ 0 ] = new int[ ] { 1, 2 };
        b[ 1 ] = null;
        b[ 2 ] = new int[ ] { 5, 6 };

        int[ ][ ] c = new int[ 3 ][ ];

        c[ 0 ] = new int[ ] { 1, 2 };
        c[ 1 ] = new int[ ] { 3, 4, 5 };
        c[ 2 ] = new int[ ] { 6 };
        Console.WriteLine( "a: " ); PrintMatrix( a );
        Console.WriteLine( "b: " ); PrintMatrix( b );
        Console.WriteLine( "c: " ); PrintMatrix( c );
    }
}