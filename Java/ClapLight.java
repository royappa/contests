import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class ClapLight
{


	private boolean trigger(int[] b, int t, int n)
	{
		for (int i = 0; i <= n-4; i++)
		{
			if (b[i] < t && b[i+1] >= t && b[i+2] >= t && b[i+3] < t)
				return true;
		}
		return false;
	}
	public int threshold(int[] b)
	{
		int n = b.length;
		int[] b2 = new int[n];
		System.arraycopy(b, 0, b2, 0, n);
				
		Arrays.sort(b);
		
		int t = b[n/2];
		for (; t <= 1001; t++)
		{
			int count = 0;
			for (int i = 0; i < n; i++)
			{
				if (t > b[i])
					count++;
			}
			if (count > n/2)
				break;
		}
		System.out.println("t = "  + t);
		for (; t <= 1001; t++)
		{
			if (!trigger(b2, t, n))
			{
				return t;
			}
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
		answer = new ClapLight().threshold(new int[]{6,6,6,6,6});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 7;
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
		answer = new ClapLight().threshold(new int[]{ 5,8,7,6,12,8,4,3,2,6 } );
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
		answer = new ClapLight().threshold(new int[]{8,8,8,1,1,1,1,1,1,1,1,1,1,1,2,1});
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
		answer = new ClapLight().threshold(new int[]{921,1,5,900,8,813,3,3,3,3,3,3,3,813,813});
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
		
		if (errors)
			System.out.println("Some of the test cases had errors :-(");
		else
			System.out.println("You're a stud (at least on the test data)! :-D ");
	}
}

//Powered by [KawigiEdit]

