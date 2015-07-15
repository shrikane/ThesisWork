using System;
using System.IO;
using weiss.Collections.Generic;

// Balance class: check for balanced symbols
//
// CONSTRUCTION: with a BufferedReader object
// ******************PUBLIC OPERATIONS***********************
// int CheckBalance( )   --> Print mismatches
//                           return number of errors
// ******************ERRORS**********************************
// Error checking on comments and quotes is performed
// main checks for balanced symbols.

public class Balance
{
    // Symbol represents what will be placed on the stack.
    private class Symbol
    {
        public char token;
        public int theLine;
        public Symbol( char tok, int line )
        {
            token = tok;
            theLine = line;
        }
    }

    // Constructor.
    // inStream is the stream containing a program.
    public Balance( TextReader inStream )
    {
        errors = 0;
        tok = new Tokenizer( inStream );
    }

    // Prints an error message for unbalanced symbols.
    // Returns number of errors detected.
    public int CheckBalance( )
    {
        char ch;
        Symbol match = null;
        Stack<Symbol> pendingTokens = new Stack<Symbol>( );

        while( ( ch = tok.GetNextOpenClose( ) ) != '\0' )
        {
            Symbol lastSymbol = new Symbol( ch, tok.GetLineNumber( ) );

            switch( ch )
            {
                case '(':
                case '[':
                case '{':
                    pendingTokens.Push( lastSymbol );
                    break;

                case ')':
                case ']':
                case '}':
                    if( pendingTokens.Count == 0 )
                    {
                        errors++;
                        Console.WriteLine( "Extraneous " + ch +
                                            " at line " + tok.GetLineNumber( ) );
                    }
                    else
                    {
                        match = pendingTokens.Pop( );
                        CheckMatch( match, lastSymbol );
                    }
                    break;

                default: // Cannot happen
                    break;
            }
        }

        while( pendingTokens.Count > 0 )
        {
            match = pendingTokens.Pop( );
            Console.WriteLine( "Unmatched " + match.token +
                                " at line " + match.theLine );
            errors++;
        }
        return errors + tok.GetErrorCount( ); ;
    }
    private Tokenizer tok;
    private int errors;

    // Print an error message if clSym does not match opSym.
    // Update errors.
    private void CheckMatch( Symbol opSym, Symbol clSym )
    {
        if( opSym.token == '(' && clSym.token != ')' ||
            opSym.token == '[' && clSym.token != ']' ||
            opSym.token == '{' && clSym.token != '}' )
        {
            Console.WriteLine( "Found " + clSym.token + " on line " +
                  tok.GetLineNumber( ) + "; does not match " + opSym.token
                  + " at line " + opSym.theLine );
            errors++;
        }
    }

    // main routine for balanced symbol checker.
    // Slightly different from text.
    // If no command line parameters, standard input is used.
    // Otherwise, files in command line are used.
    public static void Main( string[ ] args )
    {

        Balance p;

        if( args.Length == 0 )
        {
            p = new Balance( Console.In );
            if( p.CheckBalance( ) == 0 )
                Console.WriteLine( "No errors!" );
            return;
        }

        for( int i = 0; i < args.Length; i++ )
        {
            TextReader f = null;
            try
            {
                f = new StreamReader( args[ i ] );

                Console.WriteLine( args[ i ] + ": " );
                p = new Balance( f );
                if( p.CheckBalance( ) == 0 )
                    Console.WriteLine( "   ...no errors!" );
            }
            catch( IOException e )
            {
                Console.Error.WriteLine( e + args[ i ] );
            }
            finally
            {
                if( f != null )
                    f.Close( );
            }

        }
    }
}