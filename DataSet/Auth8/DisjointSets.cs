using System;
using System.IO;

namespace weiss.nonstandard
{
    // DisjointSets class
    //
    // CONSTRUCTION: with int representing initial number of sets
    //
    // ******************PUBLIC OPERATIONS*********************
    // void Union( root1, root2 ) --> Merge two sets
    // int Find( x )              --> Return set containing x
    // ******************ERRORS********************************
    // Error checking or parameters is performed

    // Disjoint set class.
    // Does not use union heuristics or path compression.
    // Elements in the set are numbered starting at 0.
    class DisjointSetsSlow
    {

        // Construct the disjoint sets object.
        // numElements is the initial number of disjoint sets.
        public DisjointSetsSlow( int numElements )
        {
            s = new int[ numElements ];
            for( int i = 0; i < s.Length; i++ )
                s[ i ] = -1;
        }

        // Union two disjoint sets.
        // root1 and root2 are distinct and represent set names.
        // throws ArgumentException if root1 or root2 are not distinct roots.
        public void Union( int root1, int root2 )
        {
            AssertIsRoot( root1 );
            AssertIsRoot( root2 );
            if( root1 == root2 )
                throw new ArgumentException( "Union: root1 == root2 " + root1 );

            if( s[ root2 ] < s[ root1 ] )  // root2 is deeper
                s[ root1 ] = root2;        // Make root2 new root
            else
            {
                if( s[ root1 ] == s[ root2 ] )
                    s[ root1 ]--;          // Update height if same

                s[ root2 ] = root1;        // Make root1 new root
            }
        }

        // Perform a find.
        // x is the element being searched for.
        // returna the set containing x.
        // throws ArgumentException if x is not valid.
        public int Find( int x )
        {
            AssertIsItem( x );
            if( s[ x ] < 0 )
                return x;
            else
                return s[ x ] = Find( s[ x ] );
        }

        private void AssertIsRoot( int root )
        {
            AssertIsItem( root );
            if( s[ root ] >= 0 )
                throw new ArgumentException( "Union: " + root + " not a root" );
        }
        private void AssertIsItem( int x )
        {
            if( x < 0 || x >= s.Length )
                throw new ArgumentException( "Disjoint sets: " + x + " not an item" );
        }
        private int[ ] s;

        // Test main; all finds on same output line should be identical
        public static void Main( string[ ] args )
        {
            int numElements = 128;
            int numInSameSet = 16;

            DisjointSetsSlow ds = new DisjointSetsSlow( numElements );
            int set1, set2;

            for( int k = 1; k < numInSameSet; k *= 2 )
            {
                for( int j = 0; j + k < numElements; j += 2 * k )
                {
                    set1 = ds.Find( j );
                    set2 = ds.Find( j + k );
                    ds.Union( set1, set2 );
                }
            }

            for( int i = 0; i < numElements; i++ )
            {
                Console.WriteLine( ds.Find( i ) + "*" );
                if( i % numInSameSet == numInSameSet - 1 )
                    Console.WriteLine( );
            }
            Console.WriteLine( );
        }
    }
}
