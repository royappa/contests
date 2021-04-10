import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class PointInPolygon
{
	private boolean between(int u, int a, int b)
	{
		return (a <= u && u <= b) || (b <= u && u <= a);
	}
	
	public String testPoint(String[] v, int x, int y)
	{
		int n = v.length;
		int[] px = new int[n];
		int[] py = new int[n];
		
		for (int i = 0; i < n; i++)
		{
			String[] w = v[i].split(" ");
			px[i] = Integer.parseInt(w[0]);
			py[i] = Integer.parseInt(w[1]);
		}
		for (int i = 0; i < n; i++)
		{
			int j = (i+1)%n;
			if (px[i]==px[j]) // vertical line
			{
				if (px[i] == x && between(y, py[i], py[j])) return "BOUNDARY";
			}
			if (py[i]==py[j]) // hor line
			{
				if (py[i] == y && between(x, px[i], px[j])) return "BOUNDARY";
			}			
		}
		int numInt = 0;
		// loop for each vertical edge that is strictly to the right of point
		for (int i = 0; i < n; i++)
		{
			int j = (i+1)%n;
			if (px[i]==px[j] && px[i] > x) // vertical edge to the right of point
			{
				//numInt = number of intersections of a horizontal line through that point
				if (y == py[i] || y == py[j]) continue;
				if (between(y, py[i], py[j]))
				{
					numInt++;
				}
			}			
		}
		return (numInt % 2) == 0 ? "EXTERIOR" : "INTERIOR";
	}
	
	public static void main(String[] args)
	{
		long time;
		String answer;
		boolean errors = false;
		String desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new PointInPolygon().testPoint(new String[]{"0 0", "0 10", "10 10", "10 0"}, 5, 5);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "INTERIOR";
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
		answer = new PointInPolygon().testPoint(new String[]{"0 0", "0 10", "10 10", "10 0"}, 10, 15);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "EXTERIOR";
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
		answer = new PointInPolygon().testPoint(new String[]{"0 0", "0 10", "10 10", "10 0"}, 5, 10);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "BOUNDARY";
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
		answer = new PointInPolygon().testPoint(new String[]{"-100 -90", "-100 100","100 100", "100 -100", "-120 -100","-120 100","-130 100","-130 -110", "110 -110", "110 110", "-110 110","-110 -90"}, 0, 0);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "EXTERIOR";
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
		answer = new PointInPolygon().testPoint(new String[]{"0 0","0 1000","1000 1000","1000 800", "200 800","200 600","600 600","600 400", "200 400","200 200","1000 200","1000 0"}, 100, 500);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "INTERIOR";
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
		answer = new PointInPolygon().testPoint(new String[]{"0 1000","1000 1000","1000 800", "200 800","200 600","600 600","600 400", "200 400","200 200","1000 200","1000 0","0 0"}, 322, 333);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "EXTERIOR";
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
		answer = new PointInPolygon().testPoint(new String[]{"500 0","500 100","400 100","400 200","300 200", "300 300","200 300","200 400","100 400","100 500", "0 500","0 400","-100 400","-100 300","-200 300",  "-200 200","-300 200","-300 100","-400 100","-400 0",  "-500 0","-500 -100","-400 -100","-400 -200","-300 -200",  "-300 -300","-200 -300","-200 -400","-100 -400","-100 -500",  "0 -500","0 -400","100 -400","100 -300","200 -300",  "200 -200","300 -200","300 -100","400 -100","400 0"}, 200, 200);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "INTERIOR";
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
		answer = new PointInPolygon().testPoint(new String[]{"1 0","2 0","2 1","3 1","3 0","4 0","4 -1","5 -1","5 0", "6 0","6 2","0 2","0 3","-1 3","-1 4","0 4","0 6","1 6", "1 7","0 7","0 8","-2 8","-2 2","-8 2","-8 0","-7 0", "-7 -1","-6 -1","-6 0","-4 0","-4 1","-3 1","-3 0", "-2 0","-2 -6","0 -6","0 -5","1 -5","1 -4","0 -4", "0 -3","-1 -3","-1 -2","0 -2","0 -1","1 -1"} , 0, 0);
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "INTERIOR";
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
