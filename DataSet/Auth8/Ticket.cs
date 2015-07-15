using System;

class Ticket
{
    public Ticket( )
    {
        Console.WriteLine( "Calling constructor" );
        serialNumber = ++ticketCount;
    }

    public int GetSerial( )
    {
        return serialNumber;
    }

    public override string ToString( )
    {
        return "Ticket #" + GetSerial( );
    }

    public static int GetTicketCount( )
    {
        return ticketCount;
    }

    private int serialNumber;
    private static int ticketCount = 0;
}

class TestTicket
{
    public static void Main( string[ ] args )
    {
        Ticket t1;
        Ticket t2;

        Console.WriteLine( "Ticket count is " + Ticket.GetTicketCount( ) );
        t1 = new Ticket( );
        t2 = new Ticket( );
        Console.WriteLine( "Ticket count is " + Ticket.GetTicketCount( ) );
        Console.WriteLine( t1 );
        Console.WriteLine( t2 );
    }
}
