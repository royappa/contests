import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class ChessKnight
{

	
	public double probability(int x, int y, int n)
	{
		double[][][] board = new double[110][8][8];
		
		x--;
		y--;
		
		int[] dirv = {-2, -2, -1, 1, 2, 2, 1, -1};
		int[] dirh = {-1, 1, 2, 2, 1, -1, -2, -2};
		
		// n = 1
		for (int r = 0; r < 8; r++)
		{
			for (int c = 0; c < 8; c++)
			{
				int count = 0;
				for (int d = 0; d < 8; d++)
				{
					int dr = r+dirv[d];
					int dc = c+dirh[d];
					if (dr >= 0 && dr < 8 && dc >= 0 && dc < 8)
						count++;
				}
				board[1][r][c] = (double) count/8.0;
			}		
		}
		
		for (int i = 2; i <= n; i++)
		{
			for (int r = 0; r < 8; r++)
			{
				for (int c = 0; c < 8; c++)
				{
					int count = 0;
					double prob = 0;
					for (int d = 0; d < 8; d++)
					{
						int dr = r+dirv[d];
						int dc = c+dirh[d];
						if (dr >= 0 && dr < 8 && dc >= 0 && dc < 8)
						{
							prob += board[i-1][dr][dc]/8;
						}
					}
					board[i][r][c] = (double) board[i-1][r][c]*prob;
				}		
			}			
		}
		return board[n][x][y];
		
	}
	
	public static void main(String[] args)
	{
		long time;
		double answer;
		boolean errors = false;
		double desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new ChessKnight().probability(1, 1, 2);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 0.1875D;
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
		answer = new ChessKnight().probability(4, 4, 1);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 1.0D;
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
		answer = new ChessKnight().probability(2, 3, 10);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 0.0522148497402668D;
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
		answer = new ChessKnight().probability(4, 3, 50);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 8.356427906809618E-7D;
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

