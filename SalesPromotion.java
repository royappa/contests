import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class SalesPromotion
{
	private double discount;
	private int[] itemPoints;
	private int[] itemPrice;
	private int numItems;
	
	HashMap cache;
	
	private int best(int points, int halfPrice, int n)
	{
		if (points == 0 && halfPrice == 0 && n > 0)
		{
			int total = 0;
			for (int i = 0; i < n-1; i++)
			{
				total += (int) Math.ceil((double)itemPrice[i]*discount/100.0);
			}
			return total;
		}
		if (points == 0 && halfPrice == 0 && n == 0)
		{
			return 0;
		}
		if (n == 0 && (points > 0 || halfPrice > 0))
		{
			return -1;
		}
		String key = ""+points+":"+halfPrice+":"+n;
		if (cache.containsKey(key))
			return ((Integer) cache.get(key)).intValue();
		
		// try 3 different ways of doing the last item
		int bestP = -1, bestH = -1, bestD = -1;
		if (points >= itemPoints[n-1])
		{
			bestP = best(points-itemPoints[n-1], halfPrice, n-1)+0;
		}
		if (halfPrice > 0)
		{
			bestH = best(points, halfPrice-1, n-1)+(int) Math.ceil((double)itemPrice[n-1]/2.0);
		}
		bestD = best(points, halfPrice, n-1)+(int) Math.ceil((double) itemPrice[n-1]*discount/100.0);
		
		int b = Math.min(bestP==-1?1000000000:bestP,bestH==-1?1000000000:bestH);
		if (b == -1)
		{
			if (bestD == -1)
				b = -1;
			else
				b = Math.min(bestD, b);
		}
				
		cache.put(key, new Integer(b));
		return b;
	}
				
	
	public int bestPrice(int points, int halfPrice, int _discount, String[] items)
	{
		numItems = items.length;
		itemPoints = new int[numItems];
		itemPrice = new int[numItems];
		
		cache = new HashMap();
		
		for (int i = 0; i < numItems; i++)
		{
			String[] w = items[i].split(" ");
			itemPoints[i] = Integer.parseInt(w[0]);
			itemPrice[i] = Integer.parseInt(w[1]);
		}
		discount = _discount;
		
		return best(points, halfPrice, numItems);
	}
	
	public static void main(String[] args)
	{
		long time;
		int answer;
		boolean errors = false;
		int desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new SalesPromotion().bestPrice(500, 1, 10, new String[]{"150 500", "350 1000", "500 600", "450 800"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 940;
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
		answer = new SalesPromotion().bestPrice(500, 1, 10, new String[]{"150 450", "350 700", "500 1200", "450 800"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 1320;
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
		answer = new SalesPromotion().bestPrice(1000, 0, 0, new String[]{"200 500", "300 700", "400 900", "500 1100", "600 1300"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 2200;
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
		answer = new SalesPromotion().bestPrice(0, 0, 0, new String[]{"100 100", "100 200", "100 150", "150 300"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 750;
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

