import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class Thesaurus
{
	private boolean common(String[] wi, String[] wj)
	{
		int ni = wi.length; 
		int nj = wj.length;
		int count = 0;
		for (int i = 0; i < ni; i++)
		{
			for (int j = 0; j < nj; j++)
			{
				if (wi[i].equals(wj[j])) count++;
				if (count >= 2) return true;
			}
		}
		return false;
	}

	private String[] merge(String[] wi, String[] wj)
	{
		ArrayList a = new ArrayList();
		
		for (int i = 0; i < wi.length; i++)
		{
			a.add(wi[i]);
		}
		for (int j = 0; j < wj.length; j++)
		{
			if (!a.contains(wj[j])) a.add(wj[j]);
		}
		
		return (String []) a.toArray(new String[0]);
	}

	public String[] edit(String[] entry)
	{
		int n = entry.length;
		LinkedList a = new LinkedList();
		
		// keep making passes until no changes
		// in each pass, merge i'th with 0..i-1, and add remaining new ones to b. THen reset a to b.
		
		for (int i = 0; i < n; i++)
		{
			String[] w = entry[i].split(" ");
			a.add(w);
		}		

		boolean changed = true;
		while (changed)
		{
			changed = false;
			n = a.size();
			// for each i, if i has anything in common with i!=j, then, remove j, add i+j, break.
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (i == j) continue;
					String[] wi = (String []) a.get(i);
					String[] wj = (String []) a.get(j);
					if (common(wi, wj))
					{
						a.remove(Math.max(i,j));
						a.remove(Math.min(i,j));
						a.add(merge(wi, wj));
						changed = true;
						break;
					}						
				}
				if (changed)
				{
					break;
				}
			}
		}
		String[] result = new String[a.size()];
		for (int i = 0; i < a.size(); i++)
		{
			result[i] = "";
			String[] w = (String []) a.get(i);
			Arrays.sort(w);
			for (int j = 0; j  < w.length; j++)
			{
				result[i] += w[j] + " ";
			}
			result[i] = result[i].trim();
		}
		Arrays.sort(result);
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
		answer = new Thesaurus().edit(new String[]{"ape monkey wrench", "wrench twist strain"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "ape monkey wrench",  "strain twist wrench" };
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
		answer = new Thesaurus().edit(new String[]{"ape monkey wrench", "wrench twist strain", "monkey twist frugue"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "ape monkey wrench",  "frugue monkey twist",  "strain twist wrench" };
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
		answer = new Thesaurus().edit(new String[]{"ape monkey wrench", "wrench twist strain", "monkey twist frugue strain"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "ape frugue monkey strain twist wrench" };
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
		answer = new Thesaurus().edit(new String[]{"point run score","point dot","cut run tear score","cut valley","cute pretty"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "cut point run score tear",  "cut valley",  "cute pretty",  "dot point" };
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

