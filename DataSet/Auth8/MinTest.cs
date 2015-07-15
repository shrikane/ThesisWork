using System;
using System.IO;

public class MinTest
{
    public static void Main( string[ ] args )
    {
        int a = 3;
        int b = 7;

        Console.WriteLine( Min( a, b ) );
    }
    // Function definition
    public static int Min( int x, int y )
    {
        return x < y ? x : y;
    }
}