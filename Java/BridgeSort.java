import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class BridgeSort
{
	private class cardSorter implements Comparator
	{
		public int compare(Object a, Object b)
		{
			String sa = (String) a;
			String sb = (String) b;
			String suits = "CDHS";
			String cards = "23456789TJQKA";
			//System.out.println(sa+" "+sb);
			char suita = sa.charAt(0), carda = sa.charAt(1);
			char suitb = sb.charAt(0), cardb = sb.charAt(1);
			int va = (suits.indexOf(suita)+1)*100+cards.indexOf(carda);
			int vb = (suits.indexOf(suitb)+1)*100+cards.indexOf(cardb);
			return va-vb;			
		}
	}
	
	public String sortedHand(String hand)
	{
		int n = hand.length()/2;
		String [] cards = new String[n];
		for (int i = 0; i < n; i++)
		{
			cards[i] = hand.substring(2*i,2*i+2);
		}
		Arrays.sort(cards, new cardSorter());
		String sorted = "";
		for (int i = 0; i < n; i++)
		{
			sorted += cards[i];
		}
		return sorted;			
	}
	
	public static void main(String[] args)
	{
		long time;
		String answer;
		boolean errors = false;
		String desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new BridgeSort().sortedHand("HAH2H3C4D5ST" );
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "C4D5H2H3HAST";
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
		answer = new BridgeSort().sortedHand("H3SAHA");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "H3HASA";
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

