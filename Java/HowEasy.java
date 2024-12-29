// BEGIN CUT HERE
// PROBLEM STATEMENT
// ***Note:  Please keep programs under 7000 characters in length.  Thank you


Class Name: HowEasy
Method Name: pointVal
Parameters: String
Returns: int

TopCoder has decided to automate the process of assigning problem difficulty
levels to problems.  TopCoder developers have concluded that problem difficulty
is related only to the Average Word Length of Words in the problem statement:

If the Average Word Length is less than or equal to 3,  the problem is a 250
point problem.
If the Average Word Length is equal to 4 or 5, the problem is a 500 point
problem.
If the Average Word Length is greater than or equal to 6, the problem is a 1000
point problem.

Definitions:
Token - a set of characters bound on either side by spaces, the beginning of
the input String parameter or the end of the input String parameter.
Word - a Token that contains only letters (a-z or A-Z) and may end with a
single period. A Word must have at least one letter.
Word Length - the number of letters in a Word. (NOTE: a period is NOT a letter)

The following are Words :
"ab",  "ab."

The following are not Words :
"ab..", "a.b", ".ab", "a.b.", "a2b.", "."

Average Word Length - the sum of the Word Lengths of every Word in the problem
statement divided by the number of Words in the problem statement.  The
division is integer division. If the number of Words is 0, the Average Word
Length is 0.

Implement a class HowEasy, which contains a method pointVal.  The method takes
a String as a parameter that is the problem statement and returns an int that
is the point value of the problem (250, 500, or 1000). The problem statement
should be processed from left to right.

Here is the method signature (be sure your method is public):
int pointVal(String problemStatement);

problemStatement is a String containing between 1 and 50 letters, numbers,
spaces, or periods.  TopCoder will ensure the input is valid.

Examples:

If problemStatement="This is a problem statement", the Average Word Length is
23/5=4, so the method should return 500.
If problemStatement="523hi.", there are no Words, so the Average Word Length is
0, and the method should return 250.
If problemStatement="Implement a class H5 which contains some method." the
Average Word Length is 38/7=5 and the method should return 500.
If problemStatement=" no9 . wor7ds he8re. hj.." the Average Word Length is 0,
and the method should return 250.


DEFINITION
Class:HowEasy
Method:pointVal
Parameters:String
Returns:int
Method signature:int pointVal(String param0)

// END CUT HERE
import java.util.*;
public class HowEasy {
	public int pointVal(String s)
	{
		int numWords, wordLength, totalWordLength;
		String[] words;
		numWords = 0;
		wordLength = 0;
		totalWordLength = 0;

		words = s.split(" ");

		for (int i = 0; i < words.length; i++)
		{
			if (words[i].matches("^[a-zA-Z]+\\.?$"))
			{
				String sw;
				sw = words[i].replaceAll("\\.", "");
				totalWordLength += sw.length();
				numWords++;
			}
		}
		int avg = (numWords == 0) ? 0 : (totalWordLength / numWords);
		return (avg <= 3 ? 250 : (avg <= 5 ? 500 : 1000));
	}
// BEGIN CUT HERE
    public static void main(String[] args) {
        try {

        } catch( Exception exx) {
            System.err.println(exx);
            exx.printStackTrace(System.err);
        }
    }
    private static void eq( int n, int a, int b ) {
        if ( a==b )
            System.err.println("Case "+n+" passed.");
        else
            System.err.println("Case "+n+" failed: expected "+b+", received "+a+".");
    }
    private static void eq( int n, char a, char b ) {
        if ( a==b )
            System.err.println("Case "+n+" passed.");
        else
            System.err.println("Case "+n+" failed: expected '"+b+"', received '"+a+"'.");
    }
    private static void eq( int n, long a, long b ) {
        if ( a==b )
            System.err.println("Case "+n+" passed.");
        else
            System.err.println("Case "+n+" failed: expected \""+b+"L, received "+a+"L.");
    }
    private static void eq( int n, boolean a, boolean b ) {
        if ( a==b )
            System.err.println("Case "+n+" passed.");
        else
            System.err.println("Case "+n+" failed: expected "+b+", received "+a+".");
    }
    private static void eq( int n, String a, String b ) {
        if ( a != null && a.equals(b) )
            System.err.println("Case "+n+" passed.");
        else
            System.err.println("Case "+n+" failed: expected \""+b+"\", received \""+a+"\".");
    }
    private static void eq( int n, int[] a, int[] b ) {
        if ( a.length != b.length ) {
            System.err.println("Case "+n+" failed: returned "+a.length+" elements; expected "+b.length+" elements.");
            return;
        }
        for ( int i= 0; i < a.length; i++)
            if ( a[i] != b[i] ) {
                System.err.println("Case "+n+" failed. Expected and returned array differ in position "+i);
                print( b );
                print( a );
                return;
            }
        System.err.println("Case "+n+" passed.");
    }
    private static void eq( int n, long[] a, long[] b ) {
        if ( a.length != b.length ) {
            System.err.println("Case "+n+" failed: returned "+a.length+" elements; expected "+b.length+" elements.");
            return;
        }
        for ( int i= 0; i < a.length; i++ )
            if ( a[i] != b[i] ) {
                System.err.println("Case "+n+" failed. Expected and returned array differ in position "+i);
                print( b );
                print( a );
                return;
            }
        System.err.println("Case "+n+" passed.");
    }
    private static void eq( int n, String[] a, String[] b ) {
        if ( a.length != b.length) {
            System.err.println("Case "+n+" failed: returned "+a.length+" elements; expected "+b.length+" elements.");
            return;
        }
        for ( int i= 0; i < a.length; i++ )
            if( !a[i].equals( b[i])) {
                System.err.println("Case "+n+" failed. Expected and returned array differ in position "+i);
                print( b );
                print( a );
                return;
            }
        System.err.println("Case "+n+" passed.");
    }
    private static void print( int a ) {
        System.err.print(a+" ");
    }
    private static void print( long a ) {
        System.err.print(a+"L ");
    }
    private static void print( String s ) {
        System.err.print("\""+s+"\" ");
    }
    private static void print( int[] rs ) {
        if ( rs == null) return;
        System.err.print('{');
        for ( int i= 0; i < rs.length; i++ ) {
            System.err.print(rs[i]);
            if ( i != rs.length-1 )
                System.err.print(", ");
        }
        System.err.println('}');
    }
    private static void print( long[] rs) {
        if ( rs == null ) return;
        System.err.print('{');
        for ( int i= 0; i < rs.length; i++ ) {
            System.err.print(rs[i]);
            if ( i != rs.length-1 )
                System.err.print(", ");
        }
        System.err.println('}');
    }
    private static void print( String[] rs ) {
        if ( rs == null ) return;
        System.err.print('{');
        for ( int i= 0; i < rs.length; i++ ) {
            System.err.print( "\""+rs[i]+"\"" );
            if( i != rs.length-1)
                System.err.print(", ");
        }
        System.err.println('}');
    }
    private static void nl() {
        System.err.println();
    }
// END CUT HERE
}

