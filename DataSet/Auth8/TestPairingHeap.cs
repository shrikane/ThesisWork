using System;
using System.Collections.Generic;
using weiss.nonstandard;

public class TestPairingHeap
{
    // Test program
    public static void Main( string[ ] args )
    {
        PairingHeap<int> h = new PairingHeap<int>( );
        int numItems = 10000;
        int i = 37;
        int j;

        Console.WriteLine( "Checking; no bad output is good" );
        for( i = 37; i != 0; i = ( i + 37 ) % numItems )
            h.Insert( i );
        for( i = 1; i < numItems; i++ )
            if( h.DeleteMin( ) != i )
                Console.WriteLine( "Oops! " + i );

        List<IPriorityQueuePosition<int>> p = new List<IPriorityQueuePosition<int>>( );
        for( i = 0; i < numItems; i++ )
            p.Add( null );

        for( i = 0, j = numItems / 2; i < numItems; i++, j = ( j + 71 ) % numItems )
            p[ j ] = h.Insert( j + numItems );
        for( i = 0, j = numItems / 2; i < numItems; i++, j = ( j + 53 ) % numItems )
            h.DecreaseKey( p[ j ], p[ j ].GetValue( ) - numItems );
        i = -1;
        while( !h.IsEmpty( ) )
            if( h.DeleteMin( ) != ++i )
                Console.WriteLine( "Oops! " + i + " " );
        Console.WriteLine( "Check completed" );
    }
}