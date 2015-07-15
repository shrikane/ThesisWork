using System;
using System.IO;

public class OperatorTest
{
    // Program to illustrate basic operators
    // The output is as follows:
    // 12 8 6
    // 6 8 6
    // 6 8 14
    // 22 8 14
    // 24 10 33
    public static void Main( string[ ] args )
    {
        int a = 12, b = 8, c = 6;

        Console.WriteLine( a + " " + b + " " + c );
        a = c;
        Console.WriteLine( a + " " + b + " " + c );
        c += b;
        Console.WriteLine( a + " " + b + " " + c );
        a = b + c;
        Console.WriteLine( a + " " + b + " " + c );
        a++;
        ++b;
        c = a++ + ++b;
        Console.WriteLine( a + " " + b + " " + c );
    }
}