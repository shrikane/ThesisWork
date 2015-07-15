using System;
using weiss.nonstandard;

public class QueueDemo
{
    public static void queueOps( string type, IQueue<int> s )
    {
        Console.WriteLine( type + " output: " );
        for( int i = 0; i < 10; i++ )
            s.Enqueue( i );

        while( !s.IsEmpty( ) )
            Console.WriteLine( s.Dequeue( ) );
    }

    public static void Main( string[ ] args )
    {
        IQueue<int> q1 = new ArrayQueue<int>( );
        IQueue<int> q2 = new ListQueue<int>( );

        queueOps( "ArrayQueue", q1 );
        queueOps( "ListQueue", q2 );
    }
}

