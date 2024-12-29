import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class HierarchicalTree
{
	private int numDesc(HashMap tree, String node, HashMap visited)
	{
		HashSet children = (HashSet) tree.get(node);
		Iterator it = children.iterator();
		int num = 0;
		while (it.hasNext())
		{
			String child = (String) it.next();
			if (visited.containsKey(child))
			{
				return -1;
			}
			visited.put(child, "");
			int d = numDesc(tree, child, visited);
			if (d < 0)
			{
				return -1;
			}
			num += 1 + d;
		}
		return num;
	}
	public String[] countDescendants(String[] parentData)
	{
		HashMap parent = new HashMap();
		HashMap children = new HashMap();
		HashSet nodes = new HashSet();
		
		nodes.add("ROOT");
		parent.put("ROOT", "");
		String all = "";
		for (int i = 0; i < parentData.length; i++)
		{
			all = all + parentData[i];
		}
		all = all.trim();
		if (all.equals(""))
			return new String[] {"ROOT: 0"};
		String[] w = all.split(" ");
		for (int j = 0; j < w.length; j++)
		{
			String[] w2 = w[j].split(",");
			parent.put(w2[0], w2[1]);
			nodes.add(w2[0]);
			if (w2[0].equals("ROOT"))
				return new String[] {"ROOT: 0"};
		}
		// initialize all children to empty set {}
		Iterator it = nodes.iterator();
		while (it.hasNext())
		{
			String node = (String) it.next();
			children.put(node, new HashSet());
		}
		// System.out.println(nodes);
		// build children sets
		it = nodes.iterator();
		while (it.hasNext())
		{
			String node = (String) it.next();
			if (node.equals("ROOT"))
				continue;
			String par = (String) parent.get(node);
			HashSet parChildren = (HashSet) children.get(par);
			parChildren.add(node); // add node to parent's set of children
		}
		HashMap v = new HashMap();
		int x = numDesc(children, "ROOT", v);
		if (x < 0 || x != nodes.size()-1)
			return new String[0];
		if (x == 0)
			return new String[] {"ROOT: 0"};
		String[] counts = new String[nodes.size()];
		it = nodes.iterator();
		int p = 0;
		while (it.hasNext())
		{
			String node = (String) it.next();
			HashMap visited = new HashMap();
			int count = numDesc(children, node, visited);
			if (count < 0)
			{
				return new String[0];
			}
			counts[p++] = node + ": " + count;
		}
		Arrays.sort(counts);
		return counts;
	}

	
	public static void main(String[] args)
	{
		long time;
		String[] answer;
		boolean errors = false;
		String[] desiredAnswer;
		
		boolean same;
		time = System.currentTimeMillis();
		answer = new HierarchicalTree().countDescendants(new String[]{"bin,ROOT tty,dev dev,ROOT passwd,etc etc,ROOT lib",",ROOT mnt,ROOT proc,ROOT tmp,ROOT usr,ROOT var,RO","OT libc,lib screens,tmp kernel,usr log,var tty,de","v"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "ROOT: 15",  "bin: 0",  "dev: 1",  "etc: 1",  "kernel: 0",  "lib: 1",  "libc: 0",  "log: 0",  "mnt: 0",  "passwd: 0",  "proc: 0",  "screens: 0",  "tmp: 1",  "tty: 0",  "usr: 1",  "var: 1" };
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
		answer = new HierarchicalTree().countDescendants(new String[]{""});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "ROOT: 0" };
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
		answer = new HierarchicalTree().countDescendants(new String[]{"disconnectb,disconnecta cyclea,ROOT intermediatea",",cyclea cycleb,intermediatea cyclea,cycleb ROOT,r","ootparent"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ };
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
		answer = new HierarchicalTree().countDescendants(new String[]{"sapiens,homo homo,hominidae hominidae,primates pri","mates,mammalia mammalia,chordata chordata,animalia"," animalia,eukarya eukarya,ROOT ","protista,eukarya fungi,eukarya plantae,eukarya ","porifera,animalia cnidaria,animalia platyhelminthe","s,animalia nematoda,animalia mollusca,animalia ann","elida,animalia arthropoda,animalia echinodermata,a","nimalia ","agnatha,chordata chondrichthyes,chordata osteichth","yes,chordata amphibia,chordata reptilia,chordata a","ves,chordata ","artiodactyla,mammalia carnivora,mammalia cetacea,m","ammalia chiroptera,mammalia dermoptera,mammalia hy","racoidea,mammalia insectivora,mammalia lagomorpha,","mammalia macroscelidea,mammalia notoryctemorphia,m","ammalia perissodactyla,mammalia pholidota,mammalia"," proboscidea,mammalia rodentia,mammalia scandentia",",mammalia sirenia,mammalia tubulidentata,mammalia ","xenarthra,mammalia ","lemuridae,primates cheirogaleidae,primates indrida","e,primates daubentoniidae,primates galagonidae,pri","mates loridae,primates megaladapidae,primates tars","iidae,primates cebidae,primates cercopithecidae,pr","imates callitrichidae,primates hylobatidae,primate","s ","gorilla,hominidae pan,hominidae pongo,hominidae ","domain,ROOT kingdom,domain phylum,kingdom class,ph","ylum order,class family,order genus,family species",",genus ninja,mammalia"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "ROOT: 67",  "agnatha: 0",  "amphibia: 0",  "animalia: 54",  "annelida: 0",  "arthropoda: 0",  "artiodactyla: 0",  "aves: 0",  "callitrichidae: 0",  "carnivora: 0",  "cebidae: 0",  "cercopithecidae: 0",  "cetacea: 0",  "cheirogaleidae: 0",  "chiroptera: 0",  "chondrichthyes: 0",  "chordata: 45",  "class: 4",  "cnidaria: 0",  "daubentoniidae: 0",  "dermoptera: 0",  "domain: 7",  "echinodermata: 0",  "eukarya: 58",  "family: 2",  "fungi: 0",  "galagonidae: 0",  "genus: 1",  "gorilla: 0",  "hominidae: 5",  "homo: 1",  "hylobatidae: 0",  "hyracoidea: 0",  "indridae: 0",  "insectivora: 0",  "kingdom: 6",  "lagomorpha: 0",  "lemuridae: 0",  "loridae: 0",  "macroscelidea: 0",  "mammalia: 38",  "megaladapidae: 0",  "mollusca: 0",  "nematoda: 0",  "ninja: 0",  "notoryctemorphia: 0",  "order: 3",  "osteichthyes: 0",  "pan: 0",  "perissodactyla: 0",  "pholidota: 0",  "phylum: 5",  "plantae: 0",  "platyhelminthes: 0",  "pongo: 0",  "porifera: 0",  "primates: 18",  "proboscidea: 0",  "protista: 0",  "reptilia: 0",  "rodentia: 0",  "sapiens: 0",  "scandentia: 0",  "sirenia: 0",  "species: 0",  "tarsiidae: 0",  "tubulidentata: 0",  "xenarthra: 0" };
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
		answer = new HierarchicalTree().countDescendants(new String[]{"duke,ROOT arizona,duke maryland,duke michiganst,a","rizona usc,duke stanford,maryland temple,michigan","st illinois,arizona ucla,duke kentucky,usc cincin","nati,stanford georgetown,maryland gonzaga,michiga","nst pennst,temple kansas,illinois mississippi,ari","zona missouri,duke utahst,ucla bostoncollege,usc ","iowa,kentucky stjosephs,stanford kentstate,cincin","nati georgiast,maryland hampton,georgetown fresno","st,michiganst indianast,gonzaga florida,temple no","rthcarolina,pennst charlotte,illinois syracuse,ka","nsas notredame,mississippi butler,arizona monmout","h,duke georgia,missouri ohiost,utahst hofstra,ucl","a oklahomast,usc southernutah,bostoncollege creig","hton,iowa holycross,kentucky ncgreensboro,stanfor","d georgiatech,stjosephs byu,cincinnati indiana,ke","ntstate wisconsin,georgiast georgemason,maryland ","arkansas,georgetown iowast,hampton alabamast,mich","iganst california,fresnost virginia,gonzaga oklah","oma,indianast texas,temple westernky,florida prov","idence,pennst princeton,northcarolina northwester","nst,illinois tennessee,charlotte hawaii,syracuse ","csnorthridge,kansas xavier,notredame iona,mississ","ippi wakeforest,butler easternill,arizona winthro","p,northwesternst"});
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = new String[]{ "ROOT: 65",  "alabamast: 0",  "arizona: 32",  "arkansas: 0",  "bostoncollege: 1",  "butler: 1",  "byu: 0",  "california: 0",  "charlotte: 1",  "cincinnati: 3",  "creighton: 0",  "csnorthridge: 0",  "duke: 64",  "easternill: 0",  "florida: 1",  "fresnost: 1",  "georgemason: 0",  "georgetown: 3",  "georgia: 0",  "georgiast: 1",  "georgiatech: 0",  "gonzaga: 3",  "hampton: 1",  "hawaii: 0",  "hofstra: 0",  "holycross: 0",  "illinois: 8",  "indiana: 0",  "indianast: 1",  "iona: 0",  "iowa: 1",  "iowast: 0",  "kansas: 3",  "kentstate: 1",  "kentucky: 3",  "maryland: 15",  "michiganst: 15",  "mississippi: 3",  "missouri: 1",  "monmouth: 0",  "ncgreensboro: 0",  "northcarolina: 1",  "northwesternst: 1",  "notredame: 1",  "ohiost: 0",  "oklahoma: 0",  "oklahomast: 0",  "pennst: 3",  "princeton: 0",  "providence: 0",  "southernutah: 0",  "stanford: 7",  "stjosephs: 1",  "syracuse: 1",  "temple: 7",  "tennessee: 0",  "texas: 0",  "ucla: 3",  "usc: 7",  "utahst: 1",  "virginia: 0",  "wakeforest: 0",  "westernky: 0",  "winthrop: 0",  "wisconsin: 0",  "xavier: 0" };
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

