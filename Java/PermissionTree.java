import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class PermissionTree
{

	private int getDepth(int[] parents, int f)
	{
		if (f == 0) return 0;
		return getDepth(parents, parents[f])+1;
	}
	
	// for anything other than f==0 &
	private boolean contains(int[] parent, int p, int f)
	{
		if (f == 0) return false;
		if (f == p) return true;
		return contains(parent, p, parent[f]);
	}
	public int[] findHome(String[] folders, String[] users)
	{
		int numF = folders.length;
		int numU = users.length;
		int[] homes = new int[numU];
		int[] depth = new int[numF];
		int[] par = new int[numF];
		Arrays.fill(par, 0);
		Arrays.fill(depth, 0);
		for (int i = 0; i < numF; i++)
		{
			String[] w = folders[i].split(" ");
			int parent = Integer.parseInt(w[0]);
			par[i] = parent;
		}
		for (int i = 1; i < numF; i++)
		{
			depth[i] = getDepth(par, i);
		}		
		for (int i = 0; i < numU; i++)
		{
			// make a list of folders that the user can access
			String user = users[i];
			ArrayList access = new ArrayList();
			for (int j = 0; j < numF; j++)
			{
				String[] w = folders[j].split(" ");
				int folder = Integer.parseInt(w[0]);
				String[] w2 = w[1].split(",");
				for (int k = 0; k < w2.length; k++)
				{
					if (w2[k].equals(user))
					{
						access.add(""+j);
						break;
					}
				}
			}
			if (access.size() == 0)
			{
				homes[i] = -1;
				continue;
			}
			// walk the list all folders, and find the deepest folder that contains all
			// that he can access
			int home = 0;
			int maxDepth = 0;
			for (int j = 0; j < numF; j++)
			{
				// check if folder j contains all the folders f that the user can access
				boolean containsAll = true;
				for (int k = 0; k < access.size(); k++)
				{
					int f = Integer.parseInt((String) access.get(k));
					if (j == 0)
						break;
					if (!contains(par, j, f))
					{
						containsAll = false;
						break;
					}
				}				
				// check depth of folder j
				if (containsAll)
				{
					if (depth[j] >= maxDepth)
					{
						home = j;
						maxDepth = depth[j];
					}
				}
			}
			homes[i] = home;
		}
		return homes;
	}
	
	public static void main(String[] args)
	{
		long time;
		int[] answer;
		boolean errors = false;
		int[] desiredAnswer;
		
		boolean same;
		time = System.currentTimeMillis();
		answer = new PermissionTree().findHome(new String[]{"0 Admin", "0 Joe,Phil", "0 Joe"}, new String[]{"Admin", "Joe", "Phil"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new int[]{ 0,  0,  1 };
		System.out.println("Your answer:");
		if (answer.length > 0)
		{
			System.out.print("\t{ " + answer[0]);
			for (int i=1; i<answer.length; i++)
				System.out.print(", " + answer[i]);
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		System.out.println("Desired answer:");
		if (desiredAnswer.length > 0)
		{
			System.out.print("\t{ " + desiredAnswer[0]);
			for (int i=1; i<desiredAnswer.length; i++)
				System.out.print(", " + desiredAnswer[i]);
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		same = desiredAnswer.length == answer.length;
		for (int i=0; i<answer.length && same; i++)
			if (answer[i] != desiredAnswer[i])
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
		answer = new PermissionTree().findHome(new String[]{"0 Admin"}, new String[]{"Peter", "Paul", "Mary"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new int[]{ -1,  -1,  -1 };
		System.out.println("Your answer:");
		if (answer.length > 0)
		{
			System.out.print("\t{ " + answer[0]);
			for (int i=1; i<answer.length; i++)
				System.out.print(", " + answer[i]);
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		System.out.println("Desired answer:");
		if (desiredAnswer.length > 0)
		{
			System.out.print("\t{ " + desiredAnswer[0]);
			for (int i=1; i<desiredAnswer.length; i++)
				System.out.print(", " + desiredAnswer[i]);
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		same = desiredAnswer.length == answer.length;
		for (int i=0; i<answer.length && same; i++)
			if (answer[i] != desiredAnswer[i])
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
		answer = new PermissionTree().findHome(new String[]{"0 Admin", "2 John", "0 Peter,John", "0 Tim", "1 John"}, new String[]{"John"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new int[]{ 2 };
		System.out.println("Your answer:");
		if (answer.length > 0)
		{
			System.out.print("\t{ " + answer[0]);
			for (int i=1; i<answer.length; i++)
				System.out.print(", " + answer[i]);
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		System.out.println("Desired answer:");
		if (desiredAnswer.length > 0)
		{
			System.out.print("\t{ " + desiredAnswer[0]);
			for (int i=1; i<desiredAnswer.length; i++)
				System.out.print(", " + desiredAnswer[i]);
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		same = desiredAnswer.length == answer.length;
		for (int i=0; i<answer.length && same; i++)
			if (answer[i] != desiredAnswer[i])
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
		answer = new PermissionTree().findHome(new String[]{"0 Admin","0 Jeff", "1 Mark,Tim", "1 Tim,Jeff","0 Dan", "4 Ed", "4 Tom", "4 Kyle,Ed","0 Ben", "8 Rich", "8 Sam", "8 Tim"}, new String[]{"Jeff", "Ed", "Tim", "Steve"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new int[]{ 1,  4,  0,  -1 };
		System.out.println("Your answer:");
		if (answer.length > 0)
		{
			System.out.print("\t{ " + answer[0]);
			for (int i=1; i<answer.length; i++)
				System.out.print(", " + answer[i]);
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		System.out.println("Desired answer:");
		if (desiredAnswer.length > 0)
		{
			System.out.print("\t{ " + desiredAnswer[0]);
			for (int i=1; i<desiredAnswer.length; i++)
				System.out.print(", " + desiredAnswer[i]);
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		same = desiredAnswer.length == answer.length;
		for (int i=0; i<answer.length && same; i++)
			if (answer[i] != desiredAnswer[i])
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
		answer = new PermissionTree().findHome(new String[]{"0 Admin", "0 Bob,Joe,Bob", "0 Joe"}, new String[]{"Joe", "Bob"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new int[]{ 0,  1 };
		System.out.println("Your answer:");
		if (answer.length > 0)
		{
			System.out.print("\t{ " + answer[0]);
			for (int i=1; i<answer.length; i++)
				System.out.print(", " + answer[i]);
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		System.out.println("Desired answer:");
		if (desiredAnswer.length > 0)
		{
			System.out.print("\t{ " + desiredAnswer[0]);
			for (int i=1; i<desiredAnswer.length; i++)
				System.out.print(", " + desiredAnswer[i]);
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		same = desiredAnswer.length == answer.length;
		for (int i=0; i<answer.length && same; i++)
			if (answer[i] != desiredAnswer[i])
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

