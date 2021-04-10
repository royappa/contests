/*
ID: royappa1
LANG: JAVA
PROG: ride
*/
import java.io.*;
import java.util.*;

class ride {
  public static void main (String [] args) throws IOException {
  
	BufferedReader in
	   = new BufferedReader(new FileReader("ride.in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(
            new FileWriter("ride.out")));	  // output file name
            
	String comet = in.readLine();
	String group = in.readLine();
	
	int sumC = 1, sumG = 1;
	for (int i = 0; i < comet.length(); i++)
	{
		sumC *= comet.charAt(i)-'A'+1;
	}
	for (int i = 0; i < group.length(); i++)
	{
		sumG *= group.charAt(i)-'A'+1;	
	}
	out.println(sumC%47==sumG%47?"GO":"STAY");
    out.close();                                  // close the output file
    System.exit(0);                               // don't omit this!
  }
}
