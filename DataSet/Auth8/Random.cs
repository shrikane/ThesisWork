using System;

namespace weiss
{

    // Random class
    // Random number class, using a 31-bit
    // linear congruential generator.
    //
    // CONSTRUCTION: with (a) no initializer or (b) an integer
    //     that specifies the initial state of the generator.
    //     This random number generator is really only 31 bits,
    //     so it is weaker than the one in java.util.
    //
    // ******************PUBLIC OPERATIONS*********************
    //     Return a random number according to some distribution:
    // int Next( )                             --> Uniform, [1 to 2^31-1]
    // int NextDouble( )                       --> Uniform, (0 to 1)
    // int Next( int high )                    --> Uniform [0..high)
    // int Next( int low, int high )           --> Uniform [low..high]
    // int NextPoisson( double expectedVal )   --> Poisson
    // double NextNegExp( double expectedVal ) --> Negative exponential
    // void Permute( Object [ ] a )            --> Randomly permutate

    public class Random
    {
        private const int A = 48271;
        private const int M = 2147483647;
        private const int Q = M / A;
        private const int R = M % A;

        // Construct this Random object with
        // initial state obtained from system clock.
        public Random( ) : this( System.Environment.TickCount )
        {
        }

        // Construct this Random object with
        // specified initial state.
        public Random( int initialValue )
        {
            if( initialValue < 0 )
                initialValue += M;

            state = initialValue;
            if( state == 0 )
                state = 1;
        }

        // Return a pseudorandom int, and change the internal state.
        public int Next( )
        {
            int tmpState = A * ( state % Q ) - R * ( state / Q );
            if( tmpState >= 0 )
                state = tmpState;
            else
                state = tmpState + M;

            return state;
        }

        // Return a pseudorandom int in range [0..high), and change the internal state.
        public int Next( int high )
        {
            return Next( ) % high;
        }

        // Return a pseudorandom int, and change the
        // internal state. DOES NOT WORK.
        public int NextWRONG( )
        {
            return state = ( A * state ) % M;
        }

        // Return a pseudorandom double in the open range 0..1
        // and change the internal state.
        public double NextDouble( )
        {
            return (double) Next( ) / M;
        }

        // Return an int in the closed range [low,high], and
        // change the internal state.
        public int Next( int low, int high )
        {
            double partitionSize = (double) M / ( high - low + 1 );

            return (int) ( Next( ) / partitionSize ) + low;
        }

        // Return an int using a Poisson distribution, and
        // change the internal state.
        // expectedValue is the mean of the distribution.
        public int NextPoisson( double expectedValue )
        {
            double limit = -expectedValue;
            double product = Math.Log( NextDouble( ) );
            int count;

            for( count = 0; product > limit; count++ )
                product += Math.Log( NextDouble( ) );

            return count;
        }

        // Return a double using a negative exponential
        // distribution, and change the internal state.
        // expectedValue is the mean of the distribution.
        public double NextNegExp( double expectedValue )
        {
            return -expectedValue * Math.Log( NextDouble( ) );
        }

        // Method to swap two elements
        private static void Swap<AnyType>( ref AnyType x, ref AnyType y )
        {
            AnyType tmp = x;
            x = y;
            y = tmp;
        }

        // Randomly rearrange an array.
        // The random numbers used depend on the time and day.
        public static void Permute<AnyType>( AnyType[ ] a )
        {
            Random r = new Random( );

            for( int j = 1; j < a.Length; j++ )
                Swap( ref a[ j ], ref a[ r.Next( 0, j ) ] );
        }

        private int state;

        // Test program
        /*
        public static void Main( string [ ] args )
        {
            Random r = new Random( );

            for( int i = 0; i < 20; i++ )
                Console.WriteLine( r.Next( ) );
                
            int [ ] dist = new int[ 10000 ];
            
            const int SAMPLES = 1000000;
            for( int i = 0; i < SAMPLES; i++ )
                dist[ r.NextPoisson( 2 ) ]++;
            for( int i = 0; i < 10; i++ )
                Console.WriteLine( i + ": " +  dist[ i ] / (double) SAMPLES );    
        }
        */
    }
}
