using System;
using System.IO;

public class ListFiles
{
    public static void Main( string[ ] args )
    {
        if( args.Length == 0 )
            Console.WriteLine( "No files specified" );
        foreach( String fileName in args )
            ListFile( fileName );
    }

    public static void ListFile( string fileName )
    {
        StreamReader fileIn = null;
        string oneLine;

        Console.WriteLine( "FILE: " + fileName );
        try
        {
            fileIn = new StreamReader( fileName );
            while( ( oneLine = fileIn.ReadLine( ) ) != null )
                Console.WriteLine( oneLine );
        }
        catch( IOException e )
        { Console.WriteLine( e ); }
        finally
        {
            // Close the stream
            if( fileIn != null )
                fileIn.Close( );
        }
    }
}
