
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef vector<string> vs;
map<string,string> parent;

// Simple split for a space separator. Splits on multiple spaces.
// leading spaces & trailing spacse are also considered separators, thus induce an extra empty-string.
vector<string> split_space(string s)
{
	vector<string> results;
	istringstream fin(s);
	while (!fin.eof())
	{
		string x;
		fin >> x;
		results.push_back(x);
	}
	return results;
}

// Split on separator
// SPLIT_NONRE()
// TESTED - may be slow if used in a loop because it makes a copy of the string "s" each time.
// That is because stupid strtok_r writes null chars into s.
// Actually strtok_r() should not be needed here but doesn't hurt.

vector<string> split_nonre(string s, string sep)
{
	char *sC = (char *) malloc(s.size()+1);
	strcpy(sC, s.c_str());
	char *sepC = (char *) sep.c_str();
	char *status = NULL;

	char *word;
	vector<string> results;
	while ((word = strtok_r(sC, sepC, &status)) != NULL)
	{
		results.push_back(word);
		sC = NULL;
	}
	return results;
}

bool ancestor(string a, string b)
{
	if (b == "ROOT")
		return false;
	if (parent[b] == a)
		return true;
	return ancestor(a, parent[b]);
}

vs countDescendants(vs src)
{
	string all;
	map<string,int> count;

	all = "";
	for (int i = 0; i < src.size(); i++)
	{
		all += src[i];
	}
	vs nodes;
	vs pairs = split_space(all);
	for (int i = 0; i < pairs.size(); i++)
	{
		vs pair = split_nonre(pairs[i], ",");
		if (parent[pair[0]] != "")
			continue;
		parent[pair[0]] = pair[1];
		nodes.push_back(pair[0]);
	}
	q


	nodes.push_back("ROOT");
	for (int i = 0; i < nodes.size(); i++)
	{
		for (int j = 0; j < nodes.size(); j++)
		{
			if (i == j)
				continue;
			if (ancestor(nodes[i], nodes[j]))
				count[nodes[i]]++;
		}
	}

	sort(nodes.begin(), nodes.end());
	vs r;
	for (int i = 0; i < nodes.size(); i++)
	{
		char buf[100];
		sprintf(buf, "%s: %d", nodes[i].c_str(), count[nodes[i]]);
		r.push_back(buf);
	}
	return r;
}

int main()
{
	char *inp[] = {"duke,ROOT arizona,duke maryland,duke michiganst,a",
"rizona usc,duke stanford,maryland temple,michigan",
"st illinois,arizona ucla,duke kentucky,usc cincin",
"nati,stanford georgetown,maryland gonzaga,michiga",
"nst pennst,temple kansas,illinois mississippi,ari",
"zona missouri,duke utahst,ucla bostoncollege,usc ",
"iowa,kentucky stjosephs,stanford kentstate,cincin",
"nati georgiast,maryland hampton,georgetown fresno",
"st,michiganst indianast,gonzaga florida,temple no",
"rthcarolina,pennst charlotte,illinois syracuse,ka",
"nsas notredame,mississippi butler,arizona monmout",
"h,duke georgia,missouri ohiost,utahst hofstra,ucl",
"a oklahomast,usc southernutah,bostoncollege creig",
"hton,iowa holycross,kentucky ncgreensboro,stanfor",
"d georgiatech,stjosephs byu,cincinnati indiana,ke",
"ntstate wisconsin,georgiast georgemason,maryland ",
"arkansas,georgetown iowast,hampton alabamast,mich",
"iganst california,fresnost virginia,gonzaga oklah",
"oma,indianast texas,temple westernky,florida prov",
"idence,pennst princeton,northcarolina northwester",
"nst,illinois tennessee,charlotte hawaii,syracuse ",
"csnorthridge,kansas xavier,notredame iona,mississ",
"ippi wakeforest,butler easternill,arizona winthro",
"p,northwesternst"};

	vs src;
	for (int i = 0; i < sizeof(inp)/sizeof(inp[0]); i++)
	{
		src.push_back(inp[i]);
	}
	vs result = countDescendants(src);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
	return 0;
}

/*
Problem Statement

Many systems of information are naturally organized as hierarchical trees. For example, a computer file system has a hierarchical structure of nested directories, and a textbook could be successively divided into chapters, sections, and subsections. In a hierarchical tree, the root node has no parent, and all other nodes are descendants of the root with exactly one parent each. Therefore, even though a node can have any number of children (zero or more), it is possible to describe the structure of a tree by specifying just the parent of each node.

You have a list of node-parent relationships and you want to analyze the structure of the hierarchical tree. All nodes are named with strings of lowercase alphabetical characters, except for the root node which is named ROOT. Write a class HierarchicalTree with a method countDescendants that takes a String[] parentData containing the nodes and their parents and returns a String[] listing the number of descendants of each node.

If parentData describes a structure that is not a hierarchical tree, return an empty String[].

The elements of parentData should be concatenated, in order, onto an initially empty string. The resulting string will contain pairs of the form NODE,PARENT separated by exactly one space character. NODE represents the name of a node, and PARENT represents the name of NODE's parent. A name will either consist of all lowercase English characters ('a' to 'z') or be ROOT.

The elements of the return value should be formatted "NODE: DESCENDANT_COUNT" (quotes are for clarity) with exactly one space character between the colon and the number of descendants, which should contain no extra leading zeroes.

The elements of the return value should be sorted in lexicographical order by NODE.

Since ROOT is capitalized, it should always precede the other nodes in the returned array.
Definition

Class:
HierarchicalTree
Method:
countDescendants
Parameters:
String[]
Returns:
String[]
Method signature:
String[] countDescendants(String[] parentData)
(be sure your method is public)


Notes
-
The ROOT node always exists.
-
The name of a node uniquely identifies it. There cannot be multiple nodes with the same name, even if they have different parents.
-
A node does not count as its own descendant.
Constraints
-
parentData will contain between 0 and 50 elements, inclusive.
-
Each element of parentData will contain between 0 and 50 characters, inclusive.
-
When the elements of parentData are concatenated, the resulting string will be a list of name pairs with no leading or trailing spaces. Members of a pair will be separated by a single comma, and pairs will be separated by a single space. Names will be lowercase alphabetical English characters ('a' to 'z') or ROOT.
Examples
0)


{"bin,ROOT tty,dev dev,ROOT passwd,etc etc,ROOT lib",
",ROOT mnt,ROOT proc,ROOT tmp,ROOT usr,ROOT var,RO",
"OT libc,lib screens,tmp kernel,usr log,var tty,de",
"v"}
Returns:
{ "ROOT: 15",
  "bin: 0",
  "dev: 1",
  "etc: 1",
  "kernel: 0",
  "lib: 1",
  "libc: 0",
  "log: 0",
  "mnt: 0",
  "passwd: 0",
  "proc: 0",
  "screens: 0",
  "tmp: 1",
  "tty: 0",
  "usr: 1",
  "var: 1" }
A node doesn't have to be specified as a child before it is specified as a parent. Also, redundant specifications may exist (tty,dev appears twice).
1)


{""}
Returns: { "ROOT: 0" }

2)


{"disconnectb,disconnecta cyclea,ROOT intermediatea",
",cyclea cycleb,intermediatea cyclea,cycleb ROOT,r",
"ootparent"}
Returns: { }
There are three things wrong with this tree. First, disconnecta and disconnectb are not descendants of ROOT. Second, cyclea has two parents. Third, rootparent is specified as the parent of ROOT.
3)


{"sapiens,homo homo,hominidae hominidae,primates pri",
"mates,mammalia mammalia,chordata chordata,animalia",
" animalia,eukarya eukarya,ROOT ",
"protista,eukarya fungi,eukarya plantae,eukarya ",
"porifera,animalia cnidaria,animalia platyhelminthe",
"s,animalia nematoda,animalia mollusca,animalia ann",
"elida,animalia arthropoda,animalia echinodermata,a",
"nimalia ",
"agnatha,chordata chondrichthyes,chordata osteichth",
"yes,chordata amphibia,chordata reptilia,chordata a",
"ves,chordata ",
"artiodactyla,mammalia carnivora,mammalia cetacea,m",
"ammalia chiroptera,mammalia dermoptera,mammalia hy",
"racoidea,mammalia insectivora,mammalia lagomorpha,",
"mammalia macroscelidea,mammalia notoryctemorphia,m",
"ammalia perissodactyla,mammalia pholidota,mammalia",
" proboscidea,mammalia rodentia,mammalia scandentia",
",mammalia sirenia,mammalia tubulidentata,mammalia ",
"xenarthra,mammalia ",
"lemuridae,primates cheirogaleidae,primates indrida",
"e,primates daubentoniidae,primates galagonidae,pri",
"mates loridae,primates megaladapidae,primates tars",
"iidae,primates cebidae,primates cercopithecidae,pr",
"imates callitrichidae,primates hylobatidae,primate",
"s ",
"gorilla,hominidae pan,hominidae pongo,hominidae ",
"domain,ROOT kingdom,domain phylum,kingdom class,ph",
"ylum order,class family,order genus,family species",
",genus ninja,mammalia"}
Returns:
{ "ROOT: 67",
  "agnatha: 0",
  "amphibia: 0",
  "animalia: 54",
  "annelida: 0",
  "arthropoda: 0",
  "artiodactyla: 0",
  "aves: 0",
  "callitrichidae: 0",
  "carnivora: 0",
  "cebidae: 0",
  "cercopithecidae: 0",
  "cetacea: 0",
  "cheirogaleidae: 0",
  "chiroptera: 0",
  "chondrichthyes: 0",
  "chordata: 45",
  "class: 4",
  "cnidaria: 0",
  "daubentoniidae: 0",
  "dermoptera: 0",
  "domain: 7",
  "echinodermata: 0",
  "eukarya: 58",
  "family: 2",
  "fungi: 0",
  "galagonidae: 0",
  "genus: 1",
  "gorilla: 0",
  "hominidae: 5",
  "homo: 1",
  "hylobatidae: 0",
  "hyracoidea: 0",
  "indridae: 0",
  "insectivora: 0",
  "kingdom: 6",
  "lagomorpha: 0",
  "lemuridae: 0",
  "loridae: 0",
  "macroscelidea: 0",
  "mammalia: 38",
  "megaladapidae: 0",
  "mollusca: 0",
  "nematoda: 0",
  "ninja: 0",
  "notoryctemorphia: 0",
  "order: 3",
  "osteichthyes: 0",
  "pan: 0",
  "perissodactyla: 0",
  "pholidota: 0",
  "phylum: 5",
  "plantae: 0",
  "platyhelminthes: 0",
  "pongo: 0",
  "porifera: 0",
  "primates: 18",
  "proboscidea: 0",
  "protista: 0",
  "reptilia: 0",
  "rodentia: 0",
  "sapiens: 0",
  "scandentia: 0",
  "sirenia: 0",
  "species: 0",
  "tarsiidae: 0",
  "tubulidentata: 0",
  "xenarthra: 0" }
The phylogeny of living organisms can be represented as a hierarchical tree.
4)


{"duke,ROOT arizona,duke maryland,duke michiganst,a",
"rizona usc,duke stanford,maryland temple,michigan",
"st illinois,arizona ucla,duke kentucky,usc cincin",
"nati,stanford georgetown,maryland gonzaga,michiga",
"nst pennst,temple kansas,illinois mississippi,ari",
"zona missouri,duke utahst,ucla bostoncollege,usc ",
"iowa,kentucky stjosephs,stanford kentstate,cincin",
"nati georgiast,maryland hampton,georgetown fresno",
"st,michiganst indianast,gonzaga florida,temple no",
"rthcarolina,pennst charlotte,illinois syracuse,ka",
"nsas notredame,mississippi butler,arizona monmout",
"h,duke georgia,missouri ohiost,utahst hofstra,ucl",
"a oklahomast,usc southernutah,bostoncollege creig",
"hton,iowa holycross,kentucky ncgreensboro,stanfor",
"d georgiatech,stjosephs byu,cincinnati indiana,ke",
"ntstate wisconsin,georgiast georgemason,maryland ",
"arkansas,georgetown iowast,hampton alabamast,mich",
"iganst california,fresnost virginia,gonzaga oklah",
"oma,indianast texas,temple westernky,florida prov",
"idence,pennst princeton,northcarolina northwester",
"nst,illinois tennessee,charlotte hawaii,syracuse ",
"csnorthridge,kansas xavier,notredame iona,mississ",
"ippi wakeforest,butler easternill,arizona winthro",
"p,northwesternst"}
Returns:
{ "ROOT: 65",
  "alabamast: 0",
  "arizona: 32",
  "arkansas: 0",
  "bostoncollege: 1",
  "butler: 1",
  "byu: 0",
  "california: 0",
  "charlotte: 1",
  "cincinnati: 3",
  "creighton: 0",
  "csnorthridge: 0",
  "duke: 64",
  "easternill: 0",
  "florida: 1",
  "fresnost: 1",
  "georgemason: 0",
  "georgetown: 3",
  "georgia: 0",
  "georgiast: 1",
  "georgiatech: 0",
  "gonzaga: 3",
  "hampton: 1",
  "hawaii: 0",
  "hofstra: 0",
  "holycross: 0",
  "illinois: 8",
  "indiana: 0",
  "indianast: 1",
  "iona: 0",
  "iowa: 1",
  "iowast: 0",
  "kansas: 3",
  "kentstate: 1",
  "kentucky: 3",
  "maryland: 15",
  "michiganst: 15",
  "mississippi: 3",
  "missouri: 1",
  "monmouth: 0",
  "ncgreensboro: 0",
  "northcarolina: 1",
  "northwesternst: 1",
  "notredame: 1",
  "ohiost: 0",
  "oklahoma: 0",
  "oklahomast: 0",
  "pennst: 3",
  "princeton: 0",
  "providence: 0",
  "southernutah: 0",
  "stanford: 7",
  "stjosephs: 1",
  "syracuse: 1",
  "temple: 7",
  "tennessee: 0",
  "texas: 0",
  "ucla: 3",
  "usc: 7",
  "utahst: 1",
  "virginia: 0",
  "wakeforest: 0",
  "westernky: 0",
  "winthrop: 0",
  "wisconsin: 0",
  "xavier: 0" }
The results of single-elimination tournaments can also be expressed as hierarchical trees.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.*/
