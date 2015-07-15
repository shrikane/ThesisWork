using System;
using System.IO;

public class PrintIntDemo
{
    private const string DIGIT_TABLE = "0123456789abcdef";
    private static int MAX_BASE = DIGIT_TABLE.Length;

    // Print n in any base, recursively
    // Precondition: n >= 0, 2 <= base <= MAX_BASE
    private static void PrintIntRec( long n, int theBase )
    {
        if( n >= theBase )
            PrintIntRec( n / theBase, theBase );
        Console.Write( DIGIT_TABLE[ (int) ( n % theBase ) ] );
    }

    // Driver routine
    public static void PrintInt( long n, int theBase )
    {
        if( theBase <= 1 || theBase > MAX_BASE )
            Console.Error.WriteLine( "Cannot print in base " + theBase );
        else
        {
            if( n < 0 )
            {
                n = -n;
                Console.Write( "-" );
            }
            PrintIntRec( n, theBase );
        }
    }

    // Simple test program
    public static void Main( string[ ] args )
    {
        for( int i = 0; i <= 17; i++ )
        {
            PrintInt( 1000, i );
            Console.WriteLine( );
        }
        PrintInt( 0x5DEECE66DL, 10 );
        Console.WriteLine( );
    }
}