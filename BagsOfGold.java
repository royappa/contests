import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class BagsOfGold
{
	private int[][][] cache;
	
	int findGain(int turn, int left, int right, int[] bags)
	{
		if (left > right)
		{
			return 0;
		}
		int value = cache[turn][left][right];
		if (value != -1)
			return value;
			
		if (turn == 0)
		{
			int leftVal = bags[left]+findGain(1, left+1, right, bags);
			int rightVal = bags[right]+findGain(1, left, right-1, bags);
			value = Math.max(leftVal, rightVal);
		}
		else if (turn == 1)
		{
			int leftVal = -bags[left]+findGain(0, left+1, right, bags);
			int rightVal = -bags[right]+findGain(0, left, right-1, bags);
			value = Math.min(leftVal, rightVal);
		}
		cache[turn][left][right] = value;
		return value;	
	}

	public int netGain(int[] bags)
	{
		int n = bags.length;
		cache = new int[2][n][n];
		
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					cache[i][j][k] = -1;
					
		return findGain(0, 0, n-1, bags); // turn==0 means "my turn"; endpoints are 0,n-1		
	}
	
	public static void main(String[] args)
	{
		long time;
		int answer;
		boolean errors = false;
		int desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new BagsOfGold().netGain(new int[]{7,2});
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
		answer = new BagsOfGold().netGain(new int[]{2,7,3});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = -2;
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
		answer = new BagsOfGold().netGain(new int[]{1000,1000,1000,1000,1000});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 1000;
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
		answer = new BagsOfGold().netGain(new int[]{823,912,345,100000,867,222,991,3,40000});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = -58111;
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

