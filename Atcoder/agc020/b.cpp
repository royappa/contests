#include <bits/stdc++.h>


using namespace std;

typedef long long LL;
int A[100000+1];

int main()
{
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		scanf("%d", &A[K-i-1]);
	}
	// The game ends after Ak
	// the last order is "Form groups of Ak"
	// Suppose there were R remaining before the last round then
	// R-R%Ak = 2
	// R=2  2-2%2 = 2
	// R=3  3-3%2 = 2
	// Those are the only choices (2,3)
	// R-R%A = 3
	// R=3  3-3%3 = 3
	// R=4  4-4%3 = 3
	// R=5  5-5%3 = 3
	// R=6  6-6%3 = 6xx
	// R=7 7-7%3 = 6xx
	// R=8  8-8%3  = 6xx
	// R=9 ....
	LL lo = 2, hi = 2;
	// After the last step, there are 2 people.
	// How many could there be before that step?
	// Keep doing that until we do this for the first step.
	// In general, given range of numbers we have now, find range of numbers we could have had before this step
	for (int i = 0; i < K; i++) {
		LL x = A[i];
		// if you form groups of x with C remaining then you must have started with
		// y = C, C+1, C+2.., C+x-1
		// C ranges in the range L,L+1...,L+m
		// range1 = C...C+x-1
		// range2 = (C+1),...,(C+1)+(x-1)

	}


	exit(0);
}
