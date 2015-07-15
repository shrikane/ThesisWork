using System;

public class TestBinaryTree
{
    public static void Main( string[ ] args )
    {
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
        Console.WriteLine( "t4 should be perfect 1-7; t2 empty" );
        Console.WriteLine( "----------------" );
        Console.WriteLine( "t4" );
        t4.PrintInOrder( );
        Console.WriteLine( "----------------" );
        Console.WriteLine( "t2" );
        t2.PrintInOrder( );
        Console.WriteLine( "----------------" );
        Console.WriteLine( "t4 size: " + t4.Size( ) );
        Console.WriteLine( "t4 height: " + t4.Height( ) );
    }
}