import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;
import java.util.Collections;

public class bloggoSequenceSearch
{
	public class Compar implements Comparator
	{
		public int compare(Object a, Object b)
		{
			String sa = (String) a;
			String sb = (String) b;
			String[] w1 = sa.split(":");
			String[] w2 = sb.split(":");
			int len1 = w1[2].length();
			int len2 = w2[2].length();
			int d1 = Integer.parseInt(w1[0]);
			int d2 = Integer.parseInt(w2[0]);
			int p1 = Integer.parseInt(w1[1]);
			int p2 = Integer.parseInt(w2[1]);
			if (len1 != len2)
				return len1 - len2;
			if (d1 != d2)
				return d1 - d2;
			return p1 - p2;			
		}
	}
	
	public String[] findPassages(String[] documents, String query)
	{
		// calculate all matches
		query = query.toLowerCase();
		ArrayList mres = new ArrayList();
		String[] lcDoc = new String[documents.length];
		for (int i = 0; i < documents.length; i++)
		{
			lcDoc[i] = documents[i].toLowerCase();
		}
		String[] w = query.split("\\.\\.\\.");
		String pat = "";
		for (int i = 0; i < w.length; i++)
		{
			pat += "(?:"+w[i]+")++.*";
		}
		pat = "("+pat.substring(0, pat.length()-2)+")+";
		Pattern p = Pattern.compile(pat);
		System.out.println(pat);
		for (int i = 0; i < documents.length; i++)
		{

			Matcher m = p.matcher(lcDoc[i]);
			while (m.find())
			{
				mres.add(""+i+":"+m.start()+":"+documents[i].substring(m.start(),m.end()));
			}
		}
		// sort
		String[] preResults = (String[]) mres.toArray(new String[0]);
		Arrays.sort(preResults, new Compar());
		// return string of highest 5 or fewer
		int n = Math.min(5, preResults.length);
		String[] results = new String[n];
		for (int i = 0; i < n; i++)
		{
			String[] w2 = preResults[i].split(":");
			results[i] = w2[0] + " " + w2[1] + " " + "[" + w2[2] + "]";
		}
		return results;
	}
	
	public static void main(String[] args)
	{
		long time;
		String[] answer;
		boolean errors = false;
		String[] desiredAnswer;
		
		boolean same;
		time = System.currentTimeMillis();
		answer = new bloggoSequenceSearch().findPassages(new String[]{"But in a larger sense we can not dedicate --", "we can not consecrate -- we can not hallow this", "ground. The brave men, living and dead, who", "struggled, here, have consecrated it far above", "our poor power to add or detract. The world will", "little note, nor long remember, what we say here,",  "but can never forget what they did here. It is", "for us, the living, rather to be dedicated here", "to the unfinished work which they have, thus", "far, so nobly carried on. It is rather for us", "to be here dedicated to the great task remaining",  "before us -- that from these honored dead we take", "increased devotion to that cause for which they", "here gave the last full measure of devotion --", "that we here highly resolve that these dead", "shall not have died in vain; that this nation", "shall have a new birth of freedom; and that", "this government of the people, by the people,",  "for the people, shall not perish from the earth."}, "the...People");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "17 19 [the people]",  "17 34 [the people]",  "18 4 [the people]",  "17 19 [the people, by the people]" };
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
		answer = new bloggoSequenceSearch().findPassages(new String[]{"But in a larger sense we can not dedicate --", "we can not consecrate -- we can not hallow this", "ground. The brave men, living and dead, who", "struggled, here, have consecrated it far above", "our poor power to add or detract. The world will", "little note, nor long remember, what we say here,",  "but can never forget what they did here. It is", "for us, the living, rather to be dedicated here", "to the unfinished work which they have, thus", "far, so nobly carried on. It is rather for us", "to be here dedicated to the great task remaining",  "before us -- that from these honored dead we take", "increased devotion to that cause for which they", "here gave the last full measure of devotion --", "that we here highly resolve that these dead", "shall not have died in vain; that this nation", "shall have a new birth of freedom; and that", "this government of the people, by the people,",  "for the people, shall not perish from the earth."}, "Shall...The");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "18 16 [shall not perish from the]" };
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
		answer = new bloggoSequenceSearch().findPassages(new String[]{"But in a larger sense we can not dedicate --", "we can not consecrate -- we can not hallow this", "ground. The brave men, living and dead, who", "struggled, here, have consecrated it far above", "our poor power to add or detract. The world will", "little note, nor long remember, what we say here,",  "but can never forget what they did here. It is", "for us, the living, rather to be dedicated here", "to the unfinished work which they have, thus", "far, so nobly carried on. It is rather for us", "to be here dedicated to the great task remaining",  "before us -- that from these honored dead we take", "increased devotion to that cause for which they", "here gave the last full measure of devotion --", "that we here highly resolve that these dead", "shall not have died in vain; that this nation", "shall have a new birth of freedom; and that", "this government of the people, by the people,",  "for the people, shall not perish from the earth."}, "wE...nOT");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "0 22 [we can not]",  "1 0 [we can not]",  "1 25 [we can not]",  "1 0 [we can not consecrate -- we can not]" };
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
		answer = new bloggoSequenceSearch().findPassages(new String[]{"But in a larger sense we can not dedicate --", "we can not consecrate -- we can not hallow this", "ground. The brave men, living and dead, who", "struggled, here, have consecrated it far above", "our poor power to add or detract. The world will", "little note, nor long remember, what we say here,",  "but can never forget what they did here. It is", "for us, the living, rather to be dedicated here", "to the unfinished work which they have, thus", "far, so nobly carried on. It is rather for us", "to be here dedicated to the great task remaining",  "before us -- that from these honored dead we take", "increased devotion to that cause for which they", "here gave the last full measure of devotion --", "that we here highly resolve that these dead", "shall not have died in vain; that this nation", "shall have a new birth of freedom; and that", "this government of the people, by the people,",  "for the people, shall not perish from the earth."}, "we...can...not");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "0 22 [we can not]",  "1 0 [we can not]",  "1 25 [we can not]",  "1 0 [we can not consecrate -- we can not]" };
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
		answer = new bloggoSequenceSearch().findPassages(new String[]{"B A b B B A b a A B b b b a a a B a A b a B B b b ", "A B b b A a A b A A a b b A A a A a A b A a A B b ", "B B a A a a A A A b A b b a a B B b a A a A b a A ", "a b b b b A B a A A A A a b A b A A B a A b b a A ", "A b a A b B B a b A A A A B A A B a A B a b b b B ", "A A A b b a a a A b b b a A A b a B a a B b B a b ", "B A B A a b A B a B b A b B b b A B A A a B A b B ", "A A b B a a b B b a b a A A A B A b b b b A b b A ", "B B A A B B A b a a b a a A B B A A B B A B b A b ", "A a A b B B b A a b b B A a B b b A B b a a a b b ", "B B a b A A a b a A a A a B B A B A A a B B b a B ", "B b B B a B A B b B B a A a a a b b B a A A b a A ", "b B a a a B b a A a A b a a A b A B b a B a b A A ", "A A b B b A a B a a a b B A b B B a b B b b b B B ", "b B a A A A B B b b b b a b B B a a a b B b A A B ", "a B A a a a a A A B A A B b a b A A a A a a B B B ", "B B A B b B B a b B A B A b b A b A B A A b A a b ", "B A A A b A B a b b b a b b b a a A A b A b a A b ", "A a B B B A B b b A B a B a A b B b b a B A B b a ", "B a A A B a a b b B b B A A a A b a a b b b a B b ", "a a b A B a b B B B A A B a B b B A b B b a b A B ", "A a a b a A b B A b B a A B a a A B a A b a b a B ", "A b A b b A b b a B b a A a b A a A A A A a A b A ", "a B B A a B B a b B b a B b A a B B B a B a a b a ", "a a A b B B B a A B a B a A a B a a B b A B b b B ", "A a A B A A A b b B A A a A b B b a A b B A b b A ", "A A a a b B A b a b a A A A B B b B A a A B A B b ", "b a b B a A B a a b B B B A b a A a A A A a a A b ", "a b a a B a B b a B B A A b a B A B b A b a A a a ", "b a a B a a b A B A a b a B A B b b B A b A a b a ", "a B b B a a a A b B B A b b b A A B A b b b B b A ", "B B a A b b a B B b A a a A B B A a A b a a B A A ", "a A a A b b B B a B B b a b b A B a B A a a b a A ", "A B A A a a b A b A B B A b A B b B B a a a A b a ", "b A B b b b a b b A A a A B b B B A a b b B a b a ", "A B B b b a a a B A B b b a b A a a B A b B A B B ", "A b B b B a b a B B B B A a A a a B B b b a b A A ", "B B a a b B a A b A A A a A a b b b a B B A a B a ", "A B a a B A B B a B B b b a B a b b A A B b A A b ", "B b a a A a B b B a b A B B B A b B b A A B a a B ", "B b b A B a a b a B a b A A b B a b b a A B B a A ", "A A b A a a a a B B b b b b A B A B B a B b A a a ", "B B B A b A a a a B a B b b B b a A a b b A B a B ", "A B b b B a b A b B b A B A A A a B B a A b b b B ", "B a A B A b b A b b a A A b b b A B a b B a b A b ", "B a a B a B A b B A b b a b B a b a A b b a A b B ", "a b b a A b A a A B B a b B B a A B A a b B a a a ", "b b a A a a A a a B b A B a A B B a A a B A b A a ", "b b B b B a a b a B B A B b A b A a b b B A B b a ", "a b a B a A B a A A A A A a B a A A a B a b b b b "}, "a...b...a...b...a...a...b...b...a...a...b...b");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "45 24 [a b B a b a A b b a A b B]",  "8 12 [A b a a b a a A B B A A B B]",  "18 18 [A B a B a A b B b b a B A B b]",  "40 16 [a B a b A A b B a b b a A B B]",  "47 16 [a B b A B a A B B a A a B A b]" };
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
		answer = new bloggoSequenceSearch().findPassages(new String[]{ "this government of the people, by the people,",  "for the people, shall not perish from the earth."}, "people");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "0 23 [people]",  "0 38 [people]",  "1 8 [people]" };
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

