import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class TournamentRanker
{
	private class Compare implements Comparator
	{
		private ArrayList names;
		private ArrayList lostTo;
		private int n;
		Compare(String[] _names, String[] _lostTo, int _n)
		{
			names = new ArrayList();
			lostTo = new ArrayList();
			n = _n;
			for (int i = 0; i < n; i++)
			{
				names.add(_names[i]);
				lostTo.add(_lostTo[i]);
			}
		}
		
		public int compare(Object oa, Object ob)
		{
			String a = (String) oa;
			String b = (String) ob;
			return compare_rec(a, b);
		}
		
		private int numWins(String x)
		{
			int num = 0;
			for (int i = 0; i < n; i++)
			{
				if (((String) lostTo.get(i)).equals(x))
					num++;
			}
			return num;
		}
		private int compare_rec(String a, String b)
		{
			int ia = names.indexOf(a);
			int ib = names.indexOf(b);
			String aLost = (String) lostTo.get(ia);
			String bLost = (String) lostTo.get(ib);
			if (a.equals(b)) return 0;
			int na = numWins(a);
			int nb = numWins(b);
			if (na != nb) return nb - na;
			return compare_rec(aLost, bLost);			
		}
	}

	public String[] rankTeams(String[] names, String[] lostTo)
	{
		int n = names.length;
		
		String[] ranked = new String[n];
		System.arraycopy(names, 0, ranked, 0, n);
		Arrays.sort(ranked, new Compare(names, lostTo, n));
		return ranked;
	}
	
	public static void main(String[] args)
	{
		long time;
		String[] answer;
		boolean errors = false;
		String[] desiredAnswer;
		
		boolean same;
		time = System.currentTimeMillis();
		answer = new TournamentRanker().rankTeams(new String[]{"RODDICK", "SCHUETTLER", "FERREIRA", "AGASSI"}, new String[]{"SCHUETTLER", "AGASSI", "AGASSI", ""});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "AGASSI",  "SCHUETTLER",  "FERREIRA",  "RODDICK" };
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
		answer = new TournamentRanker().rankTeams(new String[]{"DUKE", "SETON HALL", "ILLINOIS", "CINCINNATI", "NORTH CAROLINA", "TEXAS", "XAVIER", "MISSISSIPPI STATE"}, new String[]{"", "DUKE", "DUKE", "ILLINOIS", "TEXAS", "XAVIER", "DUKE", "XAVIER"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "DUKE",  "XAVIER",  "ILLINOIS",  "TEXAS",  "SETON HALL",  "MISSISSIPPI STATE",  "CINCINNATI",  "NORTH CAROLINA" };
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
		answer = new TournamentRanker().rankTeams(new String[]{"JAVA", "VISUAL BASIC"}, new String[]{"VISUAL BASIC", ""});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "VISUAL BASIC",  "JAVA" };
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

