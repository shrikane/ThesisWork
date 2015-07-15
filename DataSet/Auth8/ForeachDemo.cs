using System;
using System.IO;
using System.Collections.Generic;

public class ForeachDemo
{
    public static void Main( string[ ] args )
    {
        string[ ] arr1 = { "Hello", "world" };
        List<string> arr2 = new List<string>( );

        arr2.Add( "Hello" );
        arr2.Add( "world" );
        foreach( string s in arr1 )
            Console.WriteLine( s );

        foreach( string s in arr2 )
            Console.WriteLine( s );
    }
}