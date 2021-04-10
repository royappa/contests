import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class VolumeGuess
{
	private int atoi(String x) { return Integer.parseInt(x); }
	
	public class Compar implements Comparator
	{
		public int compare(Object oa, Object ob)
		{
			String a = (String) oa;
			String b = (String) ob;
			String[] wa = a.split(",");
			String[] wb = b.split(",");
			
			return atoi(wa[2])-atoi(wb[2]);
		}
	}
	
	public int correctVolume(String[] queries, int n, int ithBox)
	{
		Arrays.sort(queries, new Compar());
		
		int p = 0;
		for (int i = 1; i < ithBox; i++)
		{
			p += n-i;
		}
		for (int j = p; j < p+(n-ithBox); j++)
		{
			System.out.println(queries[j]);
		}
		return 0;
	}
	
	public static void main(String[] args)
	{
		long time;
		int answer;
		boolean errors = false;
		int desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new VolumeGuess().correctVolume(new String[]{"1,2,10","1,3,10","2,3,20"}, 3, 1);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 10;
		System.out.println("Your answer:");
		System.out.println("\t" + answer);
		System.out.println("Desired answer:");
		System.out.println("\t" + desiredAnswer);
		if (answer != desiredAnswer)
		{
			errors = true;
			System.out.println("DOESN'T MATCH!!!!");
		}
		else
			System.out.println("Match :-)");
		System.out.println();
		time = System.currentTimeMillis();
		answer = new VolumeGuess().correctVolume(new String[]{"1,02,10","2,3,010","1,3,20"}, 3, 2);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 10;
		System.out.println("Your answer:");
		System.out.println("\t" + answer);
		System.out.println("Desired answer:");
		System.out.println("\t" + desiredAnswer);
		if (answer != desiredAnswer)
		{
			errors = true;
			System.out.println("DOESN'T MATCH!!!!");
		}
		else
			System.out.println("Match :-)");
		System.out.println();
		time = System.currentTimeMillis();
		answer = new VolumeGuess().correctVolume(new String[]{"1,2,31","1,3,9","1,4,31","2,4,32","3,4,9","3,2,9"}, 4, 1);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 31;
		System.out.println("Your answer:");
		System.out.println("\t" + answer);
		System.out.println("Desired answer:");
		System.out.println("\t" + desiredAnswer);
		if (answer != desiredAnswer)
		{
			errors = true;
			System.out.println("DOESN'T MATCH!!!!");
		}
		else
			System.out.println("Match :-)");
		System.out.println();
		time = System.currentTimeMillis();
		answer = new VolumeGuess().correctVolume(new String[]{"1,2,31","1,3,9","1,4,31","2,4,32","3,4,9","3,2,9"}, 4, 3);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 9;
		System.out.println("Your answer:");
		System.out.println("\t" + answer);
		System.out.println("Desired answer:");
		System.out.println("\t" + desiredAnswer);
		if (answer != desiredAnswer)
		{
			errors = true;
			System.out.println("DOESN'T MATCH!!!!");
		}
		else
			System.out.println("Match :-)");
		System.out.println();
		
		if (errors)
			System.out.println("Some of the test cases had errors :-(");
		else
			System.out.println("You're a stud (at least on the test data)! :-D ");
	}
}

//Powered by [KawigiEdit]

