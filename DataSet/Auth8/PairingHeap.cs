using System;
using System.Collections.Generic;

namespace weiss.nonstandard
{
    // PairingHeap class
    // Implements a pairing heap.
    // Supports a DecreaseKey operation.
    // Note that all "matching" is based on the CompareTo method.
    //
    // CONSTRUCTION: with no initializer
    //
    // ******************PUBLIC OPERATIONS*********************
    // IPosition Insert( x )  --> Insert x, return position
    // AnyType DeleteMin( )--> Return and remove smallest item
    // AnyType FindMin( )  --> Return smallest item
    // bool IsEmpty( )     --> Return true if empty; else false
    // int Size( )            --> Return size of priority queue
    // void MakeEmpty( )      --> Remove all items
    // void DecreaseKey( IPosition p, newVal )
    //                        --> Decrease value in node p
    // ******************ERRORS********************************
    // Exceptions thrown for various operations

    public class PairingHeap<AnyType> : IPriorityQueue<AnyType> where AnyType : IComparable<AnyType>
    {
        // Construct the pairing heap.
        public PairingHeap( )
        {
            root = null;
            theSize = 0;
        }

        // Insert into the priority queue, and return an IPriorityQueuePosition
        // that can be used by decreaseKey.
        // Duplicates are allowed.
        // x is the item to insert.
        // returns the node containing the newly inserted item.
        public IPriorityQueuePosition<AnyType> Insert( AnyType x )
        {
            PairNode newNode = new PairNode( x );

            if( root == null )
                root = newNode;
            else
                root = CompareAndLink( root, newNode );

            theSize++;
            return newNode;
        }

        // Returns the smallest item in the priority queue.
        // Throws UnderflowException if pairing heap is empty.
        public AnyType FindMin( )
        {
            if( IsEmpty( ) )
                throw new UnderflowException( "Pairing heap is empty" );
            return root.element;
        }

        // Remove and returns the smallest item from the priority queue.
        // Throws UnderflowException if pairing heap is empty.
        public AnyType DeleteMin( )
        {
            if( IsEmpty( ) )
                throw new UnderflowException( "Pairing heap is empty" );

            AnyType x = FindMin( );
            if( root.leftChild == null )
                root = null;
            else
                root = CombineSiblings( root.leftChild );

            theSize--;
            return x;
        }

        // Changes the value of the item stored in the pairing heap.
        // pos is any Position returned by insert.
        // newVal is the new value, which must be smaller
        //    than the currently stored value.
        // Throws ArgumentException if pos is null.
        // Throws IllegalValueException if new value is larger than old.
        public void DecreaseKey( IPriorityQueuePosition<AnyType> pos, AnyType newVal )
        {
            if( pos == null )
                throw new ArgumentException( "null Position passed to decreaseKey" );

            PairNode p = (PairNode) pos;

            if( p.element.CompareTo( newVal ) < 0 )
                throw new IllegalValueException( "newVal/oldval: " + newVal + " /" + p.element );
            p.element = newVal;
            if( p != root )
            {
                if( p.nextSibling != null )
                    p.nextSibling.prev = p.prev;
                if( p.prev.leftChild == p )
                    p.prev.leftChild = p.nextSibling;
                else
                    p.prev.nextSibling = p.nextSibling;

                p.nextSibling = null;
                root = CompareAndLink( root, p );
            }
        }

        // Test if the priority queue is logically empty.
        // Returns true if empty, false otherwise.
        public bool IsEmpty( )
        {
            return root == null;
        }

        // Returns the number of items stored in the priority queue.
        public int Size( )
        {
            return theSize;
        }

        // Makes the priority queue logically empty.
        public void MakeEmpty( )
        {
            root = null;
            theSize = 0;
        }

        // Private  class for use with PairHeap.
        private class PairNode : IPriorityQueuePosition<AnyType>
        {
            // Constructs the PairNode.
            // theElement is the value stored in the node.
            public PairNode( AnyType theElement )
            {
                element = theElement;
                leftChild = null;
                nextSibling = null;
                prev = null;
            }

            // Returns the value stored at this position.
            public AnyType GetValue( )
            {
                return element;
            }

            // Friendly data; accessible by other package routines
            public AnyType element;
            public PairNode leftChild;
            public PairNode nextSibling;
            public PairNode prev;
        }

        private PairNode root;
        private int theSize;

        // Internal method that is the basic operation to maintain order.
        // Links first and second together to satisfy heap order.
        // first is root of tree 1, which may not be null.
        //    first.nextSibling MUST be null on entry.
        // second is root of tree 2, which may be null.
        // returns result of the tree merge.
        private PairNode CompareAndLink( PairNode first, PairNode second )
        {
            if( second == null )
                return first;

            if( second.element.CompareTo( first.element ) < 0 )
            {
                // Attach first as leftmost child of second
                second.prev = first.prev;
                first.prev = second;
                first.nextSibling = second.leftChild;
                if( first.nextSibling != null )
                    first.nextSibling.prev = first;
                second.leftChild = first;
                return second;
            }
            else
            {
                // Attach second as leftmost child of first
                second.prev = first;
                first.nextSibling = second.nextSibling;
                if( first.nextSibling != null )
                    first.nextSibling.prev = first;
                second.nextSibling = first.leftChild;
                if( second.nextSibling != null )
                    second.nextSibling.prev = second;
                first.leftChild = second;
                return first;
            }
        }

        private PairNode[ ] DoubleIfFull( PairNode[ ] array, int index )
        {
            if( index == array.Length )
            {
                PairNode[ ] oldArray = array;

                array = new PairNode[ index * 2 ];
                for( int i = 0; i < index; i++ )
                    array[ i ] = oldArray[ i ];
            }
            return array;
        }

        // The tree array for combineSiblings
        private PairNode[ ] treeArray = new PairNode[ 5 ];

        /**
        * Internal method that implements two-pass merging.
        * @param firstSibling the root of the conglomerate;
        *     assumed not null.
        */






















































































































































































































































































































        private PairNode CombineSiblings( PairNode firstSibling )
        {
            if( firstSibling.nextSibling == null )
                return firstSibling;

            // Store the subtrees in an array
            int numSiblings = 0;
            for( ; firstSibling != null; numSiblings++ )
            {
                treeArray = DoubleIfFull( treeArray, numSiblings );
                treeArray[ numSiblings ] = firstSibling;
                firstSibling.prev.nextSibling = null;  // break links
                firstSibling = firstSibling.nextSibling;
            }
            treeArray = DoubleIfFull( treeArray, numSiblings );
            treeArray[ numSiblings ] = null;

            // Combine subtrees two at a time, going left to right
            int i = 0;
            for( ; i + 1 < numSiblings; i += 2 )
                treeArray[ i ] = CompareAndLink( treeArray[ i ], treeArray[ i + 1 ] );

            int j = i - 2;

            // j has the result of last compareAndLink.
            // If an odd number of trees, get the last one.
            if( j == numSiblings - 3 )
                treeArray[ j ] = CompareAndLink( treeArray[ j ], treeArray[ j + 2 ] );

            // Now go right to left, merging last tree with
            // next to last. The result becomes the new last.
            for( ; j >= 2; j -= 2 )
                treeArray[ j - 2 ] = CompareAndLink( treeArray[ j - 2 ], treeArray[ j ] );

            return treeArray[ 0 ];
        }
    }
}