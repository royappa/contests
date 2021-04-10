// @JUDGE_ID:  55118HH  10115  C++  "Automatic Editing"

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

int main()
{

	int numRules;

	string line;
	
	vector< pair<string,string> > rules;

	getline(cin, line);
	sscanf(line.c_str(), "%d", &numRules);	
	while (numRules != 0)
	{
		rules.clear();
		for (int i = 0; i < numRules; i++)
		{
			string L, R;
			getline(cin, L); 
			getline(cin, R); 
			rules.push_back(make_pair(L,R));
		}
		getline(cin, line);
		cout << "edit: " << line << endl;
		getline(cin, line);
		sscanf(line.c_str(), "%d", &numRules);
	}
	
	return 0;
}
