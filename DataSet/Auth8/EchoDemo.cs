using System;
using System.IO;

class EchoDemo
{
    public static void Main( string[ ] args )
    {
        for( int i = 0; i < args.Length - 1; i++ )
            Console.Write( args[ i ] + " " );
        if( args.Length != 0 )
            Console.WriteLine( args[ args.Length - 1 ] );
        else
            Console.WriteLine( "No arguments to echo" );
    }
}