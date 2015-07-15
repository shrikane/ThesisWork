using System;

class Best
{
    public int row;
    public int column;
    public int val;

    public Best( int v ) : this ( v, 0, 0 ) { }

    public Best( int v, int r, int c )
    { val = v; row = r; column = c; }
}
