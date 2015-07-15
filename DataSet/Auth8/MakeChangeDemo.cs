using System;
using System.IO;

public class MakeChangeDemo
{
    // Dynamic programming algorithm to solve change making problem.
    // As a result, the coinsUsed array is filled with the
    // minimum number of coins needed for change from 0 -> maxChange
    // and lastCoin contains one of the coins needed to make the change.
    public static void MakeChange( int[ ] coins, int differentCoins,
                int maxChange, int[ ] coinsUsed, int[ ] lastCoin )
    {
        coinsUsed[ 0 ] = 0; lastCoin[ 0 ] = 1;

        for( int cents = 1; cents <= maxChange; cents++ )
        {
            int minCoins = cents;
            int newCoin = 1;

            for( int j = 0; j < differentCoins; j++ )
            {
                if( coins[ j ] > cents )   // Cannot use coin j
                    continue;
                if( coinsUsed[ cents - coins[ j ] ] + 1 < minCoins )
                {
                    minCoins = coinsUsed[ cents - coins[ j ] ] + 1;
                    newCoin = coins[ j ];
                }
            }

            coinsUsed[ cents ] = minCoins;
            lastCoin[ cents ] = newCoin;
        }
    }

    // Simple test program
    public static void Main( string[ ] args )
    {
        // The coins and the total amount of change
        int numCoins = 5;
        int[ ] coins = { 1, 5, 10, 21, 25 };
        int change = 0;

        if( args.Length == 0 )
        {
            Console.Error.WriteLine( "Supply a monetary amount on the command line" );
            Environment.Exit( 0 );
        }

        try
        { change = int.Parse( args[ 0 ] ); }
        catch( FormatException e )
        {
            Console.Error.WriteLine( e );
            Environment.Exit( 0 );
        }

        int[ ] used = new int[ change + 1 ];
        int[ ] last = new int[ change + 1 ];

        MakeChange( coins, numCoins, change, used, last );

        Console.WriteLine( "Best is " + used[ change ] + " coins" );

        for( int i = change; i > 0; )
        {
            Console.Write( last[ i ] + " " );
            i -= last[ i ];
        }
        Console.WriteLine( );
    }
}

