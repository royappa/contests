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
int debug = 0;
char buf[4096];

/*
- A flavor MUST be malted if it is the ONLY flavor liked by some customer(s)
- For any customer liking both, we can satisfy them with non-malted version
- And, a customer can like only ONE malted flavor. So it's not like they can prefer TWO malted flavors and we can satisfy them with one of those. They can only like ONE malted flavor, and if it's the only thing they like, then we must malt it.

So, find the flavors which MUST be malted.

Then, for each must-malt flavor, suppose there is a customer who likes that same flavor un-malted.
	- If that customer likes some other unmalted flavor, then all is good.
	- If that customer's ONLY other like is a malted flavor, then we must-malt that also.

If there is some customer who ONLY likes the unmalted version of these must-malted flavors, then this situation is IMPOSSIBLE.

*/

int main()
{
	int C;
	cin >> C;
	for (int testCase = 0; testCase < C; testCase++)
	{
		int N, M;
		cin >> N >> M; // N=#flavors, M=#customers
		vector< vector<int> > flavor;
		vector< vector<int> > typ;
		if (debug && testCase==71) cout << N << " " << M << endl;
		for (int i = 0; i < M; i++)
		{
			int T;
			cin >> T;
			if (debug && testCase==71) cout << T << endl;
			vector<int> f;
			vector<int> t;
			for (int j = 0; j < T; j++)
			{
				int X, Y;
				cin >> X >> Y;
				if (debug && testCase==71) cout << X << " " << Y << endl;
				f.push_back(X-1);
				t.push_back(Y);
			}
			flavor.push_back(f);
			typ.push_back(t);
		}
		set<int> mustMalt;
		for (int i = 0; i < M; i++)
		{
			if (flavor[i].size() > 1) continue;
			if (typ[i][0] == 1)
				mustMalt.insert(flavor[i][0]);
		}
		bool poss = true;
		set<int> oldSet;
		do
		{
			oldSet = mustMalt;
			for (int i = 0; i < M; i++)
			{
				// ALL the customers flavors are unmalted of some must-malt: IMPOSSIBLE
				bool all = true;
				for (int j = 0; j < flavor[i].size(); j++)
				{
					if (typ[i][j] == 0 && mustMalt.count(flavor[i][j]) > 0) continue;
					all = false;
					break;
				}
				if (all)
				{
					poss = false;
					break;
				}
				// it is possible to satisfy customer, but check if it requires a malt
				int malt = -1;
				bool nomalt = false;
				for (int j = 0; j < flavor[i].size(); j++)
				{
					if (mustMalt.count(flavor[i][j]) == 0 && typ[i][j] == 0) // he likes a non-must-malt flavor in unmalted
					{
						nomalt = true;
						break;
					}
					if (mustMalt.count(flavor[i][j]) > 0) // ignore any must-malt flavors he likes, we took care of it already
						continue;

					if (typ[i][j] == 1) // see if he likes a malt flavor
					{
						malt = flavor[i][j];
					}
				}
				if (nomalt)
					continue;
				mustMalt.insert(malt);
			}
		} while (oldSet != mustMalt);
		if (!poss)
		{
			printf("Case #%d: IMPOSSIBLE\n", testCase+1);
		}
		else
		{
			printf("Case #%d:", testCase+1);
			for (int i = 0; i < N; i++)
			{
				printf(" %d", mustMalt.count(i));
			}
			printf("\n");
		}
	}
	return 0;
}
