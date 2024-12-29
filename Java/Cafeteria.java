import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class Cafeteria
{
	public String latestTime(int[] offset, int[] walkingTime, int[] drivingTime)
	{
		int startTime = 0;
		
		for (int i = 0; i < offset.length; i++)
		{
			for (int hour = 14; hour >= 0; hour--)
			{		
				for (int t = 0; t <= 5; t++)
				{
					if (hour == 14 && t >= 3)
						continue;
					// if this bus can make it
					if (hour*60+t*10+offset[i]+drivingTime[i] <= 14*60+30)
					{
						int s = (hour*60+t*10+offset[i])-walkingTime[i];
						if (s > startTime)
						{
							startTime = s;
						}
					}
				}
			}		
		}	
		int h = startTime / 60;
		if (h >= 13)
			h -= 12;
		int m = startTime % 60;
		
		
		String hh = h < 10 ? ("0"+h) : (""+h);
		String mm = m < 10 ? ("0"+m) : (""+m);
		String ret = hh+":"+mm;
		return ret;
	}
	
	public static void main(String[] args)
	{
		long time;
		String answer;
		boolean errors = false;
		String desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new Cafeteria().latestTime(new int[]{9}, new int[]{1}, new int[]{1});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "02:28";
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
		answer = new Cafeteria().latestTime(new int[]{6}, new int[]{9}, new int[]{120});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "12:17";
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
		answer = new Cafeteria().latestTime(new int[]{6,9}, new int[]{9,10}, new int[]{120,121});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "12:19";
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
		answer = new Cafeteria().latestTime(new int[]{0,1,2,3,4,5,6,7,8,9}, new int[]{11,11,11,11,11,11,11,11,11,11}, new int[]{190,190,190,190,190,190,190,190,190,190});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "11:09";
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
		answer = new Cafeteria().latestTime(new int[]{7,4,0,0,2,1,6,7,7,0,8,6,0,5,0,6,7,9,0,2,4,8,4,7,9,2,4,4,3,1,4,5,8,8,2,5,7,8,7,5,6,8,8,0,1,3,5,0,8}, new int[]{26,14,1,4,16,28,16,6,4,5,21,18,5,2,21,21,28,22,5,22,26,16,14,19,19,19,4,12,24,4,30,16,28,20,25,2,30,18,4,6,9,22,8,3,7,29,8,30,6}, new int[]{151,264,280,89,63,57,15,120,28,296,76,269,90,106,31,222,291,52,102,73,140,248,44,187,76,49,296,106,54,119,54,283,263,285,275,127,108,82,84,241,169,203,244,256,109,288,9,262,103});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "02:07";
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

