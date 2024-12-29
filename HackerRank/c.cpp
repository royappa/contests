#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef pair<int,pair<int,int>> piii;
typedef pair<int,int> pii;

bool overlap(piii a, piii b)
{
	set<pii> coords;
    int w = a.first, r = a.second.first, c = a.second.second;
	for (int i = 0; i < w; i++)
	{
		coords.insert(make_pair(r-i, c));
        coords.insert(make_pair(r+i, c));
        coords.insert(make_pair(r, c-i));
        coords.insert(make_pair(r, c+i));
	}
	w = b.first;
    r = b.second.first;
    c = b.second.second;
    for (int i = 0; i < w; i++)
	{
		if (coords.count(make_pair(r-i, c)) > 0) return true;
        if (coords.count(make_pair(r+i, c)) > 0) return true;
        if (coords.count(make_pair(r, c-i)) > 0) return true;
        if (coords.count(make_pair(r, c+i)) > 0) return true;
	}
	return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
		cin >> v[i];
	}
	vector<piii> s;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v[i][j] == 'B') continue;
			int w = 0;
			while (i+w < n && i-w >= 0 && j-w >= 0 && j+w < m && v[i-w][j] == 'G' && v[i+w][j] == 'G' && v[i][j-w] == 'G' && v[i][j+w] == 'G')
			{
				w++;
				s.push_back(make_pair(w, make_pair(i, j)));
			}
		}
	}
	int mx = 0;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = i+1; j < s.size(); j++)
		{
			if (!overlap(s[i], s[j]))
			{
				mx = max(mx, (4*s[i].first-3)*(4*s[j].first-3));
			}
		}
	}
	cout << mx << endl;
    return 0;
}
