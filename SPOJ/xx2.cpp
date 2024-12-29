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

class Foo {
public:
string rtrim(string s, string f)
{
	for (int i = 0; i < f.size(); i++)
	{
		string pref = f.substr(0, i+1);
		string x = s.substr(s.size()-pref.size());
		if (pref == x)
			return pref;
	}
	return "";
}


};

int main()
{
	Foo dummy;

	cout << dummy.rtrim("", "b");
	return 0;

	for (int i = 0; i < 10; i++)
	{
		string s;
		for (int k = 0; k < i; k++)
		{
			s += "a";
		}
		for (int j = 0; j < 10; j++)
		{
			string t;
			for (int k = 0; k < j; k++)
			{
				t += "b";
			}
			cout << dummy.rtrim(s, t);
		}
	}
	return 0;
}
