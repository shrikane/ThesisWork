using System;

class ShapeDemo
{
    public static double TotalArea( Shape[ ] arr )
    {
        double total = 0;

        foreach( Shape s in arr )
        {
            if( s != null )
                total += s.Area( );
        }

        return total;
    }
    public static double TotalSemiperimeter( Shape[ ] arr )
    {
        double total = 0;

        foreach( Shape s in arr )
        {
            if( s != null )
                total += s.Semiperimeter( );
        }

        return total;
    }
    public static void PrintAll( Shape[ ] arr )
    {
        foreach( Shape s in arr )
            Console.WriteLine( s );
    }
    public static void Main( string[ ] args )
    {
        Shape[ ] a = { new Circle( 2.0 ), new Rectangle( 1.0, 3.0 ),
                        null, new Square( 2.0 ) };

        Console.WriteLine( "Total area = " + TotalArea( a ) );
        Console.WriteLine( "Total semiperimeter = " + TotalSemiperimeter( a ) );
        PrintAll( a );
    }
}
