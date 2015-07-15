using System;

namespace weiss.nonstandard
{
    // ArrayQueue class
    //
    // Array-based implementation of the queue.
    //
    // ******************PUBLIC OPERATIONS*********************
    // void Enqueue( x )      --> Insert x
    // AnyType GetFront( )    --> Return least recently inserted item
    // AnyType Dequeue( )     --> Return and remove least recent item
    // boolean IsEmpty( )     --> Return true if empty; else false
    // void MakeEmpty( )      --> Remove all items
    // ******************ERRORS********************************
    // GetFront or Dequeue on empty queue

    public class ArrayQueue<AnyType> : IQueue<AnyType>
    {
        // Construct the queue.
        public ArrayQueue( )
        {
            theArray = new AnyType[ DEFAULT_CAPACITY ];
            MakeEmpty( );
        }

        // Tests if the queue is logically empty.
        // Returns true if empty, false otherwise.
        public bool IsEmpty( )
        {
            return currentSize == 0;
        }

        // Makes the queue logically empty.
        public void MakeEmpty( )
        {
            currentSize = 0;
            front = 0;
            back = -1;
        }

        // Removes and returns the least recently inserted item from the queue.
        // Throws UnderflowException if the queue is empty.
        public AnyType Dequeue( )
        {
            if( IsEmpty( ) )
                throw new UnderflowException( "ArrayQueue dequeue" );
            currentSize--;

            AnyType returnValue = theArray[ front ];
            Increment( ref front );
            return returnValue;
        }

        // Returns the least recently inserted item in the queue.
        // Throws UnderflowException if the queue is empty.
        public AnyType GetFront( )
        {
            if( IsEmpty( ) )
                throw new UnderflowException( "ArrayQueue getFront" );
            return theArray[ front ];
        }

        // Inserts x into the queue.
        public void Enqueue( AnyType x )
        {
            if( currentSize == theArray.Length )
                DoubleQueue( );
            Increment( ref back );
            theArray[ back ] = x;
            currentSize++;
        }

        // Internal method to increment with wraparound.
        // x is any index in theArray's range.
        // Returns x+1, or 0 if x is at the end of theArray.
        private void Increment( ref int x )
        {
            if( ++x == theArray.Length )
                x = 0;
        }

        // Internal method to expand theArray.
        private void DoubleQueue( )
        {
            AnyType[ ] newArray = new AnyType[ theArray.Length * 2 + 1 ];

            // Copy elements that are logically in the queue
            for( int i = 0; i < currentSize; i++, Increment( ref front ) )
                newArray[ i ] = theArray[ front ];

            theArray = newArray;
            front = 0;
            back = currentSize - 1;
        }

        private AnyType[ ] theArray;
        private int currentSize;
        private int front;
        private int back;

        private const int DEFAULT_CAPACITY = 10;
    }
}
