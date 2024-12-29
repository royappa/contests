import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class Crossings
{
	private boolean passes(int x, int[] pos, int[] ang, int n)
	{
		for (int i = 0; i < n; i++)
		{
			// calculate the intersection of ray(i) and ray(x)
			// no intersection
			if ((pos[i] < pos[x] && ang[i] >= ang[x]) || (pos[x] < pos[i] && ang[x] >= ang[i]))
			{
				continue;
			}
			// there IS an intersection
			if (pos[i] < pos[x]) 
			{
				if (ang[x] <= 90)
				{
					continue;
				}
				int opp = 180-ang[x];
				if (opp < ang[i]) 
					return false;
				else if (opp == ang[i] && i < x)
					return false;
				continue;
			}
			if (pos[x] < pos[i]) 
			{
				if (ang[i] <= 90)
				{
					return false;
				}
				int opp = 180-ang[i];
				if (opp < ang[x]) 
					continue;
				else if (opp == ang[x] && x < i)
					continue;
				return false;
			}
		}
		return true;
	}
	public int[] getOut(int[] positions, int[] angles)
	{
		int n = positions.length;
		ArrayList pass = new ArrayList();
		for (int x = 0; x < n; x++)
		{
			if (passes(x, positions, angles, n))
			{
				pass.add(""+x);
			}
		}
		int[] result = new int[pass.size()];
		for (int i = 0; i < pass.size(); i++)
		{
			result[i] = Integer.parseInt( (String) pass.get(i));
		}
		return result;		
	}
	
	public static void main(String[] args)
	{
		long time;
		int[] answer;
		boolean errors = false;
		int[] desiredAnswer;
		
		boolean same;
		time = System.currentTimeMillis();
		answer = new Crossings().getOut(new int[]{0, 40, 20, 10, 30, 50}, new int[]{105, 40, 30, 75, 135, 75});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new int[]{ 0,  3,  5 };
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
		answer = new Crossings().getOut(new int[]{0, 40, 20}, new int[]{40, 40, 140});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new int[]{ 0,  1 };
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
		answer = new Crossings().getOut(new int[]{10, 20}, new int[]{89, 91});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new int[]{ 0 };
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

