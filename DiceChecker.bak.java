import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class DiceChecker
{
		public int[] badValues(int[] param0)
		{
			ArrayList a = new ArrayList();
			int total = param0.length;

			int[] counts = new int[7];
			Arrays.fill(counts, 0);
			for (int i = 0; i < n; i++)
			{
				counts[param0[i]]++;
			}

			for (int i = 1; i <= 6; i++)
			{
				int x = counts[i];
				if (x*4 > total || x*10 < total)
					a.add(new Integer(i));
			}
			int[] res = new int[a.size()];
			for (int i = 0; i < res.length; i++)
			{
				res[i] = ((Integer) a.get(i)).intValue();
			}
			return res;
		}
	
	public static void main(String[] args)
	{
		long time;
		int[] answer;
		boolean errors = false;
		int[] desiredAnswer;
		
		boolean same;
		
		if (errors)
			System.out.println("Some of the test cases had errors :-(");
		else
			System.out.println("You're a stud (at least on the test data)! :-D ");
	}
}

//Powered by [KawigiEdit]

