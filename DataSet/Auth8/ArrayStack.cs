using System;

namespace weiss.nonstandard
{
    // ArrayStack class
    // Array-based implementation of the stack.
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

    public class ArrayStack<AnyType> : IStack<AnyType>
    {
        // Construct the stack.
        public ArrayStack( )
        {
            theArray = new AnyType[ DEFAULT_CAPACITY ];
            topOfStack = -1;
        }

        // Returns true if empty, false otherwise.
        public bool IsEmpty( )
        {
            return topOfStack == -1;
        }

        // Makes the stack logically empty.
        public void MakeEmpty( )
        {
            topOfStack = -1;
        }

        // Return the most recently inserted item in the stack.
        // Throws UnderflowException if the stack is empty.
        public AnyType Top( )
        {
            if( IsEmpty( ) )
                throw new UnderflowException( "ArrayStack top" );
            return theArray[ topOfStack ];
        }

        // Removes the most recently inserted item from the stack.
        // Throws UnderflowException if the stack is empty.
        public void Pop( )
        {
            if( IsEmpty( ) )
                throw new UnderflowException( "ArrayStack pop" );
            topOfStack--;
        }

        // Returns and remove the most recently inserted item from the stack.
        // Tthrows Underflow if the stack is empty.
        public AnyType TopAndPop( )
        {
            if( IsEmpty( ) )
                throw new UnderflowException( "ArrayStack topAndPop" );
            return theArray[ topOfStack-- ];
        }

        // Insert a x into the stack.
        public void Push( AnyType x )
        {
            if( topOfStack + 1 == theArray.Length )
                DoubleArray( );
            theArray[ ++topOfStack ] = x;
        }

        // Internal method to extend theArray.
        private void DoubleArray( )
        {
            AnyType[ ] newArray;

            newArray = new AnyType[ theArray.Length * 2 ];
            for( int i = 0; i < theArray.Length; i++ )
                newArray[ i ] = theArray[ i ];
            theArray = newArray;
        }

        private AnyType[ ] theArray;
        private int topOfStack;

        private const int DEFAULT_CAPACITY = 10;
    }
}
