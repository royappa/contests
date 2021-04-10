import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class Hangman
{
	public String guessWord(String feedback, String[] words)
	{
		System.out.println(feedback);
		int c = 0, pos = 0;
		for (int i = 0; i < words.length; i++)
		{
			if (words[i].length() == feedback.length())
			{
				int len = words[i].length();
				boolean match = true;
				for (int j = 0; j < len; j++)
				{
					if (Character.isLetter(feedback.charAt(j)) && (feedback.charAt(j) != words[i].charAt(j)))
						match = false;
					char ch = feedback.charAt(j);
					if (Character.isLetter(ch) && (ch == words[i].charAt(j)))
					{
						for (int k = 0; k < len; k++)
						{
							if (k == j) continue;
							if (words[i].charAt(k) == ch && feedback.charAt(k) == '-')
								match = false;
						}
					}
					
				}
				if (match)
				{
					c++;
					pos = i;
				}
			}
		}
		return c == 1 ? words[pos] : "";
	}
	
	public static void main(String[] args)
	{
		long time;
		String answer;
		boolean errors = false;
		String desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new Hangman().guessWord("N-N-A", new String[]{"NINJA", "NINJAS", "FLIPS", "OUT", "FRISBEE"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "NINJA";
		System.out.println("Your answer:");
		System.out.println("\t\"" + answer + "\"");
		System.out.println("Desired answer:");
		System.out.println("\t\"" + desiredAnswer + "\"");
		if (!answer.equals(desiredAnswer))
		{
			errors = true;
			System.out.println("DOESN'T MATCH!!!!");
		}
		else
			System.out.println("Match :-)");
		System.out.println();
		time = System.currentTimeMillis();
		answer = new Hangman().guessWord("B--B--", new String[]{"BRINGS", "BARBED", "BUBBLE"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "BARBED";
		System.out.println("Your answer:");
		System.out.println("\t\"" + answer + "\"");
		System.out.println("Desired answer:");
		System.out.println("\t\"" + desiredAnswer + "\"");
		if (!answer.equals(desiredAnswer))
		{
			errors = true;
			System.out.println("DOESN'T MATCH!!!!");
		}
		else
			System.out.println("Match :-)");
		System.out.println();
		time = System.currentTimeMillis();
		answer = new Hangman().guessWord("---------", new String[]{"MONKEY", "FORCE", "IS", "GAINING", "STRENGTH"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "";
		System.out.println("Your answer:");
		System.out.println("\t\"" + answer + "\"");
		System.out.println("Desired answer:");
		System.out.println("\t\"" + desiredAnswer + "\"");
		if (!answer.equals(desiredAnswer))
		{
			errors = true;
			System.out.println("DOESN'T MATCH!!!!");
		}
		else
			System.out.println("Match :-)");
		System.out.println();
		time = System.currentTimeMillis();
		answer = new Hangman().guessWord("-AAA--", new String[]{"CAAABB", "BAAACC"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "";
		System.out.println("Your answer:");
		System.out.println("\t\"" + answer + "\"");
		System.out.println("Desired answer:");
		System.out.println("\t\"" + desiredAnswer + "\"");
		if (!answer.equals(desiredAnswer))
		{
			errors = true;
			System.out.println("DOESN'T MATCH!!!!");
		}
		else
			System.out.println("Match :-)");
		System.out.println();
		time = System.currentTimeMillis();
		answer = new Hangman().guessWord("---H-O-H-B-OPHOB--", new String[]{"ROSACEA", "GYROVAGUE", "SHACONIAN", "ALTITONANT", "BRACHIATION", "CERCOPITHECAN", "SCOLECOPHAGOUS", "RESISTENTIALISM", "SLUBBERDEGULLION",  "AICHMORHABDOPHOBIA", "SPECTOCLOACAPHOBIA", "ULTRACREPIDARIANISM", "HIPPOPOTOMONSTROSESQUIPEDALIAN", "CHARGOGGAGOGGMANCHAUGGAGOGGCHAUBUNAGUNGAMAUGG"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "AICHMORHABDOPHOBIA";
		System.out.println("Your answer:");
		System.out.println("\t\"" + answer + "\"");
		System.out.println("Desired answer:");
		System.out.println("\t\"" + desiredAnswer + "\"");
		if (!answer.equals(desiredAnswer))
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
