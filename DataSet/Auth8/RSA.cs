using System;

public class RSA
{
    // Sample of how RSA works.
    // Note that n * n should not overflow a long
    // This limits x*y to about 2^15.
    public static void Main( string[ ] args )
    {
        long x = 25000;
        long y = 30000;
        long message = 37373737;

        long p, q, n, nPrime, e, d;

        for( p = x; !Numerical.IsPrime( p ); p++ )
            ;
        Console.WriteLine( "p: " + p );
        for( q = y + 2; !Numerical.IsPrime( q ); q++ )
            ;
        Console.WriteLine( "q: " + q );

        n = p * q;
        Console.WriteLine( "n: " + n );

        nPrime = ( p - 1 ) * ( q - 1 );
        Console.WriteLine( "nPrime: " + nPrime );

        for( e = nPrime / 10; Numerical.Gcd( e, nPrime ) != 1; e++ )
            ;
        Console.WriteLine( "e: " + e );

        d = Numerical.Inverse( e, nPrime );
        Console.WriteLine( "d: " + d );

        Console.WriteLine( "Verify inverse: " + ( e * d % ( nPrime ) ) );

        Console.WriteLine( "message: " + message );
        long code = Numerical.Power( message, e, n );
        long decode = Numerical.Power( code, d, n );

        Console.WriteLine( "Code: " + code );
        Console.WriteLine( "Decode: " + decode );
        if( message != decode )
            Console.WriteLine( "OOPS: " );
        else
            Console.WriteLine( "Success!!!!" );
    }
}
