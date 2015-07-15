using System;

class Person
{
    public Person( string n, int ag, string ad, string p )
    {
        name = n; age = ag; address = ad; phone = p;
    }
    public override string ToString( )
    {
        return GetName( ) + " " + GetAge( ) + " " + Address + " " + GetPhoneNumber( );
    }
    public string GetName( )
    {
        return name;
    }
    public int GetAge( )
    {
        return age;
    }
    public string GetPhoneNumber( )
    {
        return phone;
    }
    public void SetPhoneNumber( string newPhone )
    {
        phone = newPhone;
    }
    public string Address
    {
        get { return address; }
        set { address = value; }
    }

    private string name;
    private int age;
    private string address;
    private string phone;
}
class Student : Person
{
    public Student( string n, int ag, string ad, string p, double g ) : base ( n, ag, ad, p )
    {
        gpa = g;
    }
    public override string ToString( )
    {
        return base.ToString( ) + " " + GetGPA( );
    }
    public double GetGPA( )
    {
        return gpa;
    }
    private double gpa;
}
class Employee : Person
{
    public Employee( string n, int ag, string ad, string p, double s ) :base( n, ag, ad, p )
    {
        salary = s;
    }
    public override string ToString( )
    {
        return base.ToString( ) + " $" + GetSalary( );
    }
    public double GetSalary( )
    {
        return salary;
    }
    public void Raise( double percentRaise )
    {
        salary *= ( 1 + percentRaise );
    }
    private double salary;
}
class PersonDemo
{
    public static void PrintAll( Person[ ] arr )
    {
        for( int i = 0; i < arr.Length; i++ )
        {
            if( arr[ i ] != null )
            {
                Console.Write( "[" + i + "] " + arr[ i ] );
                Console.WriteLine( );
            }
        }
    }
    public static void Main( string[ ] args )
    {
        Person[ ] p = new Person[ 4 ];

        p[ 0 ] = new Person( "joe", 25, "New York", "212-555-1212" );
        p[ 1 ] = new Student( "jill", 39, "Miami", "305-555-1212", 4.0 );
        p[ 3 ] = new Employee( "bob", 29, "Boston", "617-555-1212", 100000.0 );
        if( p[ 3 ] is Employee )
            ( (Employee) p[ 3 ] ).Raise( .04 );

        p[ 3 ].Address = "Hopkintown";
        PrintAll( p );
    }
}
