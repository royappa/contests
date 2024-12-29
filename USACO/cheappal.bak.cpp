/*
ID: royappa1
LANG: C++
PROG: cheappal
*/

/*
** Acknowledgement: Used C++ STL documentation from the web at http://www.sgi.com/tech/stl/. The rules mentioned "Java API documentation from the web" is ** allowed, as is system help files. I don't keep C++ STL help files on my system so I used the web.
** I understand that this may result in disqualification if my interpretation of the rules was wrong.
*/
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
#include <ext/hash_map>

using namespace std;

using namespace __gnu_cxx;

namespace __gnu_cxx
{
	template<> class hash<std::string>
	{
		public:
	    size_t operator()(const int& i) const		// If Hash domain is a STRING, use this
	    {
	    	return hash<int>()(i);
	    }
	};
}


typedef long long LL;

hash_map<int,LL> memo;

int ic[26], dc[26];
string s;

LL f(int p, int q)
{
	if (p >= q)
	{
		return 0;
	}
	int key = p*10000+q;
	if (memo.count(key) > 0)
	{
		return memo[key];
	}

	LL r = 0;


	if (s[p] == s[q])
	{
		r = f(p+1, q-1);
	}
	else
	{
		r = dc[s[p]-'a']+dc[s[q]-'a']+f(p+1, q-1);
		r <?= ic[s[q]-'a']+f(p, q-1);
		r <?= ic[s[p]-'a']+f(p+1, q);
		r <?= dc[s[q]-'a']+f(p, q-1);
		r <?= dc[s[p]-'a']+f(p+1, q);
	}

	return memo[key] = r;
}

main ()
{
    ifstream fin("cheappal.in");
    ofstream fout("cheappal.out");

    int n, m;
    fin >> n >> m;

	fin >> s;
	memset(ic, 0, sizeof(ic));
	memset(dc, 0, sizeof(dc));

	for (int i = 0; i < n; i++)
	{
		string let;
		int ins, del;
		fin >> let >> ins >> del;
		ic[let[0]-'a'] = ins;
		dc[let[0]-'a'] = del;
	}

	/*
	fout << n << " " << m << endl;
	fout << s << endl;
	for (int i = 0; i < n; i++)
	{
		fout << char('a'+i) << " " << ic[i] << " " << dc[i] << endl;
	}
	*/

	memset(memo, -1, sizeof(memo));

	fout << f(0, int(s.size())-1) << endl;

	fout.close();

    exit (0);
}
