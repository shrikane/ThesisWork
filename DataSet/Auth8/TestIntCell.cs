using System;

// Exercise the IntCell class
public class TestIntCell
{
    public static void Main( string[ ] args )
    {
        IntCell m = new IntCell( );

        m.Write( 5 );
        Console.WriteLine( "Cell contents: " + m.Read( ) );
        // The next line would be illegal if uncommented
        // m.storedValue = 0;
    }
}