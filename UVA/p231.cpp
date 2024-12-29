// @JUDGE_ID:  55118HH  231  C++  "Maximum Decreasing Subsequence" 

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

// CORRECT

void findBest(vector<int> v, int setNum)
{
	int n = v.size();
	
	vector<int> len(n, 1);
	
	for (int k = 0; k <= n-1; k++)
	{
		for (int i = 0; i < k; i++)
		{
			if (v[i] >= v[k])
			{
				len[k] = max(len[k], len[i]+1);
			}
		}
	}
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		m = max(m, len[i]);
	}
	printf("Test #%d:\n", setNum);
	printf("  maximum possible interceptions: %d\n\n", m);
}
main()
{
	int num, setNum = 1;
	vector<int> v;
	
	cin >> num;
	while (num != -1)
	{
		v.clear();
		do
		{
			v.push_back(num);
			cin >> num;
		} while (num != -1);
		findBest(v, setNum);
		setNum++;
		cin >> num;
	}
	
	exit(0);
}
