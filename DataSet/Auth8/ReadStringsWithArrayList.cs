//using System;
using System;
using System.IO;
using System.Collections;

public class ReadStringsWithArrayList
{
    public static void Main( string[ ] args )
    {
        ArrayList array = GetStrings( );

        for( int i = 0; i < array.Count; i++ )
            Console.WriteLine( array[ i ] );
    }
    // Read an unlimited number of String; return an ArrayList
    public static ArrayList GetStrings( )
    {
        ArrayList array = new ArrayList( );
        string oneLine;

        Console.WriteLine( "Enter any number of strings, one per line; " );
        Console.WriteLine( "Terminate with empty line: " );
        try
        {
            while( ( oneLine = Console.ReadLine( ) ) != null && oneLine != "" )
                array.Add( oneLine );
        }
        catch( IOException )
        {
            Console.WriteLine( "Unexpected IO Exception has shortened amount read" );
        }
        Console.WriteLine( "Done reading" );
        return array;
    }
}

