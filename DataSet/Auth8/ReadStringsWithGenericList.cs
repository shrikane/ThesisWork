using System;
using System.IO;
using System.Collections.Generic;

public class ReadStringsWithGenericList
{
    public static void Main( string[ ] args )
    {
        List<string> array = GetStrings( );

        for( int i = 0; i < array.Count; i++ )
            Console.WriteLine( array[ i ] );
    }
    // Read an unlimited number of string; return a List<string>
    public static List<string> GetStrings( )
    {
        List<string> array = new List<string>( );
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

