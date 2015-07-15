//using System;
using System;
using System.IO;

public class ReadStringsWithGenericSimpleArrayList
{
    public static void Main( string[ ] args )
    {
        GenericSimpleArrayList<string> array = GetStrings( );

        for( int i = 0; i < array.Count; i++ )
            Console.WriteLine( array[ i ] );
    }
    // Read an unlimited number of String; return an ArrayList
    public static GenericSimpleArrayList<string> GetStrings( )
    {
        GenericSimpleArrayList<string> array = new GenericSimpleArrayList<string>( );
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

