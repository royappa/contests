import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class ParameterSubstitution
{
	public String processParams(String code, String[] params)
	{
		String all = "";
		int len = code.length();
		for (int i = 0; i < len; i++)
		{
			char ch = code.charAt(i);
			if (ch != '$' || i == len-1)
			{
				all += ch;
				continue;
			}
			char next = code.charAt(i+1);
			if (!Character.isDigit(next) || next == '0')
				continue;
			int num = next-'0';
			String rep = "";
			if (num-1 < params.length)
			{
				rep = params[num-1];
			}
			else
			{
				all += next;
				continue;
			}
			int j = i+2;
			while (j < len)
			{
				next = code.charAt(j);
				if (!Character.isDigit(next))
					break;
				num = num*10+(next-'0');
				if (num-1 < params.length)
				{
					rep = params[num-1];
				}
				else
				{
					break;
				}
				j++;
			}
			all += rep;
			i = j-1;
		}
		return all;
	}
	
	public static void main(String[] args)
	{
		long time;
		String answer;
		boolean errors = false;
		String desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new ParameterSubstitution().processParams("if ($1 == $2) $3;", new String[]{"12", "12", "doWhatIWant()"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "if (12 == 12) doWhatIWant();";
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
		answer = new ParameterSubstitution().processParams("$3+$1*$2-$7=$10", new String[]{"myvar", "490jri", "e09jd9", "dlkjfoiej"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "e09jd9+myvar*490jri-$7=myvar0";
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
		answer = new ParameterSubstitution().processParams("12342123$13231232$2123211242$a$dlkj$", new String[]{"$2", "$1"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "12342123$23231232$1123211242$a$dlkj$";
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
		answer = new ParameterSubstitution().processParams("{[(+.*-,/\\:;<=>?@)]}_`~|$$1", new String[]{"1{[(+.*-,/\\:;<=>?@)]}_`~|"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "{[(+.*-,/\\:;<=>?@)]}_`~|$1{[(+.*-,/\\:;<=>?@)]}_`~|";
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
		answer = new ParameterSubstitution().processParams("$01", new String[]{"abc"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "$01";
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

