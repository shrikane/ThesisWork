using System;
using System.IO;

// Double space files specified on command line.
public class DoubleSpace
{
    public static void Main( string[ ] args )
    {
        foreach( string fileName in args )
            OutputDoubleSpace( fileName );
    }
    public static void OutputDoubleSpace( String fileName )
    {
        StreamWriter fileOut = null;
        StreamReader fileIn = null;

        try
        {
            fileIn = new StreamReader( fileName );
            fileOut = new StreamWriter( fileName + ".ds" );

            string oneLine;

            while( ( oneLine = fileIn.ReadLine( ) ) != null )
                fileOut.WriteLine( oneLine + "\n" );
        }
        catch( IOException e )
        { Console.WriteLine( e ); }
        finally
        {
            if( fileOut != null )
                fileOut.Close( );

            if( fileIn != null )
                fileIn.Close( );
        }
    }
}