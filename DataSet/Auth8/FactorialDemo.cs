using System;
using System.IO;

public class FactorialDemo
{
    // Evaluate n!
    public static long Factorial( int n )
    {
        if( n <= 1 )     // base case
            return 1;
        else
            return n * Factorial( n - 1 );
    }
    // Simple test program
    public static void Main( string[ ] args )
    {
        for( int i = 1; i <= 10; i++ )
            Console.WriteLine( Factorial( i ) );
    }
}
