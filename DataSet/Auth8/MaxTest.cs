using System;
using System.IO;

public class MaxTest
{
    public static void Main( string[ ] args )
    {
        Console.WriteLine( "Enter 2 ints on one line: " );
        try
        {
            string oneLine = Console.ReadLine( );
            if( oneLine == null )
                return;

            string[ ] tokens = oneLine.Split( );
            if( tokens.Length != 2 )
            {
                Console.WriteLine( "Error: need two ints" );
                return;
            }

            int x = int.Parse( tokens[ 0 ] );
            int y = int.Parse( tokens[ 1 ] );
            Console.WriteLine( "Max: " + Math.Max( x, y ) );
        }
        catch( IOException )
        { Console.Error.WriteLine( "Unexpected IO error" ); }
        catch( FormatException )
        { Console.Error.WriteLine( "Error: need two ints" ); }
    }
}
