import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class TerribleEncryption
{
	public String decrypt(String pool, int[] data, int[] keys)
	{
		int poolLen = pool.length();
		char[] ret = new char[data.length];
		for (int i = 0; i < data.length; i++)
		{
			int k = 1;
			while (true)
			{
				if ((data[i]*k)%keys[i] == 1)
					break;
				k++;
			}
			ret[i] = pool.charAt(k%poolLen);
		}
		
		return new String(ret);
	}
	
	public static void main(String[] args)
	{
		long time;
		String answer;
		boolean errors = false;
		String desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new TerribleEncryption().decrypt("ABCDEFGHIJKLMNOPQRSTUVWXYZ", new int[]{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}, new int[]{17,17,17,17,17,17,17,17,17,17,17,17,17,17,17});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "BJGNHDFPCMOKELI";
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
		answer = new TerribleEncryption().decrypt("AEIOUAEIOUaeiouaeiou", new int[]{1,2,3,4,5,6,7,8,9,10,1,2,3,4,5}, new int[]{2,3,4,5,6,7,8,9,10,11,13,15,16,17,18});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "EIOUAEIOUaEOeoe";
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
		answer = new TerribleEncryption().decrypt("abcdeffedcbaABCDEFFEDCBA", new int[]{10,10,10,10,10,10,10,10,10,10,10}, new int[]{3,7,11,13,17,19,23,29,31,37,41});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "bfbeAcedecB";
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
		answer = new TerribleEncryption().decrypt("abcdefghijklmnopqrstuvwxyz", new int[]{11,11,11,11,11,11,11,11,11,11,11,11,11,11,11}, new int[]{2,3,4,5,6,7,8,9,10,12,13,14,15,16,17});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "bcdbfcdfblgjldo";
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
		answer = new TerribleEncryption().decrypt("HmmBlahHmmBlah", new int[]{1,1,1,1,1,1,1}, new int[]{10,9,8,7,6,5,4});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "mmmmmmm";
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

