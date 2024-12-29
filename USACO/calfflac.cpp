/*
ID: royappa1
LANG: C++
PROG: calfflac
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

using namespace std;

// longest palindrome centered at p
int palLen(string &s, int p)
{
	int len = 1;
	int n = s.size();

	int i = p, j = p;
	while (i > 0 && j < n-1)
	{
		i--;
		j++;
		if (s[i] == s[j])
		{
			len += 2;
		}
		else
		{
			break;
		}
	}
	return len;
}

// longest palindrome which is centered between p,p+1
int palLen2(string &s, int p)
{
	int n = s.size();
	int len = 0;
	int i = p, j = p+1;
	while (i >= 0 && j < n)
	{
		if (s[i] == s[j])
		{
			len += 2;
		}
		else
		{
			break;
		}
		i--;
		j++;
	}
	return len;
}

int main ()
{
	ifstream fin("calfflac.in");
	ofstream fout("calfflac.out");

	int N, S;
	char buf[100];
	char bigbuf[25000];
	strcpy(bigbuf, "");

	while (!fin.eof())
	{
		memset(buf, '\0', sizeof(buf));
		fin.getline(buf, sizeof(buf));
		buf[strlen(buf)] = '\n';
		strcat(bigbuf, buf);
	}
	string s(bigbuf);

	string t = "";
	vector<int> pos;
	for (int i = 0; i < s.size(); i++)
	{
		if (isalpha(s[i]))
		{
			t += tolower(s[i]);
			pos.push_back(i);
		}
	}
//cout << t << endl;
	int n = t.size();
	int maxLen = 0;
	int maxi, maxj;
	for (int i = 0; i < n; i++)
	{
		int len = palLen(t, i);
//cout << i << " " << len << endl;
		if (len > maxLen)
		{
			maxLen = len;
			maxi = pos[i-len/2];
			maxj = pos[i+len/2];
		}
	}
	for (int i = 0; i < n; i++)
	{
		int len = palLen2(t, i);
//cout << i << " " << len << "*"<<endl;
		if (len > maxLen)
		{
			maxLen = len;
			maxi = pos[i-len/2+1];
			maxj = pos[i+len/2];
		}
	}
	if (maxLen == 0)
	{
		fout << 0 << endl;
		fout.close();
		exit(0);
	}

	fout << maxLen << endl << s.substr(maxi, maxj-maxi+1) << endl;

	fout.close();
	exit (0);
}
