import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class WindowManager
{
	private int atoi(String s) { return Integer.parseInt(s); }

	private int clip(int coord, int max)
	{
		if (coord < 0)
			return 0;
		if (coord > max)
			return max;
		return coord;
	}
	private boolean inside (int r, int c, int width, int height)
	{
		return (r >= 0 && r < height && c >= 0 && c < width);
	}
	private boolean between(int x, int min, int max)
	{
		return x >= min && x <= max;
	}
	private boolean outside(int tlv, int tlh, int vs, int hs, int width, int height)
	{
		if (inside(tlv,tlh,width,height) || inside(tlv+vs-1,tlh,width,height) || 
				  inside(tlv+vs-1,tlh+hs-1,width,height) || inside(tlv,tlh+hs-1,width,height))
			return false;
		int minr = tlv, minc = tlh, maxr = tlv+vs-1, maxc = tlh+hs-1;
		if (between(0, minr, maxr) && between(0, minc, maxc))
			return false;
		if (between(height-1, minr, maxr) && between(0, minc, maxc))
			return false;
		if (between(height-1, minr, maxr) && between(width-1, minc, maxc))
			return false;
		if (between(0, minr, maxr) && between(width-1, minc, maxc))
			return false;
		return true;
	}
	private void draw(char[][] screen, int r, int c, int tlv, int tlh, int vs, int hs, char ch)
	{
		char dch = ch;
		if ( (r == tlv && c == tlh) || (r == tlv && c == tlh+hs-1) ||
		     (r == tlv+vs-1 && c == tlh) || (r == tlv+vs-1 && c == tlh+hs-1))
		{
			dch = '+';
		}
		else if ( r == tlv || r == tlv+vs-1)
		{
			dch = '-';
		}
		else if (c == tlh || c == tlh+hs-1 )
		{
			dch = '|';
		}
		screen[r][c] = dch;
	}
	
	public String[] screen(int height, int width, String[] windows)
	{
		char[][] screen = new char[100][100];
		for (int i = 0; i < 100; i++)
		{
			Arrays.fill(screen[i], ' ');
		}
		for (int i = 0; i < windows.length; i++)
		{
			String[] w = windows[i].split(" ");
			int tlv = atoi(w[0]);
			int tlh = atoi(w[1]);
			int vs = atoi(w[2]);
			int hs = atoi(w[3]);
			if (outside(tlv,tlh,vs,hs,width,height))
				continue;
			char ch = windows[i].charAt(windows[i].length()-1);
			int ulr = clip(tlv, height-1);
			int ulc = clip(tlh, width-1);
			int lrr = clip(tlv+vs-1, height-1);
			int lrc = clip(tlh+hs-1, width-1);
			//System.out.println(ulr + " " + ulc + " " + lrr + " " + lrc);
			for (int r = ulr; r <= lrr; r++)
			{
				for (int c = ulc; c <= lrc; c++)
				{
					draw(screen, r, c, tlv, tlh, vs, hs, ch);
				}
			}
		}
		String[] result = new String[height];
		for (int r = 0; r < height; r++)
		{
			result[r] = new String(screen[r]);
			result[r] = result[r].substring(0, width);
		}
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
		answer = new WindowManager().screen(4, 6, new String[]{"-5 -5 20 20 O", "0 0 2 2 Y", "0 0 4 6 X"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "+----+",  "|XXXX|",  "|XXXX|",  "+----+" };
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
		answer = new WindowManager().screen(7, 7, new String[]{"-5 -5 20 12 9", "2 2 15 15 @", "2 2 3 3 *"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "999999|",  "999999|",  "99+-+--",  "99|*|@@",  "99+-+@@",  "99|@@@@",  "99|@@@@" };
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
		answer = new WindowManager().screen(1, 1, new String[]{"-20000 -20000 5 5 X"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ " " };
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
		answer = new WindowManager().screen(5, 5, new String[]{"-1000000 -1000000 2000000 2000000 L"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "LLLLL",  "LLLLL",  "LLLLL",  "LLLLL",  "LLLLL" };
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
