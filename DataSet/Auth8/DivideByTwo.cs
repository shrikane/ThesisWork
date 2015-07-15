using System;
using System.IO;

class DivideByTwo
{
    public static void Main( string[ ] args )
    {
        int x;
        String oneLine;

        Console.WriteLine( "Enter an integer: " );
        try
        {
            oneLine = Console.ReadLine( );
            x = int.Parse( oneLine );
            Console.WriteLine( "Half of x is " + ( x / 2 ) );
        }
        catch( IOException e )
        { Console.WriteLine( e ); }
        catch( FormatException e )
        { Console.WriteLine( e ); }
        catch( OverflowException e )
        { Console.WriteLine( e ); }
    }
}