import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class SignatureDecorator
{
	public String applyDecoration(String name, String[] commands, String[] decorations)
	{
		for (int i = 0; i < commands.length; i++)
		{
			String ch = decorations[i];
			if (commands[i].equals("prepend"))
			{
				name = ch+name;
			}
			else if (commands[i].equals("append"))
			{
				name = name+ch;
			}
			else
			{
				name = ch+name;
				for (int j = ch.length()-1; j >= 0; j--)
				{
					name += ch.charAt(j);
				}
			}
		}
		return name;
		
	}
	
	public static void main(String[] args)
	{
		long time;
		String answer;
		boolean errors = false;
		String desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new SignatureDecorator().applyDecoration("Bob", new String[]{"surround", "append", "prepend"}, new String[]{"-=", "(", ")"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = ")-=Bob=-(";
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
		answer = new SignatureDecorator().applyDecoration("Super_Man_01", new String[]{}, new String[]{});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "Super_Man_01";
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
		answer = new SignatureDecorator().applyDecoration("4BcD3FgHIjklMN0pqrS7uVWxYZ_", new String[]{"append", "prepend", "surround"}, new String[]{"`{[(", ")]}'", ",.;<>?:|-=_+!@#$%^&*~"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = ",.;<>?:|-=_+!@#$%^&*~)]}'4BcD3FgHIjklMN0pqrS7uVWxYZ_`{[(~*&^%$#@!+_=-|:?><;.,";
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
		answer = new SignatureDecorator().applyDecoration("RacEcaR", new String[]{"surround"}, new String[]{"([{/"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "([{/RacEcaR/{[(";
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
