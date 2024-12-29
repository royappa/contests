import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class WordFind
{
	public String[] findWords(String[] grid, String[] wordList)
	{
		ArrayList found = new ArrayList();
		int height = grid.length;
		int width = grid[0].length();
		for (int i = 0; i < wordList.length; i++)
		{	
			int row = -1, col = -1;
			boolean done = false;
			int wordLen = wordList[i].length();
			for (int r = 0; r < height && !done; r++)
			{
				for (int c = 0; c < width && !done; c++)
				{
					// down		
					if (r+wordLen <= height)
					{
						boolean equal = true;					
						for (int k = 0; k < wordLen; k++)
						{
							if (wordList[i].charAt(k) != grid[r+k].charAt(c))
							{
								equal = false;
								break;
							}
						}
						if (equal)
						{
							row = r;
							col = c;
							done = true;
							break;
						}
					}	
					// right
					if (c+wordLen <= width)
					{
						boolean equal = true;					
						for (int k = 0; k < wordLen; k++)
						{
							if (wordList[i].charAt(k) != grid[r].charAt(c+k))
							{
								equal = false;
								break;
							}
						}
						if (equal)
						{
							row = r;
							col = c;
							done = true;
							break;
						}
					}						
					// diag
					if (r+wordLen <= height && c+wordLen <= width)
					{
						boolean equal = true;			
						for (int k = 0; k < wordLen; k++)
						{
							if (wordList[i].charAt(k) != grid[r+k].charAt(c+k))
							{
								equal = false;
								break;
							}
						}
						if (equal)
						{
							row = r;
							col = c;
							done = true;
							break;
						}
					}						
				}
			}
			if (row != -1)
			{
				found.add(""+row + " " + col);
			}
			else
			{
				found.add("");
			}
		}		
		String[] ret = (String []) found.toArray(new String[0]);
		return ret;	
	}
	
	public static void main(String[] args)
	{
		long time;
		String[] answer;
		boolean errors = false;
		String[] desiredAnswer;
		
		boolean same;
		time = System.currentTimeMillis();
		answer = new WordFind().findWords(new String[]{"TEST", "GOAT", "BOAT"}, new String[]{"GOAT", "BOAT", "TEST"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "1 0",
  "2 0",
  "0 0" };
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
		answer = new WordFind().findWords(new String[]{"SXXX", "XQXM", "XXLA", "XXXR"}, new String[]{"SQL", "RAM"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "0 0",
  "" };
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
		answer = new WordFind().findWords(new String[]{"EASYTOFINDEAGSRVHOTCJYG", "FLVENKDHCESOXXXXFAGJKEO", "YHEDYNAIRQGIZECGXQLKDBI", "DEIJFKABAQSIHSNDLOMYJIN", "CKXINIMMNGRNSNRGIWQLWOG", "VOFQDROQGCWDKOUYRAFUCDO", "PFLXWTYKOITSURQJGEGSPGG"}, new String[]{"EASYTOFIND", "DIAG", "GOING", "THISISTOOLONGTOFITINTHISPUZZLE"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "0 0",
  "1 6",
  "0 22",
  "" };
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

