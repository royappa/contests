import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class MagicSquare
{
	private int ind(int[] square, int i, int j)
	{
		return square[i*3+j];
	}
	
	public int missing(int[] square)
	{
	for (int i = 0; i < 9; i++) if (square[i] == -1) square[i]= 0;
		int sum1 = ind(square, 0, 0)+ind(square,0,1)+ind(square,0,2);
		int sum2 = ind(square, 1, 0)+ind(square, 1, 1)+ind(square, 1, 2);
		int sum3 = ind(square, 2, 0)+ind(square, 2, 1)+ind(square, 2, 2);
		
		int sum = 0;
		if (sum1 == sum2) 
			sum = sum1;
		else if (sum1 == sum3)
			sum = sum1;
		else 
			sum = sum2;
			
		for (int r = 0; r < 3; r++)
		{
			int s = ind(square, r, 0)+ind(square, r, 1) + ind(square, r, 2);			
			if (s != sum) return sum-s;
			s = ind(square, 0, r)+ind(square, 1, r) + ind(square, 2, r);			
			if (s != sum) return (sum-s);		
		}
		int s = ind(square, 0, 0)+ind(square, 1, 1) + ind(square, 2, 2);			
		if (s != sum) return (sum-s);			
		s = ind(square, 0, 2)+ind(square, 1, 1) + ind(square, 2, 0);
		if (s != sum) return (sum-s);	
		
		return 0;		
	}
	
	public static void main(String[] args)
	{
		long time;
		int answer;
		boolean errors = false;
		int desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new MagicSquare().missing(new int[]{ 8, 1, 6, 3, 5, -1, 4, 9, 2 });
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 7;
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
		answer = new MagicSquare().missing(new int[]{ -1, 1, 6, 3, 5, 7, 4, 9, 2 });
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 8;
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
		answer = new MagicSquare().missing(new int[]{ 5, 15, 13, 19, 11, 3, 9, 7, -1 });
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 17;
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

