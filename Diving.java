import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class Diving
{
	public String needed(String sDifficulty, String sNeed, String sRatings)
	{
		double diff = Double.parseDouble(sDifficulty);
		double need = Double.parseDouble(sNeed);
		String[] strRatings = sRatings.split(" ");
		double[] ratings = new double[5];
		int pos = -1;
		double sum = 0.0;
		int maxPos = 0, minPos = 0;
		double max = -999.0, min = 999.0;
		for (int i = 0; i < 5; i++)
		{
			ratings[i] = strRatings[i].equals("?.?") ? -1.0 : Double.parseDouble(strRatings[i]);
			if (strRatings[i].equals("?.?"))
			{
				pos = i;
				continue;
			}
			sum += ratings[i];
			if (ratings[i] > max)
			{
				max = ratings[i];
				maxPos = i;
			}
			if (ratings[i] < min)
			{
				min = ratings[i];
				minPos = i;
			}
		}
		System.out.println(pos+" "+ maxPos+" "+minPos);
		for (int rate = 0; rate <= 100; rate+=5)
		{
			String sample = "" + (rate/10) + "." + (rate % 10);
			ratings[pos] = Double.parseDouble(sample);
			double newsum = sum + ratings[pos];
			newsum -= ratings[pos] < ratings[minPos] ? ratings[pos] : ratings[minPos];
			newsum -= ratings[pos] > ratings[maxPos] ? ratings[pos] : ratings[maxPos];
			if (sample.equals("5.5")) System.out.println(diff*newsum);
			if (diff*newsum >= need-1e-9)
			{
				return sample;
			}
		}
		return "-1.0";
	}
	
	public static void main(String[] args)
	{
		long time;
		String answer;
		boolean errors = false;
		String desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new Diving().needed("3.2", "50.32", "5.5 7.5 10.0 ?.? 4.5");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "0.0";
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
		answer = new Diving().needed("3.2", "50.32", "5.5 5.5 10.0 ?.? 4.5");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "5.0";
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
		answer = new Diving().needed("4.0", "120.00", "9.5 10.0 ?.? 10.0 10.0");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "10.0";
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
		answer = new Diving().needed("4.0", "120.00", "9.5 10.0 ?.? 9.5 10.0");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "-1.0";
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
		answer = new Diving().needed("2.3", ".01", "0.0 0.0 ?.? 0.0 0.5");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "0.5";
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
		answer = new Diving().needed("3.3", "47.85", "0.5 5.5 3.5 7.0 ?.?");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "5.5";
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

