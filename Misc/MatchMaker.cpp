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

class MatchMaker {
public:
	vector <string> getBestMatches(vector <string>, string, int);

	vector<string> split_nonre(string s, string sep)
	{
		char *sC = (char *) s.c_str();
		char *sepC = (char *) sep.c_str();
		
		char *word;
		vector<string> results;
		while ((word = strtok(sC, sepC)) != NULL)
		{
			results.push_back(word);
			sC = NULL;
		}
		return results;
	}
		
};

vector <string> MatchMaker::getBestMatches(vector <string> param0, string param1, int param2) 
{
	for (int i = 0; i < param0.size(); i++)
	{
		vector<string> vs = split_nonre(param0[i], " ");
		for (int j = 0; j < vs.size(); j++)
		{
			cout << vs[i] << endl;
		}
		cout << "***" << endl;
	}
	
}


//Powered by [KawigiEdit]

int main() {
int time;
	bool errors = false;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
