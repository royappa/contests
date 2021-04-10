import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class Mortgage
{
	private int calcBalance(int payment, int loan, int interest, int term)
	{
	System.out.println(payment);
		double balance = loan;
		for (int month = 1; month <= term*12; month++)
		{
			balance -= payment;
			if (balance < 0)
				return -1;
			balance *= (1.0 + interest/12.0/100.0/10.0);
			balance = Math.ceil(balance);
			if (balance > loan)
				return 1;
		}
		return (int) balance;
	}
	private int payOff(int min, int max, int loan, int interest, int term)
	{
		if (min == max)
		{
			return min;
		}
		if (max == min+1)
		{
			if (calcBalance(min, loan, interest, term) <= 0)
				return min;
			return max;
		}
		
		double dMid = ((double)min+(double)max)/2.0;
		int mid = (int) Math.floor( dMid);
		
		int bal = calcBalance(mid, loan, interest, term);
		if (bal > 0)
			return payOff(mid, max, loan, interest, term);
		return payOff(min, mid, loan, interest, term);
	}
	public int monthlyPayment(int loan, int interest, int term)
	{
		
		return payOff(1, loan, loan, interest, term);
	}
	
	public static void main(String[] args)
	{
		long time;
		int answer;
		boolean errors = false;
		int desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new Mortgage().monthlyPayment(1000, 50, 1);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 86;
		System.out.println("Your answer:");
		System.out.println("\t" + answer);
		System.out.println("Desired answer:");
		System.out.println("\t" + desiredAnswer);
		if (answer != desiredAnswer)
		{
			errors = true;
			System.out.println("DOESN'T MATCH!!!!");
		}
		else
			System.out.println("Match :-)");
		System.out.println();
		time = System.currentTimeMillis();
		answer = new Mortgage().monthlyPayment(2000000000, 6000, 1);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 671844808;
		System.out.println("Your answer:");
		System.out.println("\t" + answer);
		System.out.println("Desired answer:");
		System.out.println("\t" + desiredAnswer);
		if (answer != desiredAnswer)
		{
			errors = true;
			System.out.println("DOESN'T MATCH!!!!");
		}
		else
			System.out.println("Match :-)");
		System.out.println();
		time = System.currentTimeMillis();
		answer = new Mortgage().monthlyPayment(1000000, 1000000, 1000);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 988143;
		System.out.println("Your answer:");
		System.out.println("\t" + answer);
		System.out.println("Desired answer:");
		System.out.println("\t" + desiredAnswer);
		if (answer != desiredAnswer)
		{
			errors = true;
			System.out.println("DOESN'T MATCH!!!!");
		}
		else
			System.out.println("Match :-)");
		System.out.println();
		time = System.currentTimeMillis();
		answer = new Mortgage().monthlyPayment(1000000, 129, 30);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 10868;
		System.out.println("Your answer:");
		System.out.println("\t" + answer);
		System.out.println("Desired answer:");
		System.out.println("\t" + desiredAnswer);
		if (answer != desiredAnswer)
		{
			errors = true;
			System.out.println("DOESN'T MATCH!!!!");
		}
		else
			System.out.println("Match :-)");
		System.out.println();
		time = System.currentTimeMillis();
		answer = new Mortgage().monthlyPayment(1999999999, 1000000, 1);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 1976284585;
		System.out.println("Your answer:");
		System.out.println("\t" + answer);
		System.out.println("Desired answer:");
		System.out.println("\t" + desiredAnswer);
		if (answer != desiredAnswer)
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

