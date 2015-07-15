using System;
using System.IO;

public class RecSum
{
    // Evaluate the sum of the first n integers
    public static long Sum( int n )
    {
        if( n == 1 )
            return 1;
        else
            return Sum( n - 1 ) + n;
    }
    // Simple test program
    public static void Main( string[ ] args )
    {
        for( int i = 1; i <= 10; i++ )
            Console.WriteLine( Sum( i ) );
    }
}