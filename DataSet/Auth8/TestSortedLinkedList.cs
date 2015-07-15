using System;

using weiss.nonstandard;

public class TestLinkedList
{
    // Simple print method
    public static void PrintList<AnyType>( LinkedList<AnyType> theList )
    {
        if( theList.IsEmpty( ) )
            Console.WriteLine( "Empty list" );
        else
        {
            LinkedListIterator<AnyType> itr = theList.First( );

            for( ; itr.IsValid( ); itr.Advance( ) )
                Console.Write( itr.Retrieve( ) + " " );
        }

        Console.WriteLine( );
    }

    // In this routine, LinkedList and LinkedListIterator are the
    // classes written in Section 17.2.
    public static int ListSize<AnyType>( LinkedList<AnyType> theList )
    {
        LinkedListIterator<AnyType> itr;
        int size = 0;

        for( itr = theList.First( ); itr.IsValid( ); itr.Advance( ) )
            size++;

        return size;
    }


    public static void Main( string[ ] args )
    {
        LinkedList<int> theList = new SortedLinkedList<int>( );
        LinkedListIterator<int> theItr;
        int i;

        theItr = theList.Zeroth( );
        PrintList( theList );

        for( i = 0; i < 10; i++ )
        {
            theList.Insert( i * 7 % 10, theItr );
            PrintList( theList );
            theItr.Advance( );
        }

        for( i = 0; i < 10; i += 2 )
            theList.Remove( i );

        for( i = 0; i < 10; i++ )
            if( ( i % 2 == 0 ) == ( theList.Find( i ).IsValid( ) ) )
                Console.WriteLine( "Find fails!" );

        Console.WriteLine( "Finished deletions" );
        PrintList( theList );
    }
}