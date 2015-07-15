using System;
using System.IO;

public class MaxSumTest
{
    private static int seqStart = 0;
    private static int seqEnd = -1;

    // Cubic maximum contiguous subsequence sum algorithm.
    // seqStart and seqEnd represent the actual best sequence.
    public static int MaxSubSum1( int[ ] a )
    {
        int maxSum = 0;

        for( int i = 0; i < a.Length; i++ )
            for( int j = i; j < a.Length; j++ )
            {
                int thisSum = 0;

                for( int k = i; k <= j; k++ )
                    thisSum += a[ k ];

                if( thisSum > maxSum )
                {
                    maxSum = thisSum;
                    seqStart = i;
                    seqEnd = j;
                }
            }

        return maxSum;
    }

    // Quadratic maximum contiguous subsequence sum algorithm.
    // seqStart and seqEnd represent the actual best sequence.
    public static int MaxSubSum2( int[ ] a )
    {
        int maxSum = 0;

        for( int i = 0; i < a.Length; i++ )
        {
            int thisSum = 0;
            for( int j = i; j < a.Length; j++ )
            {
                thisSum += a[ j ];

                if( thisSum > maxSum )
                {
                    maxSum = thisSum;
                    seqStart = i;
                    seqEnd = j;
                }
            }
        }

        return maxSum;
    }

    // Linear-time maximum contiguous subsequence sum algorithm.
    // seqStart and seqEnd represent the actual best sequence.
    public static int MaxSubSum3( int[ ] a )
    {
        int maxSum = 0;
        int thisSum = 0;

        for( int i = 0, j = 0; j < a.Length; j++ )
        {
            thisSum += a[ j ];

            if( thisSum > maxSum )
            {
                maxSum = thisSum;
                seqStart = i;
                seqEnd = j;
            }
            else if( thisSum < 0 )
            {
                i = j + 1;
                thisSum = 0;
            }
        }

        return maxSum;
    }

    // Recursive maximum contiguous subsequence sum algorithm.
    // Finds maximum sum in subarray spanning a[left..right].
    // Does not attempt to maintain actual best sequence.
    private static int MaxSumRec( int[ ] a, int left, int right )
    {
        int maxLeftBorderSum = 0, maxRightBorderSum = 0;
        int leftBorderSum = 0, rightBorderSum = 0;
        int center = ( left + right ) / 2;

        if( left == right )  // Base case
            return a[ left ] > 0 ? a[ left ] : 0;

        int maxLeftSum = MaxSumRec( a, left, center );
        int maxRightSum = MaxSumRec( a, center + 1, right );

        for( int i = center; i >= left; i-- )
        {
            leftBorderSum += a[ i ];
            if( leftBorderSum > maxLeftBorderSum )
                maxLeftBorderSum = leftBorderSum;
        }

        for( int i = center + 1; i <= right; i++ )
        {
            rightBorderSum += a[ i ];
            if( rightBorderSum > maxRightBorderSum )
                maxRightBorderSum = rightBorderSum;
        }

        return Max3( maxLeftSum, maxRightSum,
                     maxLeftBorderSum + maxRightBorderSum );
    }

    // Return maximum of three integers.
    private static int Max3( int a, int b, int c )
    {
        return a > b ? a > c ? a : c : b > c ? b : c;
    }

    // Driver for divide-and-conquer maximum contiguous
    // subsequence sum algorithm.
    public static int MaxSubSum4( int[ ] a )
    {
        return a.Length > 0 ? MaxSumRec( a, 0, a.Length - 1 ) : 0;
    }

    // Simple test program.
    public static void Main( string[ ] args )
    {
        int[ ] a = { 4, -3, 5, -2, -1, 2, 6, -2 };
        int maxSum;

        maxSum = MaxSubSum1( a );
        Console.WriteLine( "Max sum is " + maxSum + "; it goes"
                       + " from " + seqStart + " to " + seqEnd );
        maxSum = MaxSubSum2( a );
        Console.WriteLine( "Max sum is " + maxSum + "; it goes"
                       + " from " + seqStart + " to " + seqEnd );
        maxSum = MaxSubSum3( a );
        Console.WriteLine( "Max sum is " + maxSum + "; it goes"
                       + " from " + seqStart + " to " + seqEnd );
        maxSum = MaxSubSum4( a );
        Console.WriteLine( "Max sum is " + maxSum );
    }
}
