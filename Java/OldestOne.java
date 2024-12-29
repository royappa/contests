import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class OldestOne
{
public String oldest(String[] data)
{
	int maxAge = 0;
	String maxName = "";
	for (int i = 0; i < data.length; i++)
	{
		String name = data[i].trim();
		Pattern p = Pattern.compile("([A-Z ]*[A-Z])[ ]+([0-9]+)[ ]+.*");
		Matcher m = p.matcher(name);
		if (!m.find()) System.out.println("No match for " + name);
		name = m.group(1);
		int age = Integer.parseInt(m.group(2));
		if (age > maxAge)
		{
			maxAge = age;
			maxName = name;
		}
	}
	return maxName;		
}
	
	public static void main(String[] args)
	{
		long time;
		String answer;
		boolean errors = false;
		String desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new OldestOne().oldest(new String[]{"DOUG JONES 22 213 ALDEN LANE","   BOB     A SMITH  102 CLARK ST"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "BOB     A SMITH";
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
		answer = new OldestOne().oldest(new String[]{"DOUG JONES 102 213 ALDEN LANE","   BOB     A SMITH  102 CLARK ST", "A 1 999ELM"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "DOUG JONES";
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
		answer = new OldestOne().oldest(new String[]{"DOUG JONES 122 213 ALDEN LANE","   BOB     A SMITH  102 CLARK ST", "A 199 ELM"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "A";
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
		answer = new OldestOne().oldest(new String[]{"   DOUG                 JONES   122 213 ALDEN LANE","   BOB     A SMITH                       102  3", " J O H N N Y           199 ELM"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "J O H N N Y";
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

