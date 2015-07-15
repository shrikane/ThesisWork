using System;

namespace weiss.nonstandard
{
    // ListQueue class
    //
    // Linked list-based implementation of the queue.
    //
    // ******************PUBLIC OPERATIONS*********************
    // void Enqueue( x )      --> Insert x
    // AnyType GetFront( )    --> Return least recently inserted item
    // AnyType Dequeue( )     --> Return and remove least recent item
    // boolean IsEmpty( )     --> Return true if empty; else false
    // void MakeEmpty( )      --> Remove all items
    // ******************ERRORS********************************
    //GetFront or Dequeue on empty queue

    public class ListQueue<AnyType> : IQueue<AnyType>
    {
        // Construct the queue.
        public ListQueue( )
        {
            front = back = null;
        }

        // Returns true if empty, false otherwise.
        public bool IsEmpty( )
        {
            return front == null;
        }

        // Insert x into the queue.
        public void Enqueue( AnyType x )
        {
            if( IsEmpty( ) )    // Make queue of one element
                back = front = new ListNode( x );
            else                // Regular case
                back = back.next = new ListNode( x );
        }

        // Remove and returns the least recently inserted item from the queue.
        // Throws UnderflowException if the queue is empty.
        public AnyType Dequeue( )
        {
            if( IsEmpty( ) )
                throw new UnderflowException( "ListQueue dequeue" );

            AnyType returnValue = front.element;
            front = front.next;
            return returnValue;
        }

        // Returns the least recently inserted item in the queue.
        // Throws UnderflowException if the queue is empty.
        public AnyType GetFront( )
        {
            if( IsEmpty( ) )
                throw new UnderflowException( "ListQueue getFront" );
            return front.element;
        }

        // Makes the queue logically empty.
        public void MakeEmpty( )
        {
            front = null;
            back = null;
        }

        // Basic node stored in a linked list
        private class ListNode
        {
            // Constructors
            public ListNode( AnyType theElement ) : this( theElement, null )
            {
            }

            public ListNode( AnyType theElement, ListNode n )
            {
                element = theElement;
                next = n;
            }

            public AnyType element;
            public ListNode next;
        }

        private ListNode front;
        private ListNode back;
    }
}
