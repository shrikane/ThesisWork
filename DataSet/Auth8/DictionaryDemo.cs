using System;
using System.IO;
using System.Collections.Generic;

public class DictionaryDemo
{
    public static void PrintMap<KeyType, ValueType>( string msg, IDictionary<KeyType, ValueType> m )
    {
        Console.WriteLine( msg + ":" );

        foreach( KeyValuePair<KeyType, ValueType> thisPair in m )
        {
            Console.Write( thisPair.Key + ": " );
            Console.WriteLine( thisPair.Value );
        }
    }

    private class ReverseOrder<AnyType> : IComparer<AnyType> where AnyType : IComparable<AnyType>
    {
        public int Compare( AnyType lhs, AnyType rhs )
        {
            return ( (IComparable<AnyType>) rhs ).CompareTo( lhs );
        }
        public bool Equals( AnyType lhs, AnyType rhs )
        {
            return ( (IComparable<AnyType>) rhs ).CompareTo( lhs ) == 0;
        }
        public int GetHashCode( AnyType obj )
        {
            return obj.GetHashCode( );
        }
    }

    // Do some inserts and printing (done in printMap).
    public static void Main( string[ ] args )
    {
        //IDictionary<string,string> phone1 = new SortedDictionary<string,string>( );
        IDictionary<string, string> phone1 = new Dictionary<string, string>( );

        phone1[ "John Doe" ] = "212-555-1212";
        phone1[ "Jane Doe" ] = "312-555-1212";
        phone1[ "Holly Doe" ] = "213-555-1212";
        phone1[ "Susan Doe" ] = "617-555-1212";

        Console.WriteLine( "phone1[ \"Jane Doe\" ]: " + phone1[ "Jane Doe" ] );
        Console.WriteLine( );

        PrintMap( "phone1", phone1 );
    }
}


