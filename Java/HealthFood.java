import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class HealthFood
{
	public class Compar implements Comparator
	{
		int[] key;
		boolean[] asc;
		int num;
		
		public Compar(String _key)
		{
			num = _key.length();
			key = new int[num];
			asc = new boolean[num];
			for (int i = 0; i < num; i++)
			{
				char ch = Character.toLowerCase(_key.charAt(i));
				key[i] = ch=='p'?0:
						ch=='c'?1:
						ch=='f'?2:3;
				asc[i] = Character.isLowerCase(_key.charAt(i));
			}
		}
		public int compare(Object oa, Object ob)
		{
			int[] a = (int[]) oa;
			int[] b = (int[]) ob;
			for (int i = 0; i < num; i++)
			{
				if (a[key[i]]==b[key[i]])
					continue;
				return asc[i] ? a[key[i]]-b[key[i]] : b[key[i]]-a[key[i]];
			}
			return a[4]-b[4];
		}

	}
	public int[] selectMeals(int[] protein, int[] carbs, int[] fat, String[] dietPlans)
	{
		int nmenu = protein.length;
		int nplan = dietPlans.length;
		int[][] all = new int[nmenu][5];
		
		for (int i = 0; i < nmenu; i++)
		{
			all[i][0] = protein[i];
			all[i][1] = carbs[i];
			all[i][2] = fat[i];
			all[i][3] = protein[i]*5+carbs[i]*5+fat[i]*9;
			all[i][4] = i;
		}
		
		int[] best = new int[nplan];
		int[] total = new int[nmenu];
		for (int i = 0; i < nplan; i++)
		{
			// choose best plan for dietPlans[i] & put its index into best[i]
			if (dietPlans[i].length() == 0)
			{
				best[i] = 0;
				continue;
			}
			Arrays.sort(all, new Compar(dietPlans[i]));				
			//System.out.print(i + " " + dietPlans[i] + " ");
			//for (int m = 0; m < nmenu; m++) System.out.print(all[m][4]+" "); System.out.println("");
			best[i] = all[0][4];
		}
		return best;
	}
	
	
	public static void main(String[] args)
	{
		long time;
		int[] answer;
		boolean errors = false;
		int[] desiredAnswer;
		
		boolean same;
		time = System.currentTimeMillis();
		answer = new HealthFood().selectMeals(new int[]{3, 4}, new int[]{2, 8}, new int[]{5, 2}, new String[]{"P", "p", "C", "c", "F", "f", "T", "t"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new int[]{ 1,  0,  1,  0,  0,  1,  1,  0 };
		System.out.println("Your answer:");
		if (answer.length > 0)
		{
			System.out.print("\t{ " + answer[0]);
			for (int i=1; i<answer.length; i++)
				System.out.print(", " + answer[i]);
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		System.out.println("Desired answer:");
		if (desiredAnswer.length > 0)
		{
			System.out.print("\t{ " + desiredAnswer[0]);
			for (int i=1; i<desiredAnswer.length; i++)
				System.out.print(", " + desiredAnswer[i]);
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		same = desiredAnswer.length == answer.length;
		for (int i=0; i<answer.length && same; i++)
			if (answer[i] != desiredAnswer[i])
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
		answer = new HealthFood().selectMeals(new int[]{3, 4, 1, 5}, new int[]{2, 8, 5, 1}, new int[]{5, 2, 4, 4}, new String[]{"tFc", "tF", "Ftc"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new int[]{ 3,  2,  0 };
		System.out.println("Your answer:");
		if (answer.length > 0)
		{
			System.out.print("\t{ " + answer[0]);
			for (int i=1; i<answer.length; i++)
				System.out.print(", " + answer[i]);
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		System.out.println("Desired answer:");
		if (desiredAnswer.length > 0)
		{
			System.out.print("\t{ " + desiredAnswer[0]);
			for (int i=1; i<desiredAnswer.length; i++)
				System.out.print(", " + desiredAnswer[i]);
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		same = desiredAnswer.length == answer.length;
		for (int i=0; i<answer.length && same; i++)
			if (answer[i] != desiredAnswer[i])
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
		answer = new HealthFood().selectMeals(new int[]{18, 86, 76,  0, 34, 30, 95, 12, 21}, new int[]{26, 56,  3, 45, 88,  0, 10, 27, 53}, new int[]{93, 96, 13, 95, 98, 18, 59, 49, 86}, new String[]{"f", "Pt", "PT", "fT", "Cp", "C", "t", "", "cCp", "ttp", "PCFt", "P", "pCt", "cP", "Pc"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new int[]{ 2,  6,  6,  2,  4,  4,  5,  0,  5,  5,  6,  6,  3,  5,  6 };
		System.out.println("Your answer:");
		if (answer.length > 0)
		{
			System.out.print("\t{ " + answer[0]);
			for (int i=1; i<answer.length; i++)
				System.out.print(", " + answer[i]);
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		System.out.println("Desired answer:");
		if (desiredAnswer.length > 0)
		{
			System.out.print("\t{ " + desiredAnswer[0]);
			for (int i=1; i<desiredAnswer.length; i++)
				System.out.print(", " + desiredAnswer[i]);
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		same = desiredAnswer.length == answer.length;
		for (int i=0; i<answer.length && same; i++)
			if (answer[i] != desiredAnswer[i])
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

