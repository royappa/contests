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
char buf[16384];
typedef long long LL;
// returns a%m where a may be negative
#define MF(a,m) (((a)%(m)+(m))%(m))

typedef pair<int,int> pi;

void print(int state, int N)
{
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		v.push_back(state%2);
		state /= 2;
	}
	for (int i = 0; i < N; i++)
	cout << v[i];
}

// update state based on one snap
void update(int &state, int N)
{
	// first calculate which snappers are getting power
	int power = 1; // snapper in position p=0 always gets power
	for (int p = 1; p < N; p++)
	{
		// calculate whether snapper in position p is getting power
		// snapper in position (p-1) must be ON and must be getting power
		if ((power&(1<<(p-1))) && (state&(1<<(p-1))))
		{
			power |= 1<<p;
		}
	}
	// snap: toggle all snappers which are getting power
	state ^= power;

// now calculate which snappers are getting power after the toggle
power = 1;
for (int p = 1; p < N; p++)
{
	if ((power&(1<<(p-1))) && (state&(1<<(p-1))))
	{
		power |= 1<<p;
	}
}

if (debug) { print(power, N); cout << " "; print(state, N); cout << ((power==(1<<N)-1 && state==(1<<N)-1) ? "*" : ""); }
	return;
}



int main()
{
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++)
	{
		int N, K;
		cin >> N >> K; // number of snappers and snaps

if (debug) { cout << testCase+1 << " N = " << N << " K = " << K << endl;}
		// simulate the initial snaps
		int i;
		int state = 0; // initially all snappers are off (30 bits ok for int)
		for (i = 0; i < 100; i++)
		{
			update(state, N);
if (debug) { cout << " after " << i+1 << endl;}
		}
		int light = state&(1<<(N-1));
		int N2 = 1<<N;
		cout << "Case #" << testCase+1 << ":" << (K%N2==N2-1 ? "ON" : "OFF") << endl;
	}
	return 0;
}
