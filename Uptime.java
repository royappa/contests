import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class Uptime
{
	
	private boolean isLeap(long year)
	{
		if (year % 4 == 0)
		{
			if (year % 100 == 0)
			{
				if (year % 400 == 0)
				{
					return true;
				}
				return false;
			}
			return true;
		}
		return false;
	}
				
	
	private long toSeconds(String started)
	{
		String[] monthStr = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		int[] dpm = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		String[] w = started.split("[ :]+");
		long day = Integer.parseInt(w[0]);
		long month;
		int i;
		for (i = 0; i < 12; i++)
		{
			if (monthStr[i].equals(w[1]))
				break;
		}
		month = i;
		long year = Integer.parseInt(w[2]);
		long hour = Integer.parseInt(w[4]);
		long minute = Integer.parseInt(w[5]);
		long seconds = Integer.parseInt(w[6]);
		long ampm = w[7].equals("AM") ? 1 : 0;
		if (w[7].equals("AM"))
		{
			if (hour == 12)
			{
				hour = 0;
			}
		}
		else
		{
			if (hour < 12)
			{
				hour += 12;
			}
		}
		long total = 0;
		long d = 0, y = 0, m = 0;
		y = 1900;
System.out.println(""+day+" "+month+" "+year+" "+hour+" "+minute+" "+seconds);
		while (y < year)
		{
			long daysPerYear = isLeap(y) ? 366 : 365;
			total += daysPerYear*24*60*60;
			y++;
		}
		while (m < month)
		{
			int k = (int) m;
			long daysPerMonth = dpm[k];
			if (m == 1 && isLeap(year))
				daysPerMonth++;
			total += daysPerMonth*24*60*60;
			m++;
		}
		total += day*24*60*60;
		total += hour*60*60+minute*60+seconds;
		return total;		
	}

	String formatTime(long seconds)
	{
		String ds = "", hs = "", ms = "", ss = "";
		long days = seconds / (24*60*60);
		if (days > 0)
		{
			ds = ""+days+"d";
			seconds -= days*(24*60*60);
		}
		long hours = seconds / (60*60);
		if (hours > 0)
		{
			hs = ""+hours+"h";
			seconds -= hours*60*60;
		}
		long minutes = seconds / 60;
		if (minutes > 0)
		{
			ms = ""+minutes+"m";
			seconds -= minutes*60;
		}
		if (seconds > 0)
		{
			ss = ""+seconds+"s";
		}
		String res = ds+" "+hs+" "+ms+" "+ss;
		return res.trim();
	}
		
	public String calcUptime(String started, String now)
	{
		long secStart = toSeconds(started);
		long secNow = toSeconds(now);
		return formatTime(secNow-secStart);		
	}
	
	public static void main(String[] args)
	{
		long time;
		String answer;
		boolean errors = false;
		String desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new Uptime().calcUptime("7 Jun 2004 at 04:41:32 PM", "8 Jun 2004 at 07:16:28 PM");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "1d 2h 34m 56s";
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
		answer = new Uptime().calcUptime("7 Jun 2004 at 04:41:32 PM", "7 Jun 2004 at 04:41:32 PM");
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
		answer = new Uptime().calcUptime("28 Feb 2004 at 01:23:45 PM", "1 Mar 2004 at 12:34:56 AM");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "1d 11h 11m 11s";
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
		answer = new Uptime().calcUptime("28 Feb 2005 at 01:23:45 PM", "1 Jan 2015 at 12:34:56 AM");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "3593d 11h 11m 11s";
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
		answer = new Uptime().calcUptime("25 Jan 1922 at 05:58:52 AM", "26 Feb 2190 at 11:53:14 AM");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "97918d 5h 54m 22s";
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

