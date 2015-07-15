using System;

public class TestGenericMemoryCell
{
    public static void Main( string[ ] args )
    {
        GenericMemoryCell<string> m = new GenericMemoryCell<string>( );

        m.Write( "57" );
        String val = m.Read( );
        Console.WriteLine( "Contents are: " + val );
    }
}
