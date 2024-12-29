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
#include <string>
#include <cstring>

using namespace std;

typedef long long LL;
int M, N;

void outvec(vi v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void go(vector<LL> v)
{
	int len = v.size();
	LL imagesUsed = 0;
	for (auto x : v)
	{
		imagesUsed |= x;
	}
	int numImages = __builtin_popcountll(imagesUsed);
	int numLeft = M-numImages;
	LL imagesLeft = ~imagesUsed;


int main()
{


	cin >> M >> N;
	vector<int> v;
	go(v, N);

}

