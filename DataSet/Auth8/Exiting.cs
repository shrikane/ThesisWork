using System.Threading;

namespace weiss.nonstandard
{
    public class Exiting
    {
        // Suspend current program for a long time
        public static void LongPause( )
        {
            Thread.Sleep( 10000 );
        }
    }
}
