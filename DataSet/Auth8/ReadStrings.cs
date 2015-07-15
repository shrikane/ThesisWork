using System;
using System.IO;

public class ReadStrings
{
    public static void Main( string[ ] args )
    {
        string[ ] array = GetStrings( );

        for( int i = 0; i < array.Length; i++ )
            Console.WriteLine( array[ i ] );
    }
    // Read an unlimited number of string; return a string [ ]
    public static string[ ] GetStrings( )
    {
        string[ ] array = new string[ 5 ];
        int itemsRead = 0;
        string oneLine;

        Console.WriteLine( "Enter any number of strings, one per line; " );
        Console.WriteLine( "Terminate with empty line: " );

        try
        {
            while( ( oneLine = Console.ReadLine( ) ) != null && oneLine != "" )
            {
                if( itemsRead == array.Length )
                    array = Resize( array, array.Length * 2 );
                array[ itemsRead++ ] = oneLine;
            }
        }
        catch( IOException )
        {
            Console.WriteLine( "Unexpected IO Exception has shortened amount read" );
        }

        Console.WriteLine( "Done reading" );
        return Resize( array, itemsRead );
    }
    // Resize a string[ ] array; return new array
    public static string[ ] Resize( string[ ] array, int newSize )
    {
        string[ ] original = array;
        int numToCopy = Math.Min( original.Length, newSize );

        array = new string[ newSize ];
        for( int i = 0; i < numToCopy; i++ )
            array[ i ] = original[ i ];

        return array;
    }
}
