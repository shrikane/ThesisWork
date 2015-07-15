using System;

namespace weiss.nonstandard
{
    // Exception class for illegal decrease key
    // operations in pairing heaps.
    public class IllegalValueException : ApplicationException
    {
        // Construct this exception object.
        // message is the error message.
        public IllegalValueException( string message ) : base( message )
        {
        }
    }
}
