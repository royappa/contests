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

typedef vector<int> vi;

typedef vector<vi> vvi;
vvi boxes;
map<pair<int,int>,int> memo;

int tallest(int w, int h)
{
	pair<int,int> key = make_pair(w, h);
	if (memo.count(key) > 0)
		return memo[key];
	int& t = memo[key];
	t = 0;
	for (int i = 0; i < boxes.size(); i++)
	{
		int a = boxes[i][0], b = boxes[i][1], c = boxes[i][2];
		if (min(a,b) < w && max(a,b) < h)
			t = max(t, tallest(min(a,b), max(a,b))+c);
		if (min(a,c) < w && max(a,c) < h)
			t = max(t, tallest(min(a,c), max(a,c))+b);
		if (min(b,c) < w && max(b,c) < h)
			t = max(t, tallest(min(b,c), max(b,c))+a);
	}
	return t;
}

int main()
{
	int n;

	scanf("%d", &n);
	while (n != 0)
	{
		boxes.clear();
		memo.clear();
		int edge = 0;
		for (int i = 0; i < n; i++)
		{
			vi box(3);
			scanf("%d%d%d", &box[0], &box[1], &box[2]);
			boxes.push_back(box);
			edge = max(edge, max(box[0], max(box[1], box[2])));
		}
		printf("%d\n", tallest(edge+1, edge+1));
		scanf("%d", &n);
	}
	return 0;
}
