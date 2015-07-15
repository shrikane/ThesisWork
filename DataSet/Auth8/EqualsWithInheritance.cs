using System;

class BaseClass
{
    public BaseClass( int i )
    {
        x = i;
    }

    public override bool Equals( object rhs )
    {
        if( EqualsWithInheritance.BROKEN )
        {
            // This is the wrong test (ok if sealed)
            if( !( rhs is BaseClass ) )
                return false;
        }
        else
        {
            // This is the correct test, if not sealed
            if( rhs == null || GetType( ) != rhs.GetType( ) )
                return false;
        }

        return x == ( (BaseClass) rhs ).x;
    }

    public override int GetHashCode( )
    {
        return x;
    }

    private int x;
}

class DerivedClass : BaseClass
{
    public DerivedClass( int i, int j ) : base( i )
    {
        y = j;
    }

    public override bool Equals( object rhs )
    {
        if( EqualsWithInheritance.BROKEN )
        {
            // This is the wrong test.
            // Test is not needed if getClass() done in superclass equals
            if( !( rhs is DerivedClass ) )
                return false;
        }

        return base.Equals( rhs ) && y == ( (DerivedClass) rhs ).y;
    }

    public override int GetHashCode( )
    {
        return base.GetHashCode( ) + y;
    }

    private int y;
}

public class EqualsWithInheritance
{
    // Change this variable. If true, equals is not
    // symmetric. If false, it is.
    public static bool BROKEN = false;

    public static void Main( string[ ] args )
    {
        BaseClass a = new BaseClass( 5 );
        DerivedClass b = new DerivedClass( 5, 8 );
        DerivedClass c = new DerivedClass( 5, 8 );

        Console.WriteLine( "b.Equals(c): " + b.Equals( c ) );
        Console.WriteLine( "a.Equals(b): " + a.Equals( b ) );
        Console.WriteLine( "b.Equals(a): " + b.Equals( a ) );
    }
}
