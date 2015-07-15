using System;

//Exercise the MemoryCell class
public class TestMemoryCell
{
    public static void Main( string[ ] args )
    {
        MemoryCell m = new MemoryCell( );

        m.Write( "57" );
        string val = (string) m.Read( );
        Console.WriteLine( "Contents are: " + val );
    }
}
