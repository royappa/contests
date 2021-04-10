import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class TreeSpreading
{
	long fact(int n)
	{
		return n <= 2 ? 2 : n*fact(n-1);
	}
	
	long choose(int n, int k)
	{
		return fact(n)/(fact(k)*fact(n-k));
	}
		
	public long count(int[] trees)
	{
		long sum = 0;
		for (int i = 0; i < 4; i++)
			sum += trees[i];
		if (sum == 0)
		{
			return 1; // no trees to plant
		}
		long max = 0;
		sum--;
		for (int t = 0; t < 4; t++)
		{
			trees[t]--;
			long m = count(trees);
			long x = sum-trees[t]*2;
			long v;
			if (x <= 0)
				v = 0;
			else
				v = m*x;
			if (v > max)
				max = v;
			trees[t]++;
		}
		return max;
	}
	public long countArrangements(int a, int b, int c, int d)
	{
		int total = a+b+c+d;
		int[] trees = new int[] { a, b, c, d };
		
		return count(trees);
	}	
	public static void main(String[] args)
	{
		long time;
		long answer;
		boolean errors = false;
		long desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new TreeSpreading().countArrangements(1, 1, 0, 0);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 2L;
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
		answer = new TreeSpreading().countArrangements(2, 2, 0, 0);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 2L;
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
		answer = new TreeSpreading().countArrangements(1, 1, 1, 1);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 24L;
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
		answer = new TreeSpreading().countArrangements(3, 2, 1, 1);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 96L;
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

