import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class BikeRace
{
	public String[] eliminated(int track, String[] name, int[] start, int[] speed)
	{
		int time = 0;
		int n = name.length;
		int count = 0;
		int[] posLap = new int[n];
		int[] posFeet = new int[n];
		Arrays.fill(posLap, 0);
		Arrays.fill(posFeet, 0);
		
		ArrayList all = new ArrayList();
		while (true)
		{
			ArrayList cur = new ArrayList();
			// eliminate 
			int num = 0;
			for (int i = 0; i < n; i++)
			{
				if (all.indexOf(name[i]) >= 0) // don't consider eliminated guys
					continue;
				num++;			
			}
			int[] test = new int[num];
			num = 0;
			for (int i = 0; i < n; i++)
			{
				if (all.indexOf(name[i]) >= 0)
					continue;
				test[num++] = i;
			}
			// move each rider who has already started
			for (int i = 0; i < num; i++)
			{
				int rider = test[i];
				if (time > start[rider])
				{
					posFeet[rider] += speed[rider];
					if (posFeet[rider] >= track)
					{
						posLap[rider]++;
						posFeet[rider] -= track;
					}
				}
			}
			// now test for passing or lapping
			for (int i = 0; i < num; i++)
			{
				int rider1 = test[i];			
				if (time <= start[rider1])
					continue;
				if (cur.indexOf(name[rider1]) >= 0)
					continue;
				for (int j = 0; j < num; j++)
				{
					if (i == j)
						continue;
					int rider2 = test[j];
					String name2 = name[rider2];
					if (cur.indexOf(name2) >= 0) // rider2 already eliminated
						continue;
					if (start[rider1] >= start[rider2])
					{
						if (posLap[rider1] > posLap[rider2])
							cur.add(name2);
						else if (posLap[rider1] == posLap[rider2] && 
							 posFeet[rider1] > posFeet[rider2])
							cur.add(name2);
					}
					else 
					{
						if (time == start[rider2] && posLap[rider1] >= 1)
							cur.add(name2);					
					}
				}			
			}			
			// now move the un-eliminated guys starting at this time
			for (int i = 0; i < num; i++)
			{
				int rider = test[i];
				if (cur.indexOf(name[rider]) >= 0)
					continue;
				if (time == start[rider])
				{
				//System.out.println("Start " + name[rider] + " " + time);
					posFeet[rider] = speed[rider];
				}
			}
			Collections.sort(cur);
			for (int i = 0; i < cur.size(); i++)
			{
				all.add((String) cur.get(i));
			}			
			if (all.size() == n)
			{
				break;
			}
			int s = 0;
			for (int i = 0; i < n; i++)
			{
				if (all.indexOf(name[i]) >= 0)
					continue;
				s = speed[i];
				break;
			}
			boolean same = true;
			for (int i = 0; i < n; i++)
			{
				if (all.indexOf(name[i]) >= 0)
					continue;
				if (speed[i] != s)
					same = false;
			}
			if (same)
				break;
			time++;	
		}
		return (String[]) all.toArray(new String[0]);
	}
	
	public static void main(String[] args)
	{
		long time;
		String[] answer;
		boolean errors = false;
		String[] desiredAnswer;
		
		boolean same;
		time = System.currentTimeMillis();
		answer = new BikeRace().eliminated(4800 , new String[]{"A","B","C"}, new int[]{ 0, 100,180} , new int[]{30, 30, 30} );
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "C" };
		System.out.println("Your answer:");
		if (answer.length > 0)
		{
			System.out.print("\t{ \"" + answer[0] + "\"");
			for (int i=1; i<answer.length; i++)
				System.out.print(",\n\t  \"" + answer[i] + "\"");
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		System.out.println("Desired answer:");
		if (desiredAnswer.length > 0)
		{
			System.out.print("\t{ \"" + desiredAnswer[0] + "\"");
			for (int i=1; i<desiredAnswer.length; i++)
				System.out.print(",\n\t  \"" + desiredAnswer[i] + "\"");
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		same = desiredAnswer.length == answer.length;
		for (int i=0; i<answer.length && same; i++)
			if (!answer[i].equals(desiredAnswer[i]))
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
		answer = new BikeRace().eliminated(3000, new String[]{"BO","JO", "AL"}, new int[]{ 10,  0,    15 } , new int[]{ 12,  2,    10 } );
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "JO",  "AL" };
		System.out.println("Your answer:");
		if (answer.length > 0)
		{
			System.out.print("\t{ \"" + answer[0] + "\"");
			for (int i=1; i<answer.length; i++)
				System.out.print(",\n\t  \"" + answer[i] + "\"");
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		System.out.println("Desired answer:");
		if (desiredAnswer.length > 0)
		{
			System.out.print("\t{ \"" + desiredAnswer[0] + "\"");
			for (int i=1; i<desiredAnswer.length; i++)
				System.out.print(",\n\t  \"" + desiredAnswer[i] + "\"");
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		same = desiredAnswer.length == answer.length;
		for (int i=0; i<answer.length && same; i++)
			if (!answer[i].equals(desiredAnswer[i]))
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
		answer = new BikeRace().eliminated(3000, new String[]{"BOBO","JOHNNY","ANNA"}, new int[]{67,0,15}, new int[]{50,45,3});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "BOBO",  "ANNA" };
		System.out.println("Your answer:");
		if (answer.length > 0)
		{
			System.out.print("\t{ \"" + answer[0] + "\"");
			for (int i=1; i<answer.length; i++)
				System.out.print(",\n\t  \"" + answer[i] + "\"");
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		System.out.println("Desired answer:");
		if (desiredAnswer.length > 0)
		{
			System.out.print("\t{ \"" + desiredAnswer[0] + "\"");
			for (int i=1; i<desiredAnswer.length; i++)
				System.out.print(",\n\t  \"" + desiredAnswer[i] + "\"");
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		same = desiredAnswer.length == answer.length;
		for (int i=0; i<answer.length && same; i++)
			if (!answer[i].equals(desiredAnswer[i]))
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
		answer = new BikeRace().eliminated(3000, new String[]{"B","J","A"}, new int[]{66,0,15}, new int[]{50,45,3});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "A",  "J" };
		System.out.println("Your answer:");
		if (answer.length > 0)
		{
			System.out.print("\t{ \"" + answer[0] + "\"");
			for (int i=1; i<answer.length; i++)
				System.out.print(",\n\t  \"" + answer[i] + "\"");
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		System.out.println("Desired answer:");
		if (desiredAnswer.length > 0)
		{
			System.out.print("\t{ \"" + desiredAnswer[0] + "\"");
			for (int i=1; i<desiredAnswer.length; i++)
				System.out.print(",\n\t  \"" + desiredAnswer[i] + "\"");
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		same = desiredAnswer.length == answer.length;
		for (int i=0; i<answer.length && same; i++)
			if (!answer[i].equals(desiredAnswer[i]))
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
		answer = new BikeRace().eliminated(5000, new String[]{"TOM","TOMMY","BILL","SPEEDY","JIMMY"}, new int[]{100,120,110,0,1000}, new int[]{50,50,50,50,50});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "BILL",  "JIMMY",  "TOM",  "TOMMY" };
		System.out.println("Your answer:");
		if (answer.length > 0)
		{
			System.out.print("\t{ \"" + answer[0] + "\"");
			for (int i=1; i<answer.length; i++)
				System.out.print(",\n\t  \"" + answer[i] + "\"");
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		System.out.println("Desired answer:");
		if (desiredAnswer.length > 0)
		{
			System.out.print("\t{ \"" + desiredAnswer[0] + "\"");
			for (int i=1; i<desiredAnswer.length; i++)
				System.out.print(",\n\t  \"" + desiredAnswer[i] + "\"");
			System.out.println(" }");
		}
		else
			System.out.println("\t{ }");
		same = desiredAnswer.length == answer.length;
		for (int i=0; i<answer.length && same; i++)
			if (!answer[i].equals(desiredAnswer[i]))
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

