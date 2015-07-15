using System;

namespace weiss.nonstandard
{
    // ListStack class
    // Linked list-based implementation of the stack.
    //
    // CONSTRUCTION: with no initializer
    //
    // ******************PUBLIC OPERATIONS*********************
    // void Push( x )         --> Insert x
    // void Pop( )            --> Remove most recently inserted item
    // AnyType Top( )         --> Return most recently inserted item
    // AnyType TopAndPop( )   --> Return and remove most recent item
    // boolean IsEmpty( )     --> Return true if empty; else false
    // void MakeEmpty( )      --> Remove all items
    // ******************ERRORS********************************
    // Top, Pop, or TopAndPop on empty stack

    public class ListStack<AnyType> : IStack<AnyType>
    {
        // Construct the stack.
        public ListStack( )
        {
            topOfStack = null;
        }

        // Returns true if empty, false otherwise.
        public bool IsEmpty( )
        {
            return topOfStack == null;
        }

        // Makes the stack logically empty.
        public void MakeEmpty( )
        {
            topOfStack = null;
        }

        //Insert x into the stack.
        public void Push( AnyType x )
        {
            topOfStack = new ListNode( x, topOfStack );
        }

        // Removes the most recently inserted item from the stack.
        // Throws UnderflowException if the stack is empty.
        public void Pop( )
        {
            if( IsEmpty( ) )
                throw new UnderflowException( "ListStack pop" );
            topOfStack = topOfStack.next;
        }

        // Returns the most recently inserted item in the stack.
        // Throws UnderflowException if the stack is empty.
        public AnyType Top( )
        {
            if( IsEmpty( ) )
                throw new UnderflowException( "ListStack top" );
            return topOfStack.element;
        }

        // Removes and returns the most recently inserted item from the stack.
        // Throws UnderflowException if the stack is empty.
        public AnyType TopAndPop( )
        {
            if( IsEmpty( ) )
                throw new UnderflowException( "ListStack topAndPop" );

            AnyType topItem = topOfStack.element;
            topOfStack = topOfStack.next;
            return topItem;
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

        private ListNode topOfStack;
    }
}
