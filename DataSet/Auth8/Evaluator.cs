using System;
using System.IO;
using weiss.Collections.Generic;

// Evaluator class interface: evaluate infix expressions
//
// CONSTRUCTION: with a string
//
// ******************PUBLIC OPERATIONS***********************
// long GetValue( )      --> Return value of infix expression
// ******************ERRORS**********************************
// Some error checking is performed


public class Evaluator
{
    private const int EOL = 0;
    private const int VALUE = 1;
    private const int OPAREN = 2;
    private const int CPAREN = 3;
    private const int EXP = 4;
    private const int MULT = 5;
    private const int DIV = 6;
    private const int PLUS = 7;
    private const int MINUS = 8;

    private class Precedence
    {
        public int inputSymbol;
        public int topOfStack;

        public Precedence( int inSymbol, int topSymbol )
        {
            inputSymbol = inSymbol;
            topOfStack = topSymbol;
        }
    }

    // PrecTable matches order of Token enumeration
    private static Precedence[ ] precTable = new Precedence[ ]
    {
        new Precedence(   0, -1 ),  // EOL
        new Precedence(   0,  0 ),  // VALUE
        new Precedence( 100,  0 ),  // OPAREN
        new Precedence(   0, 99 ),  // CPAREN
        new Precedence(   6,  5 ),  // EXP
        new Precedence(   3,  4 ),  // MULT
        new Precedence(   3,  4 ),  // DIV
        new Precedence(   1,  2 ),  // PLUS
        new Precedence(   1,  2 )   // MINUS
    };

    private class Token
    {
        public Token( ) : this( EOL )
        {
        }

        public Token( int t ) : this( t, 0 )
        {
        }

        public Token( int t, long v )
        {
            type = t;
            val = v;
        }

        public int Type
        {
            get { return type; }
        }

        public long Value
        {
            get { return val; }
        }

        private int type = EOL;
        private long val = 0;
    }

    private class EvalTokenizer
    {
        string[ ] DELIMETERS = new string[ ] { "^", "/", "*", "(", ")", "+", "-" };

        public EvalTokenizer( string oneLine )
        {
            foreach( string s in DELIMETERS )
                oneLine = oneLine.Replace( s, " " + s + " " );

            tokens = oneLine.Split( );
            nextTokenIndex = 0;
        }

        public Token GetToken( )
        {
            long theValue;

            if( nextTokenIndex >= tokens.Length )
                return new Token( );

            string s = tokens[ nextTokenIndex++ ];
            if( s == " " ) return GetToken( );
            if( s == "^" ) return new Token( EXP );
            if( s == "/" ) return new Token( DIV );
            if( s == "*" ) return new Token( MULT );
            if( s == "(" ) return new Token( OPAREN );
            if( s == ")" ) return new Token( CPAREN );
            if( s == "+" ) return new Token( PLUS );
            if( s == "-" ) return new Token( MINUS );

            try
            { theValue = long.Parse( s ); }
            catch( FormatException )
            {
                Console.Error.WriteLine( "Parse error" );
                return new Token( );
            }

            return new Token( VALUE, theValue );
        }

        private string[ ] tokens;
        private int nextTokenIndex;
    }

    // Construct an evaluator object.
    // s is the string containing the expression.
    public Evaluator( string s )
    {
        opStack = new Stack<int>( );
        postfixStack = new Stack<long>( );

        str = s;

        opStack.Push( EOL );
    }

    // The only publicly visible routine

    /** 
     * Public routine that performs the evaluation.
     * Examine the  postfix machine to see if a single result is
     * left and if so, return it; otherwise print error.
     * @return the result.
     */

















































































































































    public long GetValue( )
    {
        EvalTokenizer tok = new EvalTokenizer( str );
        Token lastToken;

        do
        {
            lastToken = tok.GetToken( );
            ProcessToken( lastToken );
        } while( lastToken.Type != EOL );

        if( postfixStack.Count == 0 )
        {
            Console.Error.WriteLine( "Missing operand!" );
            return 0;
        }

        long theResult = postfixStack.Pop( );
        if( postfixStack.Count != 0 )
            Console.Error.WriteLine( "Warning: missing operators!" );

        return theResult;
    }


    private Stack<int> opStack;       // Operator stack for conversion
    private Stack<long> postfixStack;  // Stack for postfix machine
    private string str;           // string being evaluated

    // After a token is read, use operator precedence parsing
    // algorithm to process it; missing opening parentheses
    // are detected here.
    private void ProcessToken( Token lastToken )
    {
        int topOp;
        int lastType = lastToken.Type;


        switch( lastType )
        {
            case VALUE:
                postfixStack.Push( lastToken.Value );
                return;

            case CPAREN:
                while( ( topOp = opStack.Peek( ) ) != OPAREN && topOp != EOL )
                    BinaryOp( topOp );
                if( topOp == OPAREN )
                    opStack.Pop( );  // Get rid of opening parentheseis
                else
                    Console.Error.WriteLine( "Missing open parenthesis" );
                break;

            default:    // General operator case
                while( precTable[ lastType ].inputSymbol <=
                       precTable[ topOp = opStack.Peek( ) ].topOfStack )
                    BinaryOp( topOp );
                if( lastType != EOL )
                    opStack.Push( lastType );
                break;
        }
    }

    // topAndPop the postfix machine stack; return the result.
    // If the stack is empty, print an error message.
    private long GetTop( )
    {
        if( postfixStack.Count == 0 )
        {
            Console.Error.WriteLine( "Missing operand" );
            return 0;
        }
        return postfixStack.Pop( );
    }

    // Internal routine to compute x^n.
    private static long Pow( long x, long n )
    {
        if( x == 0 )
        {
            if( n == 0 )
                Console.Error.WriteLine( "0^0 is undefined" );
            return 0;
        }
        if( n < 0 )
        {
            Console.Error.WriteLine( "Negative exponent" );
            return 0;
        }
        if( n == 0 )
            return 1;
        if( n % 2 == 0 )
            return Pow( x * x, n / 2 );
        else
            return x * Pow( x, n - 1 );
    }

    // Process an operator by taking two items off the postfix
    // stack, applying the operator, and pushing the result.
    // Print error if missing closing parenthesis or division by 0.
    private void BinaryOp( int topOp )
    {
        if( topOp == OPAREN )
        {
            Console.Error.WriteLine( "Unbalanced parentheses" );
            opStack.Pop( );
            return;
        }
        long rhs = GetTop( );
        long lhs = GetTop( );

        if( topOp == EXP )
            postfixStack.Push( Pow( lhs, rhs ) );
        else if( topOp == PLUS )
            postfixStack.Push( lhs + rhs );
        else if( topOp == MINUS )
            postfixStack.Push( lhs - rhs );
        else if( topOp == MULT )
            postfixStack.Push( lhs * rhs );
        else if( topOp == DIV )
            if( rhs != 0 )
                postfixStack.Push( lhs / rhs );
            else
            {
                Console.Error.WriteLine( "Division by zero" );
                postfixStack.Push( lhs );
            }
        opStack.Pop( );
    }


    // Simple main to exercise Evaluator class.
    public static void Main( string[ ] args )
    {
        string str;

        try
        {
            Console.WriteLine( "Enter expressions, one per line:" );
            while( ( str = Console.ReadLine( ) ) != null )
            {
                Console.WriteLine( "Read: " + str );
                Evaluator ev = new Evaluator( str );
                Console.WriteLine( ev.GetValue( ) );
                Console.WriteLine( "Enter next expression:" );
            }
        }
        catch( IOException e ) { Console.Error.WriteLine( e ); }
    }
}
