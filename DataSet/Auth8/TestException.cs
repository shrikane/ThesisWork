using System;

public class GraphException : ApplicationException
{
    public GraphException( string msg ) : base(msg)
    {
    }
}

class TestException
{
    public static void Foo( )
    {
        throw new GraphException( "oops" );
    }
    public static void Main( string[ ] args )
    {
        try
        {
            Foo( );
        }
        catch( Exception e )
        {
            Console.WriteLine( e );
        }
    }
}

