import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class TVAntenna
{
	public double minRadius(int[] x, int[] y)
	{
		int minx = 1000, miny = 1000, maxx = -1000, maxy = -1000;
		int n = x.length;
		for (int i = 0; i < n; i++)
		{
			minx = Math.min(minx, x[i]);
			miny = Math.min(miny, y[i]);
			maxx = Math.max(maxx, x[i]);
			maxy = Math.max(maxy, y[i]);
		}
		int mind2 = 1000000000;
		for (int i = minx; i <= maxx; i++)
		{
			for (int j = miny; j <= maxy; j++)
			{
				int maxd = 0;
				for (int k = 0; k < n; k++)
				{
					int dx = x[k]-i;
					int dy = y[k]-j;
					if (dx*dx+dy*dy > maxd)
					{
						maxd = dx*dx+dy*dy;
					}
				}
				if (maxd < mind2)
				{
					mind2 = maxd;
				}
			}
		}
		return Math.sqrt(mind2);
	}
	
	public static void main(String[] args)
	{
		long time;
		double answer;
		boolean errors = false;
		double desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new TVAntenna().minRadius(new int[]{2,0,0,1}, new int[]{0,1,-1,1});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 1.4142135623730951D;
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
		answer = new TVAntenna().minRadius(new int[]{3}, new int[]{99});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 0.0D;
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
