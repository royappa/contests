import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class Matching
{
	private int shape(String s) 
	{
		return s.equals("CIRCLE") ? 0 :
			s.equals("SQUIGGLE") ? 1 : 2;
	}
	
	private int color(String s)
	{
		return s.equals("RED") ? 0 :
			s.equals("BLUE") ? 1 : 2;
	}
	
	private int stripe(String s)
	{
		return s.equals("SOLID") ? 0 :
			s.equals("STRIPED") ? 1 : 2;
	}
	
	private int count(String s)
	{
		return s.equals("ONE") ? 0 :
			s.equals("TWO") ? 1 : 2;
	}
	
	public String[] findMatch(String[] first, String[] second)
	{
		int[][] v = new int[3][4];
		String[][] s = { first, second };
		
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				v[i][j] = j == 0 ? shape(s[i][j]) :
						j == 1 ? color(s[i][j]) :
							j == 2 ? stripe(s[i][j]) : count(s[i][j]);
			}
		
		}
		for (int j = 0; j < 4; j++)
		{
			if (v[0][j] == v[1][j])
			{
				v[2][j] = v[0][j];
			}
			else
			{
				v[2][j] = 3-(v[0][j]+v[1][j]);
			}
		}
		String[] colors = { "RED", "BLUE", "GREEN" };
		String[] shapes = { "CIRCLE", "SQUIGGLE", "DIAMOND" };
		String[] stripes = { "SOLID", "STRIPED", "EMPTY" };
		String[] counts = { "ONE", "TWO", "THREE" };
		
		String[] result = { shapes[v[2][0]], colors[v[2][1]], stripes[v[2][2]], counts[v[2][3]] } ;
		
		return result;
	}
	
	
	public static void main(String[] args)
	{
		long time;
		String[] answer;
		boolean errors = false;
		String[] desiredAnswer;
		
		boolean same;
		time = System.currentTimeMillis();
		answer = new Matching().findMatch(new String[]{"DIAMOND","BLUE","SOLID","ONE"}, new String[]{"DIAMOND","GREEN","SOLID","TWO"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "DIAMOND",  "RED",  "SOLID",  "THREE" };
		System.out.println("Your answer:");
		if (answer.length > 0)
		{
			System.out.print("\t{ \"" + answer[0] + "\"");
			for (int i=1; i<answer.length; i++)
				System.out.print(",\n\t  \"" + answer[i] + "\"");
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		System.out.println("Desired answer:");
		if (desiredAnswer.length > 0)
		{
			System.out.print("\t{ \"" + desiredAnswer[0] + "\"");
			for (int i=1; i<desiredAnswer.length; i++)
				System.out.print(",\n\t  \"" + desiredAnswer[i] + "\"");
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		same = desiredAnswer.length == answer.length;
		for (int i=0; i<answer.length && same; i++)
			if (!answer[i].equals(desiredAnswer[i]))
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
		answer = new Matching().findMatch(new String[]{"CIRCLE","GREEN","EMPTY","TWO"}, new String[]{"DIAMOND","BLUE","STRIPED","ONE"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "SQUIGGLE",  "RED",  "SOLID",  "THREE" };
		System.out.println("Your answer:");
		if (answer.length > 0)
		{
			System.out.print("\t{ \"" + answer[0] + "\"");
			for (int i=1; i<answer.length; i++)
				System.out.print(",\n\t  \"" + answer[i] + "\"");
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		System.out.println("Desired answer:");
		if (desiredAnswer.length > 0)
		{
			System.out.print("\t{ \"" + desiredAnswer[0] + "\"");
			for (int i=1; i<desiredAnswer.length; i++)
				System.out.print(",\n\t  \"" + desiredAnswer[i] + "\"");
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		same = desiredAnswer.length == answer.length;
		for (int i=0; i<answer.length && same; i++)
			if (!answer[i].equals(desiredAnswer[i]))
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
		answer = new Matching().findMatch(new String[]{"DIAMOND","RED","SOLID","ONE"}, new String[]{"SQUIGGLE","BLUE","SOLID","TWO"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "CIRCLE",  "GREEN",  "SOLID",  "THREE" };
		System.out.println("Your answer:");
		if (answer.length > 0)
		{
			System.out.print("\t{ \"" + answer[0] + "\"");
			for (int i=1; i<answer.length; i++)
				System.out.print(",\n\t  \"" + answer[i] + "\"");
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		System.out.println("Desired answer:");
		if (desiredAnswer.length > 0)
		{
			System.out.print("\t{ \"" + desiredAnswer[0] + "\"");
			for (int i=1; i<desiredAnswer.length; i++)
				System.out.print(",\n\t  \"" + desiredAnswer[i] + "\"");
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		same = desiredAnswer.length == answer.length;
		for (int i=0; i<answer.length && same; i++)
			if (!answer[i].equals(desiredAnswer[i]))
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
		answer = new Matching().findMatch(new String[]{"SQUIGGLE","RED","STRIPED","ONE"}, new String[]{"SQUIGGLE","RED","STRIPED","ONE"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "SQUIGGLE",  "RED",  "STRIPED",  "ONE" };
		System.out.println("Your answer:");
		if (answer.length > 0)
		{
			System.out.print("\t{ \"" + answer[0] + "\"");
			for (int i=1; i<answer.length; i++)
				System.out.print(",\n\t  \"" + answer[i] + "\"");
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		System.out.println("Desired answer:");
		if (desiredAnswer.length > 0)
		{
			System.out.print("\t{ \"" + desiredAnswer[0] + "\"");
			for (int i=1; i<desiredAnswer.length; i++)
				System.out.print(",\n\t  \"" + desiredAnswer[i] + "\"");
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		same = desiredAnswer.length == answer.length;
		for (int i=0; i<answer.length && same; i++)
			if (!answer[i].equals(desiredAnswer[i]))
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

