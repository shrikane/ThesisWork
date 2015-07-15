using System;
using System.IO;

using Random = System.Random;

public class RandomNumbers
{
    // Generate random numbers (from 1-100)
    // Print number of occurrences of each number
    public const int DIFF_NUMBERS = 100;
    public const int TOTAL_NUMBERS = 1000000;

    public static void Main( string[ ] args )
    {
        // Create the array; initialize to zero
        int[ ] numbers = new int[ DIFF_NUMBERS + 1 ];

        for( int i = 0; i < numbers.Length; i++ )
            numbers[ i ] = 0;

        Random r = new Random( );

        // Generate the numbers
        for( int i = 0; i < TOTAL_NUMBERS; i++ )
            numbers[ r.Next( DIFF_NUMBERS ) + 1 ]++;

        // Output the summary
        for( int i = 1; i <= DIFF_NUMBERS; i++ )
            Console.WriteLine( i + ": " + numbers[ i ] );
    }
}