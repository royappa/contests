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
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int d(string s, string t)
{
	string let = "ABCDE";

	int pairs = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = i+1; j < 5; j++)
		{
			char a = let[i], b = let[j];
			int psa = s.find(a), psb = s.find(b);
			int pta = t.find(a), ptb = t.find(b);
			if ((psa-psb)*(pta-ptb) < 0)
			{
				pairs++;
			}
		}
	}
	return pairs;
}

main ()
{

   	string s = "ABCDE";

   	vector<string> v;
   	do
   	{
   		v.push_back(s);
   	} while (next_permutation(s.begin(), s.end()));

   	int n = v.size();
   	printf("string v[] =\n{\n");
   	for (int i = 0; i < n; i++)
   	{
   		printf("\"%s\"%s\n", v[i].c_str(), i < n-1?",":"");
   	}
   	printf("};\n");
   	printf("int dist[120][120] =\n{\n");
   	for (int i = 0; i < n; i++)
   	{
   		printf("{");
   		for (int j = 0; j <= i; j++)
   		{
   			printf("%d%s", d(v[i], v[j]), j < i ? "," : "");
   		}
   		printf("}%s\n", i < n-1?",":"");
   	}
   	printf("};\n");
   	exit(0);
}
