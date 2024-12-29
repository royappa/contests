import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class ImageEnlarger
{
	public String[] enlarge(String[] image, int factor)
	{
		int m = image.length;
		
		String[] mag = new String[m*factor];
		
		int num = 0;
		for (int i = 0; i < m; i++)
		{
			String magLine = "";
			for (int j = 0; j < image[i].length(); j++)
			{
				char ch = image[i].charAt(j);
				for (int k = 0; k < factor; k++)
					magLine += ch;
			}
			for (int j = 0; j < factor; j++)
			{
				mag[num++] = magLine;
			}
		}
		
		return mag;
	}
	
	public static void main(String[] args)
	{
		long time;
		String[] answer;
		boolean errors = false;
		String[] desiredAnswer;
		
		boolean same;
		time = System.currentTimeMillis();
		answer = new ImageEnlarger().enlarge(new String[]{"abc", "def", "ghi"}, 3);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "aaabbbccc",  "aaabbbccc",  "aaabbbccc",  "dddeeefff",  "dddeeefff",  "dddeeefff",  "ggghhhiii",  "ggghhhiii",  "ggghhhiii" };
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
		answer = new ImageEnlarger().enlarge(new String[]{"ab", "cd"}, 0);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ };
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
		answer = new ImageEnlarger().enlarge(new String[]{"---------", "-TTT--CC-", "--T--C---", "--T--C---", "--T---CC-", "---------"}, 10);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "----------TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT--------------------CCCCCCCCCCCCCCCCCCCC----------",  "----------TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT--------------------CCCCCCCCCCCCCCCCCCCC----------",  "----------TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT--------------------CCCCCCCCCCCCCCCCCCCC----------",  "----------TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT--------------------CCCCCCCCCCCCCCCCCCCC----------",  "----------TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT--------------------CCCCCCCCCCCCCCCCCCCC----------",  "----------TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT--------------------CCCCCCCCCCCCCCCCCCCC----------",  "----------TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT--------------------CCCCCCCCCCCCCCCCCCCC----------",  "----------TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT--------------------CCCCCCCCCCCCCCCCCCCC----------",  "----------TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT--------------------CCCCCCCCCCCCCCCCCCCC----------",  "----------TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT--------------------CCCCCCCCCCCCCCCCCCCC----------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT--------------------CCCCCCCCCC------------------------------",  "--------------------TTTTTTTTTT------------------------------CCCCCCCCCCCCCCCCCCCC----------",  "--------------------TTTTTTTTTT------------------------------CCCCCCCCCCCCCCCCCCCC----------",  "--------------------TTTTTTTTTT------------------------------CCCCCCCCCCCCCCCCCCCC----------",  "--------------------TTTTTTTTTT------------------------------CCCCCCCCCCCCCCCCCCCC----------",  "--------------------TTTTTTTTTT------------------------------CCCCCCCCCCCCCCCCCCCC----------",  "--------------------TTTTTTTTTT------------------------------CCCCCCCCCCCCCCCCCCCC----------",  "--------------------TTTTTTTTTT------------------------------CCCCCCCCCCCCCCCCCCCC----------",  "--------------------TTTTTTTTTT------------------------------CCCCCCCCCCCCCCCCCCCC----------",  "--------------------TTTTTTTTTT------------------------------CCCCCCCCCCCCCCCCCCCC----------",  "--------------------TTTTTTTTTT------------------------------CCCCCCCCCCCCCCCCCCCC----------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------",  "------------------------------------------------------------------------------------------" };
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

