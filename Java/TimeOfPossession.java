import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class TimeOfPossession
{
	public String getTime(String[] times)
	{
		int seconds[] = new int[2];
		int n = times.length;
		int last = 0, has = 0;
		for (int i = 0; i < n; i++)
		{
			String[] w = times[i].split(" ");
			if (w[0].equals("A"))
			{
				String[] ms = w[1].split(":");
				int sec = Integer.parseInt(ms[0])*60+Integer.parseInt(ms[1]);
				seconds[has] += sec-last;
				last = sec;			
				has = 0;
			}
			else if (w[0].equals("B"))
			{
				String[] ms = w[1].split(":");
				int sec = Integer.parseInt(ms[0])*60+Integer.parseInt(ms[1]);
				seconds[has] += sec-last;
				last = sec;			
				has = 1;
			}
			else if (w[0].equals("SWITCH"))
			{
				String[] ms = w[1].split(":");
				int sec = Integer.parseInt(ms[0])*60+Integer.parseInt(ms[1]);
				seconds[has] += sec-last;
				last = sec;
				has = 1-has;
			}
			else if (w[0].equals("END"))
			{
				String[] ms = w[1].split(":");
				int sec = Integer.parseInt(ms[0])*60+Integer.parseInt(ms[1]);
				seconds[has] += sec-last;			
			}
		}
		String mm = ""+ (seconds[0]/60);
		String ss = ""+seconds[0]%60;
		if (seconds[0]%60 == 0)
			ss += "0";
		else if (seconds[0]%60 <= 9)
			ss = "0"+ss;
		return mm+":"+ss;
	}
	
	public static void main(String[] args)
	{
		long time;
		String answer;
		boolean errors = false;
		String desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new TimeOfPossession().getTime(new String[]{"A 0:00","SWITCH 1:23","END 3:00"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "1:23";
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
		answer = new TimeOfPossession().getTime(new String[]{"A 0:00","SWITCH 1:23","SWITCH 4:50","END 15:00"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "11:33";
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
		answer = new TimeOfPossession().getTime(new String[]{"A 0:00","SWITCH 0:00","END 15:00"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "0:00";
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
