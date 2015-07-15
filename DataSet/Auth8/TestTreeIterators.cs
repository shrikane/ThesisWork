using System;

using weiss.nonstandard;

// TreeIterator class; maintains "current position"
//
// CONSTRUCTION: with tree to which iterator is bound
//
// ******************PUBLIC OPERATIONS**********************
//     First and Advance are abstract; others are not overrideable
// bool IsValid( )      --> True if at valid position in tree
// AnyType Retrieve( )  --> Return item in current position
// void First( )        --> Set current position to first
// void Advance( )      --> Advance (prefix)
// ******************ERRORS*********************************
// Exceptions thrown for illegal access or advance

public abstract class TreeIterator<AnyType>
{
    // Construct the iterator.
    // The current position is set to null.
    // theTree is the tree to which the iterator is
    //     permanently bound.
    public TreeIterator( BinaryTree<AnyType> theTree )
    {
        t = theTree;
        current = null;
    }

    // Set the current position to the first item, according
    // to the traversal scheme.
    public abstract void First( );

    // Returns true if the current position is not null; false otherwise.
    public bool IsValid( )
    {
        return current != null;
    }

    // Return the item stored in the current position.
    // Throws NoSuchElementException if the current position is invalid.
    public AnyType Retrieve( )
    {
        if( current == null )
            throw new IndexOutOfRangeException( "TreeIterator retrieve" );
        return current.Element;
    }

    // Advance the current position to the next node in the tree,
    //     according to the traversal scheme.
    // If the current position is null, then throw an exception.
    // This is the alternate strategy, that we did not use for lists.
    // Throws NoSuchElementException if the current position is null.
    public abstract void Advance( );

    protected BinaryTree<AnyType> t;        // Tree
    protected BinaryNode<AnyType> current;  // Current position
}


// PostOrder class; maintains "current position"
//     according to a postorder traversal
// 
// CONSTRUCTION: with tree to which iterator is bound
//
// ******************PUBLIC OPERATIONS**********************
// bool IsValid( )      --> True if at valid position in tree
// AnyType Retrieve( )  --> Return item in current position
// void First( )        --> Set current position to first
// void Advance( )      --> Advance (prefix)
// ******************ERRORS*********************************
// Exceptions thrown for illegal access or advance

class PostOrder<AnyType> : TreeIterator<AnyType>
{
    // Construct the iterator.
    // The current position is set to null.
    // theTree is the tree to which the iterator is
    //     permanently bound.
    public PostOrder( BinaryTree<AnyType> theTree ) : base( theTree )
    {
        s = new ArrayStack<StNode>( );
        s.Push( new StNode( t.Root ) );
    }

    // Set the current position to the first item, according
    // to the postorder traversal scheme.
    public override void First( )
    {
        s.MakeEmpty( );
        if( t.Root != null )
        {
            s.Push( new StNode( t.Root ) );
            Advance( );
        }
    }

    // Advance the current position to the next node in the tree,
    //     according to the postorder traversal scheme.
    // Throws NoSuchElementException if iteration has
    //     been exhausted prior to the call.
    public override void Advance( )
    {
        if( s.IsEmpty( ) )
        {
            if( current == null )
                throw new IndexOutOfRangeException( "PostOrder Advance" );
            current = null;
            return;
        }

        StNode cnode;

        for( ; ; )
        {
            cnode = s.TopAndPop( );


            if( ++cnode.timesPopped == 3 )
            {
                current = cnode.node;
                return;
            }

            s.Push( cnode );
            if( cnode.timesPopped == 1 )
            {
                if( cnode.node.Left != null )
                    s.Push( new StNode( cnode.node.Left ) );
            }
            else  // cnode.timesPopped == 2
            {
                if( cnode.node.Right != null )
                    s.Push( new StNode( cnode.node.Right ) );
            }
        }
    }

    // An internal class for tree iterators
    protected class StNode
    {
        public BinaryNode<AnyType> node;
        public int timesPopped;

        public StNode( BinaryNode<AnyType> n )
        {
            node = n;
            timesPopped = 0;
        }
    }
    /** An internal stack if visited nodes. */




















































    protected Stack<StNode> s;    // The stack of StNode objects
}


// InOrder class; maintains "current position"
//     according to an inorder traversal
// 
// CONSTRUCTION: with tree to which iterator is bound
//
// ******************PUBLIC OPERATIONS**********************
// bool    IsValid( )   --> True if at valid position in tree
// AnyType Retrieve( )  --> Return item in current position
// void First( )        --> Set current position to first
// void Advance( )      --> Advance (prefix)
// ******************ERRORS*********************************
// Exceptions thrown for illegal access or advance

class InOrder<AnyType> : PostOrder<AnyType>
{
    // Construct the iterator.
    // The current position is set to null.
    // theTree is the tree to which the iterator is
    //     permanently bound.
    public InOrder( BinaryTree<AnyType> theTree ) : base( theTree )
    {
    }

    // Advance the current position to the next node in the tree,
    //     according to the inorder traversal scheme.
    // Throws NoSuchElementException if iteration has
    //     been exhausted prior to the call.
    public override void Advance( )
    {
        if( s.IsEmpty( ) )
        {
            if( current == null )
                throw new IndexOutOfRangeException( "InOrder advance" );
            current = null;
            return;
        }

        StNode cnode;

        for( ; ; )
        {
            cnode = s.TopAndPop( );

            if( ++cnode.timesPopped == 2 )
            {
                current = cnode.node;
                if( cnode.node.Right != null )
                    s.Push( new StNode( cnode.node.Right ) );
                return;
            }

            // First time through
            s.Push( cnode );
            if( cnode.node.Left != null )
                s.Push( new StNode( cnode.node.Left ) );
        }
    }
}


// PreOrder class; maintains "current position"
//     according to a preorder traversal
// 
// CONSTRUCTION: with tree to which iterator is bound
//
// ******************PUBLIC OPERATIONS**********************
// bool IsValid( )      --> True if at valid position in tree
// AnyType Retrieve( )  --> Return item in current position
// void First( )        --> Set current position to first
// void Advance( )      --> Advance (prefix)
// ******************ERRORS*********************************
// Exceptions thrown for illegal access or advance

class PreOrder<AnyType> : TreeIterator<AnyType>
{
    // Construct the iterator.
    // The current position is set to null.
    // theTree is the tree to which the iterator is
    //     permanently bound.
    public PreOrder( BinaryTree<AnyType> theTree ) : base( theTree )
    {
        s = new ArrayStack<BinaryNode<AnyType>>( );
        s.Push( t.Root );
    }

    // Set the current position to the first item, according
    // to the preorder traversal scheme.
    public override void First( )
    {
        s.MakeEmpty( );
        if( t.Root != null )
        {
            s.Push( t.Root );
            Advance( );
        }
    }

    // Advance the current position to the next node in the tree,
    //     according to the preorder traversal scheme.
    // Throws NoSuchElementException if iteration has
    //     been exhausted prior to the call.
    public override void Advance( )
    {
        if( s.IsEmpty( ) )
        {
            if( current == null )
                throw new IndexOutOfRangeException( "PreOrder Advance" );
            current = null;
            return;
        }

        current = s.TopAndPop( );

        if( current.Right != null )
            s.Push( current.Right );
        if( current.Left != null )
            s.Push( current.Left );
    }

    private Stack<BinaryNode<AnyType>> s;    // Stack of TreeNode objects
}


// LevelOrder class; maintains "current position"
//     according to a level-order traversal
// 
// CONSTRUCTION: with tree to which iterator is bound
//
// ******************PUBLIC OPERATIONS**********************
// bool IsValid( )      --> True if at valid position in tree
// AnyType Retrieve( )  --> Return item in current position
// void First( )        --> Set current position to first
// void Advance( )      --> Advance (prefix)
// ******************ERRORS*********************************
// Exceptions thrown for illegal access or advance

class LevelOrder<AnyType> : TreeIterator<AnyType>
{
    // Construct the iterator.
    // The current position is set to null.
    //theTree is the tree to which the iterator is
    //     permanently bound.
    public LevelOrder( BinaryTree<AnyType> theTree ) : base( theTree )
    {
        q = new ArrayQueue<BinaryNode<AnyType>>( );
        q.Enqueue( t.Root );
    }

    // Set the current position to the first item, according
    // to the level-order traversal scheme.
    public override void First( )
    {
        q.MakeEmpty( );
        if( t.Root != null )
        {
            q.Enqueue( t.Root );
            Advance( );
        }
    }

    // Advance the current position to the next node in the tree,
    //     according to the level-order traversal scheme.
    // Throws NoSuchElementException if iteration has
    //     been exhausted prior to the call.
    public override void Advance( )
    {
        if( q.IsEmpty( ) )
        {
            if( current == null )
                throw new IndexOutOfRangeException( "LevelOrder advance" );
            current = null;
            return;
        }

        current = q.Dequeue( );

        if( current.Left != null )
            q.Enqueue( current.Left );
        if( current.Right != null )
            q.Enqueue( current.Right );
    }

    private Queue<BinaryNode<AnyType>> q;  // Queue of TreeNode objects
}

public class TestTreeIterators
{
    // Test program
    public static void Main( string[ ] args )
    {
        BinaryTree<int> t = new BinaryTree<int>( );

        TestItr( "PreOrder", new PreOrder<int>( t ) ); // Test empty tree

        BinaryTree<int> t1 = new BinaryTree<int>( 1 );
        BinaryTree<int> t3 = new BinaryTree<int>( 3 );
        BinaryTree<int> t5 = new BinaryTree<int>( 5 );
        BinaryTree<int> t7 = new BinaryTree<int>( 7 );
        BinaryTree<int> t2 = new BinaryTree<int>( );
        BinaryTree<int> t4 = new BinaryTree<int>( );
        BinaryTree<int> t6 = new BinaryTree<int>( );

        t2.Merge( 2, t1, t3 );
        t6.Merge( 6, t5, t7 );
        t4.Merge( 4, t2, t6 );

        t = t4;

        TestItr( "Preorder", new PreOrder<int>( t ) );
        TestItr( "Postorder", new PostOrder<int>( t ) );
        TestItr( "Inorder", new InOrder<int>( t ) );
        TestItr( "Level order", new LevelOrder<int>( t ) );
    }

    public static void TestItr<AnyType>( string type, TreeIterator<AnyType> itr )
    {
        try
        {
            Console.WriteLine( type + ":" );
            for( itr.First( ); itr.IsValid( ); itr.Advance( ) )
                Console.Write( " " + itr.Retrieve( ) );
            Console.WriteLine( );
            itr.Advance( );
        }
        catch( IndexOutOfRangeException e )
        { Console.WriteLine( e + " (as expected)" ); }
    }
}