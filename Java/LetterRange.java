import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class LetterRange
{
	public String[] ranges(String param0)
	{
		ArrayList a = new ArrayList();
		int[] counts = new int[27];
		Arrays.fill(counts, 0);
		for (int i = 0; i < param0.length(); i++)
		{
			char ch = param0.charAt(i);
			if (Character.isLetter(ch))
			{
				ch = Character.toLowerCase(ch);
				counts[ch-'a']++;
			}
		}
		String cur = "";
		for (int c = 0; c < 27; c++)
		{
			if (counts[c] == 0)
			{
				if (!cur.equals(""))
				{
				System.out.println(cur);
					int n = cur.length();
					a.add(cur.substring(0,1)+":"+cur.substring(n-1,n));
				}
				cur = "";
			}
			else
			{
				char ch2 = 'a'+c;
				cur += "" + ch2;
			}
		}
		return (String[]) a.toArray(new String[0]);
	}
	
	public static void main(String[] args)
	{
		long time;
		String[] answer;
		boolean errors = false;
		String[] desiredAnswer;
		
		boolean same;
		
		if (errors)
			System.out.println("Some of the test cases had errors :-(");
		else
			System.out.println("You're a stud (at least on the test data)! :-D ");
	}
}

//Powered by [KawigiEdit]

