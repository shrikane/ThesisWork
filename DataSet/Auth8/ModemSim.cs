using System;

using Random = weiss.Random;
using weiss.nonstandard;

// ModemSim class: run a simulation
//
// CONSTRUCTION: with three parameters: the number of
//     modems, the average connect time, and the
//     interarrival time
//
// ******************PUBLIC OPERATIONS*********************
// void RunSim( )       --> Run a simulation

public class ModemSim
{
    //The event class.
    // Implements the Comparable interface
    // to arrange events by time of occurrence.
    private class Event : System.Collections.Generic.IComparable<Event>
    {
        public const int DIAL_IN = 1;
        public const int HANG_UP = 2;

        public Event( ) : this( 0, 0, DIAL_IN )
        {
        }

        public Event( int name, int tm, int type )
        {
            who = name;
            time = tm;
            what = type;
        }

        public int CompareTo( Event rhs )
        {
            return time - rhs.time;
        }

        public bool Equals( Event rhs )
        {
            return time == rhs.time;
        }
        public int who;        // the number of the user
        public int time;       // when the event will occur
        public int what;       // DIAL_IN or HANG_UP
    }

    // Constructor.
    // modem  is number of modems.
    // avgLen is averge length of a call.
    // callIntrvl is the average time between calls.
    public ModemSim( int modems, double avgLen, int callIntrvl )
    {
        eventSet = new BinaryHeap<Event>( );
        freeModems = modems;
        avgCallLen = avgLen;
        freqOfCalls = callIntrvl;
        r = new Random( );
        NextCall( freqOfCalls );  // Schedule first call
    }

    private Random r;                       // A random source
    private IPriorityQueue<Event> eventSet; // Pending events

    // Basic parameters of the simulation
    private int freeModems;           // Number of modems unused
    private double avgCallLen;        // Length of a call
    private int freqOfCalls;          // Interval between calls

    // Used by nextCall only
    private int userNum = 0;
    private int nextCallTime = 0;

    // Place a new DIAL_IN event into the event queue.
    // Then advance the time when next DIAL_IN event will occur.
    // In practice, we would use a random number to set the time.
    private void NextCall( int delta )
    {
        Event ev = new Event( userNum++, nextCallTime, Event.DIAL_IN );
        eventSet.Insert( ev );
        nextCallTime += delta;
    }


    // Run the simulation until stoppingTime occurs.
    // Print output as in Figure 4.
    public void RunSim( long stoppingTime )
    {
        Event e = null;
        int howLong;

        while( !eventSet.IsEmpty( ) )
        {
            e = eventSet.DeleteMin( );

            if( e.time > stoppingTime )
                break;

            if( e.what == Event.HANG_UP )    // HANG_UP
            {
                freeModems++;
                Console.WriteLine( "User " + e.who +
                                    " hangs up at time " + e.time );
            }
            else                      // DIAL_IN
            {
                Console.Write( "User " + e.who +
                                    " dials in at time " + e.time + " " );
                if( freeModems > 0 )
                {
                    freeModems--;
                    howLong = r.NextPoisson( avgCallLen );
                    Console.WriteLine( "and connects for "
                                         + howLong + " minutes" );
                    e.time += howLong;
                    e.what = Event.HANG_UP;
                    eventSet.Insert( e );
                }
                else
                    Console.WriteLine( "but gets busy signal" );

                NextCall( freqOfCalls );
            }
        }
    }

    // Quickie main for testing purposes.
    public static void Main( string[ ] args )
    {
        ModemSim s = new ModemSim( 3, 5.0, 1 );
        s.RunSim( 20 );
    }
}
