import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class BusinessPlan
{
	HashMap cache;
	
	private int findMin(int[] expense, int[] revenue, int[] ptime, int C, int D, int time)
	{
		if (C >= D)
			return time;	
		if (C <= 0)
		{
			return -1;
		}
		String key = ""+C+":"+D+":"+time;
		if (cache.containsKey(key))
		{
			Integer ret = (Integer) cache.get(key);
			return ret.intValue();
		}
		
		int minTime = -1;
		for (int i = 0; i < expense.length; i++)
		{
			if (C >= expense[i] && (minTime ==-1 || ptime[i]+time < minTime))
			{
				int t = findMin(expense, revenue, ptime, C-expense[i]+revenue[i], D, ptime[i]+time);
				if (minTime == -1 || (t != -1 && t < minTime))
					minTime = t;
			}
		}		
	
		cache.put(key, new Integer(minTime));
		return minTime;
	}

	public int howLong(int[] expense, int[] revenue, int[] ptime, int C, int D)
	{
		cache = new HashMap();
		
		return findMin(expense, revenue, ptime, C, D, 0);
	}
	
	public static void main(String[] args)
	{
		long time;
		int answer;
		boolean errors = false;
		int desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new BusinessPlan().howLong(new int[]{1,4}, new int[]{2,10}, new int[]{1,2}, 1, 10);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 5;
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
		answer = new BusinessPlan().howLong(new int[]{11}, new int[]{20}, new int[]{10}, 10, 10);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 0;
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
		answer = new BusinessPlan().howLong(new int[]{11}, new int[]{20}, new int[]{10}, 10, 11);
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
		answer = new BusinessPlan().howLong(new int[]{1,1,1}, new int[]{3,4,8}, new int[]{1,2,3}, 1, 11);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 5;
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
		answer = new BusinessPlan().howLong(new int[]{99999,1,99998,2,99997,3,99996,4,99995,5}, new int[]{100000,100000,100000,100,100000,100000,100000,100000,100000,100000}, new int[]{1,9,1,10,1,9,1,9,1,9}, 2, 100);
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
