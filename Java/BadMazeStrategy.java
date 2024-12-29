import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class BadMazeStrategy
{
	public int numSteps(String[] maze)
	{
		int nr = maze.length, nc = maze[0].length();
		char[][] arr = new char[nr+2][];
		boolean[][] visited = new boolean[nr+2][];
		for (int i = 0; i < nr+2; i++)
		{
			arr[i] = new char[nc+2];
			visited[i] = new boolean[nc+2];
			Arrays.fill(arr[i], 'X');
			Arrays.fill(visited[i], false);
			if (i >=1 && i <= nr) maze[i-1].getChars(0, nc, arr[i], 1);
		}
		int curR = 0, curC = 0;
		for (int r = 1; r <= nr; r++) 
			for (int c = 1; c <= nr; c++)
				if (arr[r][c] == 'Y')
				{
					curR = r;
					curC = c;
					arr[r][c] = '.';
					break;
				}
		//
		int steps = 0;
		int dirh = 1, dirv = 0;
		visited[curR][curC] = true;
		while (arr[curR][curC] != 'D')
		{
			if (steps>1000) return -1;
			if (arr[curR+dirv][curC+dirh] != 'X')
			{
				curR = curR+dirv;
				curC = curC+dirh;
				//if (visited[curR][curC]) { steps = -1; break; }
				//visited[curR][curC] = true;
				steps++;
			}
			else 
			{
				if 	(dirh==1 && dirv==0)  { dirh = 1; dirv = 1; }
				else if (dirh==1 && dirv==1)  { dirh = 0; dirv = 1; }
				else if (dirh==0 && dirv==1)  { dirh = -1; dirv = 1; }
				else if (dirh==-1 && dirv==1) { dirh = -1; dirv = 0; }
				else if (dirh==-1 && dirv==0) { dirh = -1; dirv = -1; }
				else if (dirh==-1 && dirv==-1){ dirh = 0; dirv = -1; }
				else if (dirh==0 && dirv==-1) { dirh = 1; dirv = -1; }
				else if (dirh==1 && dirv==-1) { dirh = 1; dirv = 0; }
			}
		}
		return steps;
	}
	
	public static void main(String[] args)
	{
		long time;
		int answer;
		boolean errors = false;
		int desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new BadMazeStrategy().numSteps(new String[]{"XXXXXXX","X.....X","X.....X","XY...DX","X.....X","XXXXXXX"});
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
		answer = new BadMazeStrategy().numSteps(new String[]{"XXXXXXX","XY....X","X.....X","X.....X","X....DX","XXXXXXX"});
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
		answer = new BadMazeStrategy().numSteps(new String[]{"XXXXXXX","XY....X","X.....X","X..D..X","X.....X","XXXXXXX"});
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
		time = System.currentTimeMillis();
		answer = new BadMazeStrategy().numSteps(new String[]{"DY............."});
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
		answer = new BadMazeStrategy().numSteps(new String[]{"Y..X..............","XXX.XXXXXXXXXXXX.X",".X.X.XX.......D...",".XX.XXX..........."});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 39;
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
