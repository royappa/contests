import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class OfficeParking
{
	public int spacesUsed(String[] events)
	{
		LinkedList spaces = new LinkedList();
		HashMap spacePerson = new HashMap();
		int maxSpace = 1;
		for (int p = 0; p < events.length; p++)
		{
			String[] w = events[p].split(" ");
			String name = w[0], arrdep = w[1];
			if (w[1].equals("arrives"))
			{
				int i;
				for (i = 1; i <= maxSpace; i++)
				{
					if (!spaces.contains(""+i))
						break;
				}
				if (i > maxSpace){
					maxSpace++;
					i = maxSpace;
				}
				spaces.add(""+i);
				spacePerson.put(name, ""+i);
			}
			else
			{
				String inum = (String) spacePerson.get(name);
				int i = spaces.indexOf(inum);
				spaces.remove(i);			
			}
		}
		return maxSpace;
	}
	
	public static void main(String[] args)
	{
		long time;
		int answer;
		boolean errors = false;
		int desiredAnswer;
		
		time = System.currentTimeMillis();
		answer = new OfficeParking().spacesUsed(new String[]{"Alice arrives","bob arrives","Alice departs", "Charles arrives","bob departs","Charles departs"});
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
		answer = new OfficeParking().spacesUsed(new String[]{"AdminBrett arrives","lbackstrom arrives","AdminBrett departs","mike arrives", "TheFaxman arrives","AdminBrett arrives","lbackstrom departs","dok arrives", "AdminBrett departs","gt arrives","AdminBrett arrives","lbackstrom arrives", "AdminBrett departs","jhughes arrives","jhughes departs","TheFaxman departs", "MaryJoe arrives","AdminBrett arrives","AdminBrett departs","AdminBrett arrives"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 6;
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
		answer = new OfficeParking().spacesUsed(new String[]{"SnapDragon arrives","tomek arrives","JohnDethridge arrives","ZorbaTHut arrives", "snewman arrives","reid arrives","NGBronson arrives","Yarin arrives", "bstanescu arrives","mathijs arrives","radeye arrives","bladerunner arrives", "dgarthur arrives","venco arrives","dmwright arrives","WishingBone arrives", "Eryx arrives","antimatter arrives","ChristopherH arrives","lars arrives", "biggnate arrives","JanKuipers arrives","dary arrives","haha arrives","grotmol arrives", "XuChuan arrives","Ryan arrives","LunaticFrindge arrives","Wasteland arrives", "RunningWild arrives","hampster arrives","RalphFurmaniak arrives", "kyky arrives","qubits arrives","Rustyoldman arrives","turuthok arrives", "Vulpecular arrives","Eeyore arrives","wackes arrives","Ishan arrives", "dimkadimon arrives","dplass arrives","Olorin arrives","TangentZ arrives", "NeverMore arrives","Pops arrives","srowan arrives","tjq arrives", "vorthys arrives","schveiguy arrives"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 50;
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
		answer = new OfficeParking().spacesUsed(new String[]{"AdminBrett arrives","AdminBrett departs","AdminBrett arrives","AdminBrett departs", "AdminBrett arrives","AdminBrett departs","AdminBrett arrives","AdminBrett departs", "AdminBrett arrives","AdminBrett departs","AdminBrett arrives","AdminBrett departs", "AdminBrett arrives","AdminBrett departs","AdminBrett arrives","AdminBrett departs"});
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
		answer = new OfficeParking().spacesUsed(new String[]{"snapdragon arrives","SnapDragon arrives", "AdminBrett arrives","AdminBrett departs", "SnapDragon departs","snapdragon departs"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = 3;
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
		answer = new OfficeParking().spacesUsed(new String[]{"departs arrives","arrives arrives","arrives departs","departs departs"});
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
		
		if (errors)
			System.out.println("Some of the test cases had errors :-(");
		else
			System.out.println("You're a stud (at least on the test data)! :-D ");
	}
}

//Powered by [KawigiEdit]

