using System;

// Minimal Date class that illustrates some Java features
// No error checks

public class Date
{
    // Zero-parameter constructor
    public Date( ) : this( 1, 1, 2005 )
    {
    }

    // Three-parameter constructor
    public Date( int theMonth, int theDay, int theYear )
    {
        month = theMonth;
        day = theDay;
        year = theYear;
    }

    // Return true if two equal values
    public override bool Equals( object rhs )
    {
        if( !( rhs is Date ) )
            return false;
        Date rhDate = (Date) rhs;
        return rhDate.month == month && rhDate.day == day &&
               rhDate.year == year;
    }

    // Return a numeric code for this object.
    public override int GetHashCode( )
    {
        return day + month * 12 + year * 365;
    }

    // Conversion to String
    public override string ToString( )
    {
        return month + "/" + day + "/" + year;
    }

    // Fields
    private int month;
    private int day;
    private int year;
}

public class DateDemo
{
    // Sample main
    public static void Main( string[ ] args )
    {
        Date d1 = new Date( );
        Date d2 = new Date( 1, 1, 2005 );
        Date d3 = new Date( 1, 1, 2006 );

        Console.WriteLine( "Date 1: " + d1 );
        Console.WriteLine( "Date 2: " + d2 );
        Console.WriteLine( "Date 3: " + d3 );
        Console.WriteLine( "Date1 same state as Date2?: " + d1.Equals( d2 ) );
        Console.WriteLine( "Date1 same state as Date3?: " + d1.Equals( d3 ) );
    }
}