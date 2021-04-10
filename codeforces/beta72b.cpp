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
typedef long long LL;
int main()
{
	int n;
	LL k;
	vector<int> v;
	vector<int> a;

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
		a.push_back(i);
	}


	while (true)
	{
		// find the fewest number of visits any animal needs, say that is t
		// then after t rounds of the whole queue, that animal (and any other who needs t turns) can be removed
		// this will be a total of t*len visits, if the queue length is len
		LL len = v.size();
		LL t = *min_element(v.begin(), v.end());
		// now find the first instance of t
		int p = find(v.begin(), v.end(), t)-v.begin();


		// case 1: the doctor has enough work slots left, to remove one animal
		if (k >= p+(t-1)*len+1)
		{
if (debug) cout << "uu" << " " << a[p]+1 << "/" << v[p] << " k = " << k << endl;
			for (int i = 0; i < p; i++)
			{
				v[i]--;
			}
			rotate(v.begin(), v.begin()+p, v.end());
			rotate(a.begin(), a.begin()+p, a.end());
			vector<int> w;
			vector<int> b;
			for (int i = 1; i < len; i++)
			{
				w.push_back(v[i]-(t-1));
				b.push_back(a[i]);
			}
			k -= p+(t-1)*len+1;
			v = w;
			a = b;
if (debug) cout << "vv" << " k = " << k << endl;
			if (v.size() == 0) // all animals are finished
			{
				if (k > 0) // doctor wanted to work more
				{
					cout << -1 << endl;
				}
				else // doctor is also done
				{
					cout << endl;
				}
				break;
			}
		}
		else /// not enough turns to remove any animal
		{
if (debug) cout << "aa" << endl;
			int d = k / len, r = k % len;
			vector<int> w(len);
			vector<int> b(len);
			for (int i = 0; i < len; i++)
			{
				w[i] = v[(i+r)%len];
				b[i] = a[(i+r)%len];
			}
			a = b;
			for (int i = 0; i < len; i++)
			{
				cout << a[i]+1 << (i != len-1 ? " " : "");
			}
			cout << endl;
if (debug) cout << "bb" << endl;
			break;
		}
	}
	exit(0);
}

