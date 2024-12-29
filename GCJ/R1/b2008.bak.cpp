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
#include <queue>

using namespace std;
int debug = 1;
char buf[4096];

typedef pair<int,int> pi;

int main()
{
	int N;
	gets(buf);
	sscanf(buf, "%d", &N);
	for (int testCase = 0; testCase < N; testCase++)
	{
		int T;
		gets(buf);
		sscanf(buf, "%d", &T);
		int NA, NB;
		gets(buf);
		sscanf(buf, "%d%d", &NA, &NB);
		vector< vector<pi> > sched(2);
		vector<int> ns(2);
		ns[0] = NA;
		ns[1] = NB;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < ns[i]; j++)
			{
				gets(buf);
				int dh,dm,ah,am;
				sscanf(buf, "%d:%d %d:%d", &dh, &dm, &ah, &am);
				int dt = dh*60+dm, at = ah*60+am;
				sched[i].push_back(make_pair(dt,at));
			}
		}
		vector<int> num(2,0);
		vector<pi> trains;
		for (int t = 0; t <= 23*60+59; t++)
		{
			for (int i = 0; i < 2; i++)
			{
				int n = sched[i].size();
				for (int j = n-1; j >= 0; j--)
				{
					int td = sched[i][j].first, ta = sched[i][j].second;
					cout << "here " << t << " "<< i << " " << td << " " << ta << endl;
					if (td == t)
					{
						bool trainFound = false;
						for (int k = 0; k < trains.size(); k++)
						{
							int tkdir = trains[k].first, tkarr = trains[k].second;
							if (tkdir == 1-i && t >= tkarr+T) // reuse train k
							{
								trainFound = true;
								trains[k].first = i;
								trains[k].second = ta;
								break;
							}
						}
						if (!trainFound)
						{
							num[i]++; // another train starts at station i
							trains.push_back(make_pair(i, ta));
						}
						sched[i].erase(sched[i].begin()+j);
					}
				}
			}
		}
		printf("Case #%d: %d %d\n", testCase+1, num[0], num[1]);
	}
	return 0;
}
