import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class ChessTournament
{

	private int countUnAssigned(int[] a, int n)
	{
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == -1)
				count++;
		}
		return count;
	}
	
	private int getMax(int[] a, int[] score, int n)
	{
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == -1)
			{
				max = Math.max(max, score[i]);
			}
		
		}
		return max;	
	}
	
	public int[] nextRound(int[] score, int[] rating)
	{
		int n = score.length;
		
		int[] a = new int[n];
		Arrays.fill(a, -1);
		
		while (countUnAssigned(a, n) > 0)
		{
			int max = getMax(a, score, n);
			int count = 0;
			for (int i = 0; i < n; i++)
			{
				if (a[i] == -1 && score[i] == max)
					count++;
			}
			// take cur max scores
			int[] cur = new int[count%2==0?count:count+1];
			int ind = 0;
			for (int i = 0; i < n; i++)
			{
				if (a[i] == -1 && score[i] == max)
				{
					cur[ind++] = i;
				}
			}
			// sort cur by rating
			for (int i = 0; i < count; i++)
			{
				int maxInd = i;
				for (int j = i; j < count; j++)
				{
					if (rating[cur[j]] > rating[cur[maxInd]])
						maxInd = j;
				}
				// swap
				int t = cur[i];
				cur[i] = cur[maxInd];
				cur[maxInd] = t;			
			}
			for (int i = 0; i < count; i++)
			{
				a[cur[i]] = -2;
			}
			//.. if odd, take next highest rated player among those with second highest score
			if (count % 2 == 1)
			{
				max = getMax(a, score, n);
				int maxRating = 0, maxi = 0;
				for (int i = 0; i < n; i++)
				{
					if (a[i] == -1 && score[i] == max && rating[i] > maxRating)
					{
						maxRating = rating[i];
						maxi = i;
					}
				}
				cur[count] = maxi;
				count++;
			}
			for (int i = 0; i < count/2; i++)
			{
				a[cur[i]] = cur[i+count/2];
				a[cur[i+count/2]] = cur[i];
			}		
		for (int i = 0; i < n; i++) System.out.print(a[i]  + " " ); System.out.println();
		}
		
		return a;
	}
	
	public static void main(String[] args)
	{
		long time;
		int[] answer;
		boolean errors = false;
		int[] desiredAnswer;
		
		boolean same;
		time = System.currentTimeMillis();
		answer = new ChessTournament().nextRound(new int[]{0,2,4,3,3,2,4,3,0,3}, new int[]{1923,1882,2103,2210,2027,1988,2320,2294,1736,1864});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new int[]{ 8,  5,  6,  9,  7,  1,  2,  4,  0,  3 };
		System.out.println("Your answer:");
		if (answer.length > 0)
		{
			System.out.print("\t{ " + answer[0]);
			for (int i=1; i<answer.length; i++)
				System.out.print(", " + answer[i]);
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		System.out.println("Desired answer:");
		if (desiredAnswer.length > 0)
		{
			System.out.print("\t{ " + desiredAnswer[0]);
			for (int i=1; i<desiredAnswer.length; i++)
				System.out.print(", " + desiredAnswer[i]);
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		same = desiredAnswer.length == answer.length;
		for (int i=0; i<answer.length && same; i++)
			if (answer[i] != desiredAnswer[i])
				same = false;
		if (!same)
		{
			errors = true;
			System.out.println("DOESN'T MATCH!!!!");
		}
		else
			System.out.println("Match :-)");
		System.out.println();
		time = System.currentTimeMillis();
		answer = new ChessTournament().nextRound(new int[]{1,2,3,4,1,2,3,4,1,2,3,4,2,3}, new int[]{2000,2001,2002,2003,2004,2005,2006,2007,2008,2009,2010,2011,2012,1999});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new int[]{ 4,  9,  12,  11,  0,  8,  13,  10,  5,  1,  7,  3,  2,  6 };
		System.out.println("Your answer:");
		if (answer.length > 0)
		{
			System.out.print("\t{ " + answer[0]);
			for (int i=1; i<answer.length; i++)
				System.out.print(", " + answer[i]);
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		System.out.println("Desired answer:");
		if (desiredAnswer.length > 0)
		{
			System.out.print("\t{ " + desiredAnswer[0]);
			for (int i=1; i<desiredAnswer.length; i++)
				System.out.print(", " + desiredAnswer[i]);
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		same = desiredAnswer.length == answer.length;
		for (int i=0; i<answer.length && same; i++)
			if (answer[i] != desiredAnswer[i])
				same = false;
		if (!same)
		{
			errors = true;
			System.out.println("DOESN'T MATCH!!!!");
		}
		else
			System.out.println("Match :-)");
		System.out.println();
		time = System.currentTimeMillis();
		answer = new ChessTournament().nextRound(new int[]{0,1000}, new int[]{1500,3000});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new int[]{ 1,  0 };
		System.out.println("Your answer:");
		if (answer.length > 0)
		{
			System.out.print("\t{ " + answer[0]);
			for (int i=1; i<answer.length; i++)
				System.out.print(", " + answer[i]);
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		System.out.println("Desired answer:");
		if (desiredAnswer.length > 0)
		{
			System.out.print("\t{ " + desiredAnswer[0]);
			for (int i=1; i<desiredAnswer.length; i++)
				System.out.print(", " + desiredAnswer[i]);
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		same = desiredAnswer.length == answer.length;
		for (int i=0; i<answer.length && same; i++)
			if (answer[i] != desiredAnswer[i])
				same = false;
		if (!same)
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

