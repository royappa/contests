import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class BenfordsLaw
{
	public int questionableDigit(int[] trans, int thresh)
	{
		int n = trans.length;		
		int[] digits = new int[10];
		
		Arrays.fill(digits, 0);
		if (n == 0) return -1;
		for (int i = 0; i < n; i++)
		{
			String x = Integer.toString(trans[i]);
			int vx = x.charAt(0) - '0';
			digits[vx]++;
		}
		
		for (int d = 1; d <= 9; d++)
		{
			double prob = Math.log(1.0+1.0/(double)d)/Math.log(10.0);
			if (digits[d] >= thresh*prob*n || thresh*digits[d] <= prob*n)
			{
				return d;
			}
		}
		return -1;
	}

	
	public static void main(String[] args)
	{
		long time;
		int answer;
		boolean errors = false;
		int desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new BenfordsLaw().questionableDigit(new int[]{ 5236,7290,200,1907,3336,9182,17,4209,8746,7932,  6375,909,2189,3977,2389,2500,1239,3448,6380,4812 }, 2);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 1;
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
		answer = new BenfordsLaw().questionableDigit(new int[]{ 1,10,100,2,20,200,2000,3,30,300 }, 2);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 2;
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
		answer = new BenfordsLaw().questionableDigit(new int[]{ 9,87,765,6543,54321,43219,321987,21987,1987,345,234,123 }, 2);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = -1;
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
		answer = new BenfordsLaw().questionableDigit(new int[]{ 1,2,3,4,5,6,7,8,7,6,5,4,3,2,1 }, 8);
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
		time = System.currentTimeMillis();
		answer = new BenfordsLaw().questionableDigit(new int[]{ 987,234,1234,234873487,876,234562,17,  7575734,5555,4210,678234,3999,8123 }, 3);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 8;
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

