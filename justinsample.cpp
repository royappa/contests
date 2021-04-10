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

int fact(int k)
{
	return k == 0 ? 1 : k*fact(k-1);
}


void printexp(int N, int k)
{

	int rest = N / fact(k+1);
	if (rest > 0)
	{
		printexp(rest, k+1);
		cout << " + " << (N%fact(k+1)) << "*" << k+1 << "!";
	}
	else
	{
		cout << N << "*" << k << "! ";
	}
}

void expand(int N)
{
	cout << "The Cantor Expansion of " << N << " is ";
	printexp(N, 0);
	cout << endl;
}

int main()
{
	int T;
	cin >> T;
	while (T-- > 0)
	{
		int N;
		cin >> N;
		if (N <= 0)
			cout << "The Cantor Expansion of 0 is 0*1!" << endl;
		else
			expand(N);
	}
}

