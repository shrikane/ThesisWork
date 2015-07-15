using System;

// A class for simulating an integer memory cell
class IntCell
{
    public IntCell( ) :this( 0 )
    { }
    public IntCell( int d )
    {
        data = d;
    }
    // Get the stored value.
    public int Read( )
    {
        return data;
    }
    // Store a value
    public void Write( int d )
    {
        data = d;
    }
    private int data;

    public int State
    {
        get
        {
            return data;
        }
        set
        {
            if( Math.Abs( data - value ) <= 5 )
                data = value;
        }
    }
}

public class TestIntCell
{
    static void Main( string[ ] args )
    {
        IntCell m = new IntCell( );

        m.Write( 5 );
        Console.WriteLine( "Cell contents: " + m.Read( ) );

        m.State = 8;
        Console.WriteLine( "Cell contents: " + m.Read( ) + " " + m.State );

        m.State = 100;
        Console.WriteLine( "Cell contents: " + m.Read( ) + " " + m.State );
    }
}