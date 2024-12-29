import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class WalkingHome
{

	private int distance(int ur, int uc, int vr, int vc, char[][] map)
	{
		String all = "";
		if (ur==vr)
		{
			int ucm = Math.min(uc, vc);
			int vcm = Math.max(uc, vc);
			for (int i = ucm+1; i <= vcm-1; i++)
			{
				all += map[ur][i];
			}
			if (all.matches("\\.*"))
				return 0;
			else if (all.matches("\\|+"))
				return 1;
			return -1;
		}
		else if (uc==vc)
		{
			int urm = Math.min(ur, vr);
			int vrm = Math.max(ur, vr);
			for (int i = urm+1; i <= vrm-1; i++)
			{
				all += map[i][uc];
			}
			if (all.matches("\\.*"))
				return 0;
			else if (all.matches("\\-+"))
				return 1;
			return -1;
		}
		return -1;
	}
	
	public int fewestCrossings(String[] mapS)
	{
		int height = mapS.length;
		int width = mapS[0].length();
		char[][] map = new char[height][];
		int rowH = 0, colH = 0, rowS = 0, colS = 0;
		
		int[][] dist = new int[50][50];
		int[] qr = new int[10000];
		int[] qc = new int[10000];
		int numQ = 0;
		for (int r = 0; r < height; r++)
		{
			map[r] = mapS[r].toCharArray();
			for (int c = 0; c < width; c++)
			{
				dist[r][c] = 1000000;
				if (map[r][c] == 'H')
				{
					rowH = r;
					colH = c;
				}
				if (".SH".indexOf(map[r][c])>=0)
				{
					String pos = r+" "+c;
					if (map[r][c]=='H') 
						dist[r][c] = 0;
					qr[numQ] = r;
					qc[numQ] = c;
					numQ++;
				}
				if (map[r][c] == 'S')
				{
					rowS = r;
					colS = c;
				}
			}
		}
		
		while (numQ > 0)
		{
			int min = Integer.MAX_VALUE;
			int pos = 0;
			for (int i = 0; i < numQ; i++)
			{
				if (dist[qr[i]][qc[i]] <= min)
				{
					min = dist[qr[i]][qc[i]];
					pos = i;
				}			
			}
			int ur = qr[pos];
			int uc = qc[pos];
			qr[pos] = qr[numQ-1];
			qc[pos] = qc[numQ-1];
			numQ--;
			
			for (int i = 0; i < numQ; i++)
			{
				int vr = qr[i];
				int vc = qc[i];
				int duv = distance(ur, uc, vr, vc, map);
				if (duv >= 0)
				{
					int du = dist[ur][uc];
					int dv = dist[vr][vc];
					if (du+duv < dv)
					{
						dist[vr][vc] = du+duv;
					}
				}
			}
		}	
		int ds = dist[rowS][colS];
		return ds == 1000000 ? -1 : ds;
	}
	
	public static void main(String[] args)
	{
		long time;
		int answer;
		boolean errors = false;
		int desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new WalkingHome().fewestCrossings(new String[]{"S.|..", "..|.H"});
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
		answer = new WalkingHome().fewestCrossings(new String[]{"S.|..", "..|.H", "..|..", "....."});
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
		answer = new WalkingHome().fewestCrossings(new String[]{"S.||...", "..||...", "..||...", "..||..H"});
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
		answer = new WalkingHome().fewestCrossings(new String[]{"S.....", "---*--", "...|..", "...|.H"});
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
		answer = new WalkingHome().fewestCrossings(new String[]{"S.F..", "..F..", "--*--", "..|..", "..|.H"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 2;
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
		answer = new WalkingHome().fewestCrossings(new String[]{"H|.|.|.|.|.|.|.|.|.|.|.|.|.", "F|F|F|F|F|F|F|F|F|F|F|F|F|-", "S|.|.|.|.|.|.|.|.|.|.|.|.|."});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 27;
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
		answer = new WalkingHome().fewestCrossings(new String[]{"S-H"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = -1;
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
