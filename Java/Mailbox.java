import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class Mailbox
{
	public int impossible(String collection, String[] address)
	{
		int num = 0;
		int[] counts = new int[500];
		for (int i = 0; i < address.length; i++)
		{
			Arrays.fill(counts, 0);	
			for (int j = 0; j < collection.length(); j++)
			{
				int v = collection.charAt(j)-'0';
				counts[v]++;
			}
			String addr = address[i].replaceAll(" ", "");
			for (int j = 0; j < addr.length(); j++)
			{
				int v = addr.charAt(j) - '0';
				counts[v]--;
			}
			boolean possible = true;
			for (int j = 0; j < 500; j++)
			{
				if (counts[j] < 0)
				{
					possible = false;
					break;
				}
			}
			if (!possible)
				num++;
		}
		return num;
	}
	
	public static void main(String[] args)
	{
		long time;
		int answer;
		boolean errors = false;
		int desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new Mailbox().impossible("AAAAAAABBCCCCCDDDEEE123456789", new String[]{"123C","123A","123 ADA"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 0;
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
		answer = new Mailbox().impossible("ABCDEFGHIJKLMNOPRSTUVWXYZ1234567890", new String[]{"2 FIRST ST"," 31 QUINCE ST", "606 BAKER"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 3;
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
		answer = new Mailbox().impossible("ABCDAAST", new String[]{"111 A ST", "A BAD ST", "B BAD ST"});
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
		
		if (errors)
			System.out.println("Some of the test cases had errors :-(");
		else
			System.out.println("You're a stud (at least on the test data)! :-D ");
	}
}

//Powered by [KawigiEdit]

