using System;
using System.IO;

using weiss.nonstandard;

public class PriorityQueueDemo
{
    public static void dumpPQ<AnyType>( string msg, IPriorityQueue<AnyType> pq ) where AnyType : System.Collections.Generic.IComparable<AnyType>
    {
        Console.WriteLine( msg + ":" );
        while( !pq.IsEmpty( ) )
            Console.WriteLine( pq.DeleteMin( ) );
    }

    // Do some inserts and removes (done in DumpPQ).
    public static void Main( string[ ] args )
    {
        IPriorityQueue<int> minPQ = new BinaryHeap<int>( );

        minPQ.Insert( 4 );
        minPQ.Insert( 3 );
        minPQ.Insert( 5 );

        dumpPQ( "minPQ", minPQ );
    }
}
