using System;
using System.IO;

public class TestSwap
{
    // Does not work
    static void SwapWrong( int a, int b )
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    // C# Style -- using references
    static void SwapRef( ref int a, ref int b )
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    // Simple program to test various swap routines
    static void Main( string[ ] args )
    {
        int x = 5;
        int y = 7;

        SwapWrong( x, y );
        Console.WriteLine( "x=" + x + " y=" + y );
        SwapRef( ref x, ref y );
        Console.WriteLine( "x=" + x + " y=" + y );
    }
}