using System;
using weiss.nonstandard;

class TestRedBlackTree
{
    // Test program
    public static void Main( string[ ] args )
    {
        RedBlackTree<int> t = new RedBlackTree<int>( -9999 );
        const int NUMS = 400000;
        const int GAP = 35461;

        Console.WriteLine( "Checking... (no more output means success)" );

        for( int i = GAP; i != 0; i = ( i + GAP ) % NUMS )
            t.Insert( i );

        if( t.FindMin( ) != 1 || t.FindMax( ) != NUMS - 1 )
            Console.WriteLine( "FindMin or FindMax error!" );

        for( int i = 1; i < NUMS; i++ )
            if( t.Find( i ) != i )
                Console.WriteLine( "Find error1!" );
    }
}

