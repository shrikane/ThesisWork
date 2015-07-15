using System;

namespace weiss.nonstandard
{
    // RedBlackTree class
    //
    // Implements an red-black tree.
    // Note that all "matching" is based on the CompareTo method.
    //
    // CONSTRUCTION: with no initializer, or special value used to signal
    //    unsuccessful result from Find
    //
    // ******************PUBLIC OPERATIONS*********************
    // void Insert( x )       --> Insert x
    // void Remove( x )       --> Remove x (unimplemented)
    // bool Contains( x )     --> Return true iff x is in tree
    // AnyType Find( x )      --> Return item that matches x
    // AnyType FindMin( )     --> Return smallest item
    // AnyType FindMax( )     --> Return largest item
    // bool IsEmpty( )        --> Return true if empty; else false
    // void MakeEmpty( )      --> Remove all items
    // void PrintTree( )      --> Print all items
    // ******************ERRORS********************************
    // Exceptions are thrown by insert if warranted and remove.

    public class RedBlackTree<AnyType> where AnyType : System.Collections.Generic.IComparable<AnyType>
    {
        // Construct the tree.
        public RedBlackTree( ) : this( AnyType.default )
        {
        }

        public RedBlackTree( AnyType notFound )
        {
            nullNode = new RedBlackNode( notFound );
            nullNode.left = nullNode.right = nullNode;
            header = new RedBlackNode( notFound );
            header.left = header.right = nullNode;
            itemNotFound = notFound;
        }

        // Compare item and t.element, using compareTo, with
        // caveat that if t is header, then item is always larger.
        // This routine is called if is possible that t is header.
        // If it is not possible for t to be header, use CompareTo directly.
        private int Compare( AnyType item, RedBlackNode t )
        {
            if( t == header )
                return 1;
            else
                return item.CompareTo( t.element );
        }

        // Insert into the tree.
        // item is the item to insert.
        // Throws DuplicateItemException if item is already present.
        public void Insert( AnyType item )
        {
            current = parent = grand = header;
            nullNode.element = item;

            while( Compare( item, current ) != 0 )
            {
                great = grand; grand = parent; parent = current;
                current = Compare( item, current ) < 0 ?
                            current.left : current.right;

                // Check if two red children; fix if so
                if( current.left.color == RED && current.right.color == RED )
                    HandleReorient( item );
            }

            // Insertion fails if already present
            if( current != nullNode )
                throw new DuplicateItemException( item.ToString( ) );
            current = new RedBlackNode( item, nullNode, nullNode );

            // Attach to parent
            if( Compare( item, parent ) < 0 )
                parent.left = current;
            else
                parent.right = current;
            HandleReorient( item );
        }

        // Remove from the tree.
        // x is the item to remove.
        // Throws UnsupportedOperationException if called.
        public void Remove( AnyType x )
        {
            throw new InvalidOperationException( );
        }

        // Returns the smallest item or special value if empty.
        public AnyType FindMin( )
        {
            if( IsEmpty( ) )
                return itemNotFound;

            RedBlackNode itr = header.right;

            while( itr.left != nullNode )
                itr = itr.left;

            return itr.element;
        }

        // Returns the largest item or special value if empty.
        public AnyType FindMax( )
        {
            if( IsEmpty( ) )
                return itemNotFound;

            RedBlackNode itr = header.right;

            while( itr.right != nullNode )
                itr = itr.right;

            return itr.element;
        }

        // Find an item in the tree.
        // x is the item to search for.
        // Returns the matching item or special value if not found.
        public AnyType Find( AnyType x )
        {
            nullNode.element = x;
            current = header.right;

            for( ; ; )
            {
                if( x.CompareTo( current.element ) < 0 )
                    current = current.left;
                else if( x.CompareTo( current.element ) > 0 )
                    current = current.right;
                else
                    return current.element;
            }
        }

        // Returns true if and only if x is in the tree.
        public bool Contains( AnyType x )
        {
            nullNode.element = x;
            current = header.right;
            for( ; ; )
            {
                if( x.CompareTo( current.element ) < 0 )
                    current = current.left;
                else if( x.CompareTo( current.element ) > 0 )
                    current = current.right;
                else
                    return ( current != nullNode );
            }
        }

        // Make the tree logically empty.
        public void MakeEmpty( )
        {
            header.right = nullNode;
        }

        // Print all items.
        public void PrintTree( )
        {
            PrintTree( header.right );
        }

        // Internal method to print a subtree in sorted order.
        // t is the node that roots the tree.
        private void PrintTree( RedBlackNode t )
        {
            if( t != nullNode )
            {
                PrintTree( t.left );
                Console.WriteLine( t.element );
                PrintTree( t.right );
            }
        }

        // Returns true if empty, false otherwise.
        public bool IsEmpty( )
        {
            return header.right == nullNode;
        }

        // Internal routine that is called during an insertion
        // if a node has two red children. Performs flip and rotations.
        // item is the item being inserted.
        private void HandleReorient( AnyType item )
        {
            // Do the color flip
            current.color = RED;
            current.left.color = BLACK;
            current.right.color = BLACK;

            if( parent.color == RED )   // Have to rotate
            {
                grand.color = RED;
                if( ( Compare( item, grand ) < 0 ) !=
                    ( Compare( item, parent ) < 0 ) )
                    parent = Rotate( item, grand );  // Start dbl rotate
                current = Rotate( item, great );
                current.color = BLACK;
            }
            header.right.color = BLACK; // Make root black
        }

        // Internal routine that performs a single or double rotation.
        // Because the result is attached to the parent, there are four cases.
        // Called by HandleReorient.
        // item is the item in handleReorient.
        // parent is the parent of the root of the rotated subtree.
        // Returns the root of the rotated subtree.
        private RedBlackNode Rotate( AnyType item, RedBlackNode parent )
        {
            if( Compare( item, parent ) < 0 )
            {
                if( Compare( item, parent.left ) < 0 )
                    RotateWithLeftChild( ref parent.left );    // LL
                else
                    RotateWithRightChild( ref parent.left );  // LR
                return parent.left;
            }
            else
            {
                if( Compare( item, parent.right ) < 0 )
                    RotateWithLeftChild( ref parent.right );     // RL
                else
                    RotateWithRightChild( ref parent.right );  // RR
                return parent.right;
            }
        }

        private class RedBlackNode
        {
            // Constructor
            public RedBlackNode( AnyType theElement ) : this( theElement, null, null )
            {
            }

            public RedBlackNode( AnyType theElement, RedBlackNode lt, RedBlackNode rt )
            {
                element = theElement;
                left = lt;
                right = rt;
                color = BLACK;
            }

            internal AnyType element;
            internal RedBlackNode left;
            internal RedBlackNode right;
            internal int color;      // Color
        }

        // Rotate binary tree node with left child.
        // For AVL trees, this is a single rotation for case 1.
        private static void RotateWithLeftChild( ref RedBlackNode k2 )
        {
            RedBlackNode k1 = k2.left;

            k2.left = k1.right;
            k1.right = k2;
            k2 = k1;
        }
        // Rotate binary tree node with right child.
        // For AVL trees, this is a single rotation for case 4.
        private static void RotateWithRightChild( ref RedBlackNode k1 )
        {
            RedBlackNode k2 = k1.right;

            k1.right = k2.left;
            k2.left = k1;
            k1 = k2;
        }
        private RedBlackNode header;
        private RedBlackNode nullNode;
        private AnyType itemNotFound;

        private const int BLACK = 1;    // Black must be 1
        private const int RED = 0;

        // Used in insert routine and its helpers
        private RedBlackNode current;
        private RedBlackNode parent;
        private RedBlackNode grand;
        private RedBlackNode great;
    }

}

