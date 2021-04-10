import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class SimpleIO
{
	private boolean isUnique(String pattern, String beep, int n)
	{
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			String p = pattern+pattern;
			p = p.substring(i);
			if (p.matches(beep+".*$"))
				count++;
		}
		return count==1;
	}
	
	private int distance(int cur, int target, int n)
	{
		return cur < target ? target-cur : (n-cur)+target;
	}
	private int count(String pattern, int start, int target, int n)
	{
		String beep = "";
		for (int i = 0; i < n; i++)
		{
			int next = (start + 1) % n;
			beep += pattern.charAt(next);
			if (isUnique(pattern, beep, n))
			{
				return beep.length()+distance(next, target, n)-1;
			}
		}
		return -1;
	}
	public int worstCase(String pattern, int target)
	{
		int n = pattern.length();
		int max = -1;
		for (int start = 0; start < n; start++)
		{
			int num = start == target ? -1 : count(pattern, start, target, n);
			if (num == -1)
				continue;
			max = num > max ? num : max;
			System.out.println(start + " " + max);		
		}
		return max;
	}
	
	public static void main(String[] args)
	{
		long time;
		int answer;
		boolean errors = false;
		int desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new SimpleIO().worstCase("BNB", 0);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 4;
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
		answer = new SimpleIO().worstCase("BNBNBNBN", 3);
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
		answer = new SimpleIO().worstCase("BBNNBNBBBBNBBBBBB", 3);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 18;
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

