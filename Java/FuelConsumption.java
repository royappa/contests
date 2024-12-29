import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class FuelConsumption
{
	public double maximalDistance(int[] vels, int[] cons, int fuel)
	{
		double max = 0.0;
		int n = vels.length;
		for (int i = 0; i < n; i++)
		{
			double dist = ((double) fuel/(double) cons[i])*(double)vels[i];
			if (dist > max)
			{
				max = dist;
			}
		}
		return max;
	}
	
	public static void main(String[] args)
	{
		long time;
		double answer;
		boolean errors = false;
		double desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new FuelConsumption().maximalDistance(new int[]{100}, new int[]{10000}, 10000);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 100.0D;
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
		answer = new FuelConsumption().maximalDistance(new int[]{70, 80, 90, 100, 60, 110}, new int[]{4000, 4000, 4000, 4000, 4000, 4000}, 40000);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 1100.0D;
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
		answer = new FuelConsumption().maximalDistance(new int[]{250, 240, 230, 220, 210, 211}, new int[]{5000, 4500, 4000, 3500, 3000, 3000}, 50000);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 3516.6666666666665D;
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
		answer = new FuelConsumption().maximalDistance(new int[]{5, 10, 20, 40, 80}, new int[]{1000, 2500, 6250, 9000, 18000}, 47832);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 239.16D;
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
		answer = new FuelConsumption().maximalDistance(new int[]{5, 10, 20, 40, 80, 160}, new int[]{1000, 2500, 6250, 8000, 9500, 20000}, 47832);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 402.79578947368424D;
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
		answer = new FuelConsumption().maximalDistance(new int[]{240, 195, 130, 133, 15, 160, 111, 206, 72, 149, 146, 115, 235, 183, 102, 96, 163, 61, 196, 52, 87, 139, 33, 7, 90, 67, 118, 227, 197, 114}, new int[]{14837, 2981, 17292, 18591, 4832, 7461, 17991, 18369, 18291, 9400, 15179, 3317, 2595, 2441, 6936, 8028, 14973, 18981, 12503, 7816, 2883, 6385, 6230, 18157, 16567, 9310, 2866, 4687, 14171, 4477}, 31710);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 2871.6184971098264D;
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

