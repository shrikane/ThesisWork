
namespace weiss.nonstandard
{
    public class Rotations
    {
        // Rotate binary tree node with left child.
        // For AVL trees, this is a single rotation for case 1.
        public static void RotateWithLeftChild<AnyType>( ref BinaryNode<AnyType> k2 )
        {
            BinaryNode<AnyType> k1 = k2.left;
            k2.left = k1.right;
            k1.right = k2;
            k2 = k1;
        }

        // Rotate binary tree node with right child.
        // For AVL trees, this is a single rotation for case 4.
        public static void RotateWithRightChild<AnyType>( ref BinaryNode<AnyType> k1 )
        {
            BinaryNode<AnyType> k2 = k1.right;
            k1.right = k2.left;
            k2.left = k1;
            k1 = k2;
        }

        // Double rotate binary tree node: first left child
        // with its right child; then node k3 with new left child.
        // For AVL trees, this is a double rotation for case 2.
        public static void DoubleRotateWithLeftChild<AnyType>( ref BinaryNode<AnyType> k3 )
        {
            RotateWithRightChild( ref k3.left );
            RotateWithLeftChild( ref k3 );
        }

        // Double rotate binary tree node: first right child
        // with its left child; then node k1 with new right child.
        // For AVL trees, this is a double rotation for case 3.
        public static void DoubleRotateWithRightChild<AnyType>( ref BinaryNode<AnyType> k1 )
        {
            RotateWithLeftChild( ref k1.right );
            RotateWithRightChild( ref k1 );
        }
    }
}
