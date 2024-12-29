// @JUDGE_ID:  55118HH  507  C++  "Jill Rides Again"

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


typedef long long LL;
LL globA[21000];

// CORRECT

void findBest(LL A[], int r, int S)
{
	// i, j are stops from 1,2,..,S
	int iBest = 0, jBest = 0, iStart = 1;
	LL best = -(1LL<<60LL);
	LL thisSum = 0LL;
	for (int i = 1; i <= S-1; i++)
	{
		thisSum += A[i];
		if (thisSum > best || (thisSum == best && (i+1-iStart) > (jBest-iBest)))
		{
			best = thisSum;
			iBest = iStart;
			jBest = i+1;
		}
		if (thisSum < 0LL)
		{
			thisSum = 0LL;
			iStart = i+1;
		}
	}
	if (best > 0LL)
	{
		printf("The nicest part of route %d is between stops %d and %d\n", r, iBest, jBest);
	}
	else
	{
		printf("Route %d has no nice parts\n", r);
	}
}
main()
{
	int B;
	cin >> B;
	
	for (int r = 1; r <= B; r++)
	{
		int S;
		cin >> S;
		globA[0] = 0;
		for (int i = 1; i <= S-1; i++)
		{
			cin >> globA[i];
		}
		findBest(globA, r, S);
	}
	
	exit(0);
}
