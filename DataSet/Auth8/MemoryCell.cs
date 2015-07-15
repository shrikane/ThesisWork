using System;

// MemoryCell class
//  object read( )         -->  Returns the stored value
//  void write( object x ) -->  x is stored
public class MemoryCell
{
    // Public methods
    public object Read( ) { return storedValue; }
    public void Write( object x ) { storedValue = x; }
    // Private internal data representation
    private object storedValue;
}