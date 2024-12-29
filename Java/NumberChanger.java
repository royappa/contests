import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class NumberChanger
{
	public int transform(String start, String finish)
	{
		int n = start.length();
		char[] fin = finish.toCharArray();
		LinkedList q = new LinkedList();
		HashMap dist = new HashMap();
		
		q.add(start);
		dist.put(start, new Integer(0));

		int best = 100000000; // what SHOULD this be..?
		while (q.size() > 0)
		{
			String head = (String) q.remove(0);
			char[] tempHead = head.toCharArray();				
			int diff = 0;
			for (int i =0; i < n; i++)
				diff += Math.abs(tempHead[i]-fin[i]);
			int swaps = ((Integer) dist.get(head)).intValue();
			best = Math.min(diff+swaps, best);
			for (int i = 0; i < n; i++)
			{
				for (int j = i+1; j < n; j++)
				{
					char chi = tempHead[i];
					char chj = tempHead[j];
					tempHead[i] = chj;
					tempHead[j] = chi;
					String t = new String(tempHead);
					if (!dist.containsKey(t))
					{
						q.add(t);
						dist.put(t, new Integer(swaps+1));
					}
					tempHead[i] = chi;					
					tempHead[j] = chj;
				}
			}		
		}
		return best;
	}
	
	public static void main(String[] args)
	{
		long time;
		int answer;
		boolean errors = false;
		int desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new NumberChanger().transform("01234567", "01234567");
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
		answer = new NumberChanger().transform("11119999", "99991111");
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
		answer = new NumberChanger().transform("55555555", "12345678");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 16;
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
		answer = new NumberChanger().transform("77771111", "00446688");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 16;
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
		answer = new NumberChanger().transform("12", "30");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 3;
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
