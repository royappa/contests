import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class Hyphenated
{

	public double avgLength(String[] lines)
	{
		String all = "";
		int n = lines.length;
		
		int count = 0, len = 0;
		for (int i = 0; i < n; i++)
		{
			String[] w = all.split("[^A-Za-z\\-]+");
			int numWords = w.length;
			for (int j = 0; j < numWords; j++)
			{
				if (j <= numWords-2 && w[j].matches("[A-Za-z\\-]+") && !w[j].matches(".*\\-$"))
				{
					String[] sw = w[i].split("\\-");
					for (int k = 0; k < sw.length; k++)
					{
						if (sw[i].length() > 0)
						{
							count++;
							len += sw[i].length();
						}
					}
				}
				else if (j == numWords-1 && w[j].matches(".*\\-$"))
				{
					if (i <= n-2) 
					{
						lines[i+1] = w[i] + lines[i+1];
					}
					else
					{
						String[] sw = w[i].split("\\-");
						for (int k = 0; k < sw.length; k++)
						{
							if (sw[i].length() > 0)
							{
								count++;
								len += sw[i].length();
							}
						}
					}
				}
			}
		}
		System.out.println(len+" "+count);
		return (double) len / (double) count;
	}
	
	public static void main(String[] args)
	{
		long time;
		double answer;
		boolean errors = false;
		double desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new Hyphenated().avgLength(new String[]{"  now is the ex-", "ample.  "} );
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 3.75D;
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
		answer = new Hyphenated().avgLength(new String[]{"  now is the ex-", " ample.  "});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 3.0D;
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
		answer = new Hyphenated().avgLength(new String[]{"inter-","national-","ization.."});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 20.0D;
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
		answer = new Hyphenated().avgLength(new String[]{"All the time I have well-defined  "," trouble."});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 4.125D;
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
		answer = new Hyphenated().avgLength(new String[]{"hello-","-","-","-","great"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 5.0D;
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

