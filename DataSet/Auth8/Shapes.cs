using System;
using System.Collections;

public abstract class Shape : IComparable
{
    public abstract double Area( );
    public abstract double Perimeter( );

    public int CompareTo( object rhs )
    {
        double diff = Area( ) - ( (Shape) rhs ).Area( );
        if( diff == 0 )
            return 0;
        else if( diff < 0 )
            return -1;
        else
            return 1;
    }

    public double Semiperimeter( )
    {
        return Perimeter( ) / 2;
    }
}

public class Circle : Shape
{
    public Circle( double rad )
    {
        radius = rad;
    }

    public override double Area( )
    {
        return Math.PI * radius * radius;
    }

    public override double Perimeter( )
    {
        return 2 * Math.PI * radius;
    }

    public override string ToString( )
    {
        return "Circle: " + radius;
    }

    private double radius;
}

public class Rectangle : Shape
{
    public Rectangle( double len, double wid )
    {
        length = len; width = wid;
    }

    public override double Area( )
    {
        return length * width;
    }

    public override double Perimeter( )
    {
        return 2 * ( length + width );
    }

    public override string ToString( )
    {
        return "Rectangle: " + length + " " + width;
    }

    public double GetLength( )
    {
        return length;
    }

    public double GetWidth( )
    {
        return width;
    }

    private double length;
    private double width;
}

public class Square : Rectangle
{
    public Square( double side ) : base( side, side )
    {
    }

    public override string ToString( )
    {
        return "Square: " + GetLength( );
    }

}
