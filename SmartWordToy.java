import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class SmartWordToy
{
	public int minPresses(String start, String finish, String[] forbid)
	{
		LinkedList q = new LinkedList();
		String nextS = "bcdefghijklmnopqrstuvwxyza";
		String prevS = "zabcdefghijklmnopqrstuvwxy";
		char[] next = nextS.toCharArray();
		char[] prev = prevS.toCharArray();
		
		String pat = "";
		for (int i = 0; i < forbid.length; i++)
		{
			String[] w = forbid[i].split(" ");
			if (pat.length() > 0)
			{
				pat += "|";
			}
			for (int j = 0; j < w.length; j++)
			{
				pat += "[" + w[j] + "]";
			}
		}
		System.out.println(pat);
		Pattern p = Pattern.compile(pat);
		
		HashMap dist = new HashMap();
		
		q.add(start);
		dist.put(start, new Integer(0));
		char[] nbr = new char[4];
		char[] tmp = new char[4];
		
		while (q.size() > 0)
		{
			String head = (String) q.get(0);
			q.remove(0);
			int d = ((Integer) dist.get(head)).intValue();
			if (head.equals(finish))
			{
				return d;
			}
			tmp = head.toCharArray();
			//System.out.println(tmp);
			Integer I = new Integer(d+1);
			for (int i = 0; i < 4; i++)
			{
				for (int dir = 0; dir < 2; dir++)
				{
					nbr[0] = tmp[0]; nbr[1] = tmp[1]; nbr[2] = tmp[2]; nbr[3] = tmp[3];
					nbr[i] = dir==0 ? prev[tmp[i]-'a'] : next[tmp[i]-'a'];
					String neighbor = new String(nbr);
					Matcher m = p.matcher(neighbor);
					if (!m.matches() && !dist.containsKey(neighbor))
					{
						q.add(neighbor);
						dist.put(neighbor, I);
					}
				}
			}
		}
		return -1;
	}
	
	public static void main(String[] args)
	{
		long time;
		int answer;
		boolean errors = false;
		int desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new SmartWordToy().minPresses("aaaa", "zzzz", new String[]{"a a a z", "a a z a", "a z a a", "z a a a", "a z z z", "z a z z", "z z a z", "z z z a"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 8;
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
		answer = new SmartWordToy().minPresses("aaaa", "bbbb", new String[]{});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 4;
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
		answer = new SmartWordToy().minPresses("aaaa", "mmnn", new String[]{});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 50;
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
		answer = new SmartWordToy().minPresses("aaaa", "zzzz", new String[]{"bz a a a", "a bz a a", "a a bz a", "a a a bz"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = -1;
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
		answer = new SmartWordToy().minPresses("aaaa", "zzzz", new String[]{"cdefghijklmnopqrstuvwxyz a a a",  "a cdefghijklmnopqrstuvwxyz a a",  "a a cdefghijklmnopqrstuvwxyz a",  "a a a cdefghijklmnopqrstuvwxyz"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 6;
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
		answer = new SmartWordToy().minPresses("aaaa", "bbbb", new String[]{"b b b b"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = -1;
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
		answer = new SmartWordToy().minPresses("zzzz", "aaaa", new String[]{"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = -1;
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

