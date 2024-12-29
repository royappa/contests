import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class LargestCircle
{

	
	private boolean doesNotIntersectAny(char[][] grid, int cr, int cc, int radius, int nr, int nc)
	{
		int[] inout = {0, 0, 0, 0};
		int radiusSq = radius*radius;
		int cornerR, cornerC;
		
		for (int i = 0; i < nr; i++)
		{
			for (int j = 0; j < nc; j++)
			{
				if (grid[i][j] == '.') continue;
				cornerR = i; cornerC = j;
				inout[0] = radiusSq - ((cornerR-cr)*(cornerR-cr)+(cornerC-cc)*(cornerC-cc));			
				cornerR = i; cornerC = j+1;
				inout[1] = radiusSq - ((cornerR-cr)*(cornerR-cr)+(cornerC-cc)*(cornerC-cc));	
				cornerR = i+1; cornerC = j+1;
				inout[2] = radiusSq - ((cornerR-cr)*(cornerR-cr)+(cornerC-cc)*(cornerC-cc));	
				cornerR = i+1; cornerC = j;
				inout[3] = radiusSq - ((cornerR-cr)*(cornerR-cr)+(cornerC-cc)*(cornerC-cc));
				if (!((inout[0] <= 0 && inout[1] <= 0 && inout[2] <= 0 && inout[3] <= 0) ||
				      (inout[0] >= 0 && inout[1] >= 0 && inout[2] >= 0 && inout[3] >= 0)))
					return false;
			}
		}
		return true;
	}
	public int radius(String[] gridStr)
	{
		int nr = gridStr.length;
		int nc = gridStr[0].length();
		char[][] grid = new char[nr][nc];
		for (int i = 0; i < nr; i++)
		{
			gridStr[i].getChars(0, nc, grid[i], 0);
		}
		int maxr = 0;
		for (int i = 0; i <= nr; i++)
		{
			for (int j = 0; j <= nc; j++)
			{
				int radius = maxr+1;
				while (i>=radius && (nr-i)>=radius && j>=radius && (nc-j)>=radius)
				{
					if (doesNotIntersectAny(grid, i, j, radius, nr, nc))
					{
						maxr = radius;
						//System.out.println(""+i+" "+j+" "+radius+" "+nr+" "+nc);
					}
					radius++;
				}				
			}
		}
		return maxr;
	}
	
	public static void main(String[] args)
	{
		long time;
		int answer;
		boolean errors = false;
		int desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new LargestCircle().radius(new String[]{ "####",  "#..#",  "#..#",  "####" });
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 1;
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
		answer = new LargestCircle().radius(new String[]{ "############",  "###......###",  "##.######.##",  "#.########.#",  "#.##..####.#",  "#.##..####.#",  "#.########.#",  "#.########.#",  "#.########.#",  "##.######.##",  "###......###",  "############" });
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 5;
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
		answer = new LargestCircle().radius(new String[]{ ".........." });
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 0;
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
		answer = new LargestCircle().radius(new String[]{ "#######",  "#######",  "#######",  "#######",  "#######" });
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 0;
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
		answer = new LargestCircle().radius(new String[]{ "#####.......",  "#####.......",  "#####.......",  "............",  "............",  "............",  "............",  "............",  "............",  "............" });
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 4;
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
		answer = new LargestCircle().radius(new String[]{ "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.",  "...#...#...#...#...#...#...#...#...#...#...#...#..",  "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.",  ".#...#...#...#...#...#...#...#...#...#...#...#...#",  "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.",  "...#...#...#...#...#...#...#...#...#...#...#...#..",  "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.",  ".#...#...#...#...#...#...#...#...#...#...#...#...#",  "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.",  "...#...#...#...#...#...#...#...#...#...#...#...#.#",  "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#." });
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 0;
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
		answer = new LargestCircle().radius(new String[]{ ".........................#........................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  "..................................................",  ".................................................." });
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 24;
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

