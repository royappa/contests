import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class OmahaLow
{

	private int value(char ch)
	{
		return ch >= '0' && ch <= '9' ? ch-'0' :
			ch == 'T' ? 10 :
				ch == 'J' ? 11 :
					ch == 'Q' ? 12 : 13;
	}
	
	
	private char charValue(int a)
	{
		return a >= 0 && a <= 9 ? (char) ('0'+a):
			a == 10 ? 'T' :
				a == 11 ? 'J' : 
					a == 12 ? 'Q' : 'K';
	}
	
	public String low(String sharedCards, String playersCards)
	{
		int n = sharedCards.length();
		int m = playersCards.length();
		char[] shared = new char[n];
		char[] players = new char[m];
		
		
		sharedCards.getChars(0, n, shared, 0);
		playersCards.getChars(0, m, players, 0);
		
		for (int i = 0; i < n; i++)
		{
			shared[i] = (char) ('0' + value(shared[i]));
		}
		for (int i = 0; i < m; i++)
		{
			players[i] = (char) ('0' + value(players[i]));
		}
System.out.println(new String(shared) + "  " + new String(players));

		String least = "";
		for (int s1 = 0; s1 < n; s1++) 
			for (int s2 = s1+1; s2 < n; s2++)
				for (int s3 = s2+1; s3 < n; s3++)
					for (int p1 = 0; p1 < m; p1++)
						for (int p2 = p1+1; p2 < m; p2++)
						{
							char[] xtry = new char[] { shared[s1], shared[s2], shared[s3], 
										  players[p1], players[p2] };
							if (!(xtry[0] <= '8' && xtry[1] <= '8' && xtry[2] <= '8' && xtry[3] <= '8' && xtry[4] <= '8'))
								continue;
							Arrays.sort(xtry);
							//System.out.println(xtry[0]+" "+xtry[1]+" "+xtry[2]+" "+xtry[3]+" "+xtry[4]);
							for (int i = 0; i < 2; i++)
							{
								char t = xtry[i];
								xtry[i] = xtry[4-i];
								xtry[4-i] = t;
							}
							//System.out.println("X" + xtry[0]+" "+xtry[1]+" "+xtry[2]+" "+xtry[3]+" "+xtry[4]);
							boolean good = true;
							for (int i = 0; i < 4; i++)
							{
								if (xtry[i]==xtry[i+1])
								{
									good=false;
								}
							}
							if (!good)
								continue;
							String trys = new String(xtry);
							if (least.equals("") || trys.compareTo(least) < 0)
							{
								least = trys;
								//System.out.println("LL = " + least);
							}
						}
		
		String result = "";
		for (int i = 0; i < least.length(); i++)
		{
			result += charValue(least.charAt(i)-'0');
		}	
		return result;	
	}
	
	public static void main(String[] args)
	{
		long time;
		String answer;
		boolean errors = false;
		String desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new OmahaLow().low("123QK", "45TJ");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "54321";
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
		answer = new OmahaLow().low("55443", "2345");
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
		answer = new OmahaLow().low("1357Q", "345J");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "75431";
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
		answer = new OmahaLow().low("76285", "4816");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "65421";
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
		answer = new OmahaLow().low("12345", "3339");
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
		answer = new OmahaLow().low("58463", "947K");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "76543";
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
		answer = new OmahaLow().low("67521", "J859");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "86521";
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

