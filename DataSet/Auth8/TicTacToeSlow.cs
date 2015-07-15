using System;
using System.Collections.Generic;


class Position
{
    private int[ , ] board;

    public Position( int[ , ] theBoard )
    {
        board = new int[ 3, 3 ];
        for( int i = 0; i < 3; i++ )
            for( int j = 0; j < 3; j++ )
                board[ i, j ] = theBoard[ i, j ];

    }

    public override bool Equals( object rhs )
    {
        if( !( rhs is Position ) )
            return false;

        Position other = (Position) rhs;

        for( int i = 0; i < 3; i++ )
            for( int j = 0; j < 3; j++ )
                if( board[ i, j ] != other.board[ i, j ] )
                    return false;
        return true;
    }

    public override int GetHashCode( )
    {
        int hashVal = 0;

        for( int i = 0; i < 3; i++ )
            for( int j = 0; j < 3; j++ )
                hashVal = hashVal * 4 + board[ i, j ];

        return hashVal;
    }
}


class TicTacToe
{
    public const int HUMAN = 0;
    public const int COMPUTER = 1;
    public const int EMPTY = 2;

    public const int HUMAN_WIN = 0;
    public const int DRAW = 1;
    public const int UNCLEAR = 2;
    public const int COMPUTER_WIN = 3;

    // Constructor
    public TicTacToe( )
    {
        ClearBoard( );
    }

    public int[ , ] GetBoard( )
    {
        return board;
    }

    // Find optimal move
    public Best ChooseMove( int side )
    {
        int opp;              // The other side
        Best reply;           // Opponent's best reply
        int simpleEval;       // Result of an immediate evaluation
        int bestRow = 0;
        int bestColumn = 0;
        int value;

        if( ( simpleEval = PositionValue( ) ) != UNCLEAR )
            return new Best( simpleEval );

        if( side == COMPUTER )
        {
            opp = HUMAN; value = HUMAN_WIN;
        }
        else
        {
            opp = COMPUTER; value = COMPUTER_WIN;
        }

        for( int row = 0; row < 3; row++ )
            for( int column = 0; column < 3; column++ )
                if( SquareIsEmpty( row, column ) )
                {
                    Place( row, column, side );
                    reply = ChooseMove( opp );
                    Place( row, column, EMPTY );

                    if( side == COMPUTER && reply.val > value ||
                        side == HUMAN && reply.val < value )
                    {
                        value = reply.val;
                        bestRow = row; bestColumn = column;
                    }
                }

        return new Best( value, bestRow, bestColumn );
    }


    // Play move, including checking legality
    public bool PlayMove( int side, int row, int column )
    {
        if( row < 0 || row >= 3 || column < 0 || column >= 3
            || board[ row, column ] != EMPTY )
            return false;
        board[ row, column ] = side;
        return true;
    }


    // Simple supporting routines
    public void ClearBoard( )
    {
        for( int i = 0; i < 3; i++ )
            for( int j = 0; j < 3; j++ )
                board[ i, j ] = EMPTY;
    }


    public bool BoardIsFull( )
    {
        for( int row = 0; row < 3; row++ )
            for( int column = 0; column < 3; column++ )
                if( board[ row, column ] == EMPTY )
                    return false;
        return true;
    }

    public bool IsAWin( int side )
    {
        int row, column;

        /* Look for all in a row */
        for( row = 0; row < 3; row++ )
        {
            for( column = 0; column < 3; column++ )
                if( board[ row, column ] != side )
                    break;
            if( column >= 3 )
                return true;
        }

        /* Look for all in a column */
        for( column = 0; column < 3; column++ )
        {
            for( row = 0; row < 3; row++ )
                if( board[ row, column ] != side )
                    break;
            if( row >= 3 )
                return true;
        }

        /* Look on diagonals */
        if( board[ 1, 1 ] == side && board[ 2, 2 ] == side
            && board[ 0, 0 ] == side )
            return true;

        if( board[ 0, 2 ] == side && board[ 1, 1 ] == side
            && board[ 2, 0 ] == side )
            return true;

        return false;
    }

    private Dictionary<Position, Int32> transpositions = new Dictionary<Position, Int32>( );
    private int[ , ] board = new int[ 3, 3 ];

    // Play a move, possibly clearing a square
    private void Place( int row, int column, int piece )
    {
        board[ row, column ] = piece;
    }

    private bool SquareIsEmpty( int row, int column )
    {
        return board[ row, column ] == EMPTY;
    }

    // Compute static value of current position (win, draw, etc.)
    private int PositionValue( )
    {
        return IsAWin( COMPUTER ) ? COMPUTER_WIN :
               IsAWin( HUMAN ) ? HUMAN_WIN :
               BoardIsFull( ) ? DRAW : UNCLEAR;
    }
}
