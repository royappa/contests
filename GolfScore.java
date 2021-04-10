import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class GolfScore
{
	public int tally(int[] parValues, String[] scoreSheet)
	{
		String[] names = { "triple bogey", "double bogey", "bogey", "par", "birdie", "eagle", "albatross", "hole in one" };
		int[] values = { 3, 2, 1, 0, -1, -2, -3, 100 };
		
		int score = 0, index = 0;
		for (int i = 0; i < 18; i++)
		{
			index = -1;
			//System.out.println(""+i+ " "+scoreSheet[i]+"#"+names.length);
			for (int j = 0; j < names.length; j++)
			{
			//System.out.println("#"+names[j]+"#"+scoreSheet[i]);
				if (names[j].equals(scoreSheet[i]))
				{
					index = j;
					break;
				}
			}
			if (index == 7)
				score++;
			else
				score += parValues[i]+values[index];
		}
		return score;
	}
	
	public static void main(String[] args)
	{
		long time;
		int answer;
		boolean errors = false;
		int desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new GolfScore().tally(new int[]{1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5}, new String[]{"bogey", "bogey", "bogey", "bogey", "bogey", "bogey", "bogey", "bogey", "bogey", "eagle", "eagle", "eagle", "eagle", "eagle", "eagle", "eagle", "eagle", "eagle"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 45;
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
		answer = new GolfScore().tally(new int[]{3, 2, 4, 2, 2, 1, 1, 1, 3, 2, 4, 4, 4, 2, 3, 1, 3, 2}, new String[]{"bogey", "double bogey", "par", "double bogey", "double bogey", "triple bogey", "triple bogey", "triple bogey", "bogey", "double bogey", "par", "par", "par", "double bogey", "bogey", "triple bogey", "bogey", "double bogey"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 72;
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
		answer = new GolfScore().tally(new int[]{3, 2, 4, 2, 2, 1, 1, 1, 3, 2, 4, 4, 4, 2, 3, 1, 3, 2}, new String[]{"eagle", "birdie", "albatross", "birdie", "birdie", "par", "hole in one", "par", "eagle", "birdie", "albatross", "albatross", "albatross", "birdie", "eagle", "hole in one", "eagle", "birdie"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 18;
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
		answer = new GolfScore().tally(new int[]{4, 1, 3, 3, 4, 4, 1, 4, 2, 3, 3, 5, 4, 1, 4, 4, 2, 1}, new String[]{"triple bogey", "triple bogey", "bogey", "par", "triple bogey", "double bogey", "triple bogey", "triple bogey", "par", "eagle", "bogey", "bogey", "birdie", "par", "triple bogey", "eagle", "triple bogey", "triple bogey"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 77;
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

