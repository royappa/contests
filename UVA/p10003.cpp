// @JUDGE_ID:  55118HH  10003  C++  "Cutting Sticks"

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
map<string,int> cache;
// CORRECT

int findBest(int A[], int B, int E, int i, int j)
{
	if (j < i)
	{
		return 0;
	}
	char buf[100];
	sprintf(buf, "%d:%d:%d:%d", B, E, i, j);
	string key = buf;
	cout << key;
	int value = cache[key];
	/*
	if (value != 0)
	{
		cout << "*" << endl;
		return value;
	}
	*/
	cout << endl;
		
	int best = 1<<30;
	for (int k = i; k <= j; k++)
	{
		best = min(best, findBest(A, B, A[k], i, k-1)+findBest(A, A[k], E, k+1, j));
	}
	value = best+(E-B);
	cache[key] = value;
	return value;
		
}
main()
{

	int len;
	cin >> len;
	
	int A[100];
	
	while (len != 0)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> A[i+1];
		}
		int m = findBest(A, 0, len, 1, n);
		printf("The minimum cutting is %d\n", m);
		cin >> len;
	}
	
	exit(0);
}
