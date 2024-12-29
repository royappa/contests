/*
ID: royappa1
LANG: JAVA
PROG: gift1
*/
import java.io.*;
import java.util.*;
import java.lang.*;
import java.util.regex.*;

class gift1 {

	private static String[] mySplit(String s, String delims)
	{
		StringTokenizer st = new StringTokenizer(s, delims);
		
		ArrayList list = new ArrayList();
		while (st.hasMoreTokens())
		{
			list.add(st.nextToken());
		}
		return (String[]) list.toArray(new String[0]);
	}
  
	public static void main (String [] args) throws IOException 
	{

		BufferedReader in
		   = new BufferedReader(new FileReader("gift1.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(
				new FileWriter("gift1.out")));	  // output file name

		int n = Integer.parseInt(in.readLine());

		int[] recv = new int[n];
		int[] total = new int[n];
		int[] left = new int[n];
		
		ArrayList people = new ArrayList();
		for (int i = 0; i < n; i++)
		{
			String person = in.readLine();
			people.add(person);
		}
		for (int i = 0; i < n; i++)
		{
			String person = in.readLine();
			String line = in.readLine();
			String[] w = mySplit(line, " ");
			int amount = Integer.parseInt(w[0]);
			int friends = Integer.parseInt(w[1]);
			int gift = friends>0 ? amount/friends : 0;
			int iPerson = people.indexOf(person);
			total[iPerson] = amount;
			left[iPerson] = amount-gift*friends;
			for (int j = 0; j < friends; j++)
			{
				String friend = in.readLine();
				int iFriend = people.indexOf(friend);
				recv[iFriend] += gift;
			}
		}

		for (int i = 0; i < n; i++)
		{
			String person = (String) people.get(i);
			out.println(person+" "+  (recv[i] - total[i]+left[i]));
		}
		out.close();                                  // close the output file
		System.exit(0);                               // don't omit this!
		}
	}
