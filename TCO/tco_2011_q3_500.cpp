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

class CoinMachinesGame {
public:
typedef pair<int,int> pii;

int maxGames(int coins, vector <int> need, vector <int> give)
{
	int n = need.size();
	vector<pii> v;
	for (int i = 0; i < n; i++)
	{
		v.push_back(make_pair(need[i]-give[i],need[i]));
	}
	sort(v.begin(), v.end());
	int games = 0;
	while (coins > 0)
	{
		int p = -1;
		for (int i = 0; i < n; i++)
		{
			if (coins >= v[i].second)
			{
				p = i;
				break;
			}
		}
		if (p != -1)
		{
			int t = coins/v[p].second;
			coins -= t*v[p].first;
			games += t;
		}
		else
		{
			break;
		}
	}
	return games;
}
};


//Powered by [KawigiEdit]


Problem Statement

In an arcade palace, there are several machines with games that you like to play.

It costs some number of coins to play a single game on each machine.

However, these machines have a peculiarity: after each game, they give back some of the coins that you inserted.

You wonder how many games in total you can play with the coins you have.

It is possible to play the game on the same machine many times.

You will be given an int coins, the number of coins you start with. You will also be given the description of the machines in two vector <int>s, need and give.

Element i of need is the number of coins you need to put in machine i for the game to start, and element i of give is the number of coins machine i gives back after the game ends.

Return the maximum possible number of games that you can play.

Definition

Class:
CoinMachinesGame
Method:
maxGames
Parameters:
int, vector <int>, vector <int>
Returns:
int
Method signature:
int maxGames(int coins, vector <int> need, vector <int> give)
(be sure your method is public)


Constraints
-
coins will be between 1 and 1000000000 (10^9), inclusive.
-
need will contain between 1 and 50 elements, inclusive.
-
need and give will contain the same number of elements.
-
Each element of need and give will be between 1 and 1000, inclusive.
-
Element i of give will be strictly less than element i of need.
Examples
0)


10
{5,3}
{4,1}
Returns: 7
You can play 5 times on the first machine and 2 times on the second machine, in that order. There are other ways to get 7 games in total.
1)


1000
{16,14,11,7}
{15,12,8,3}
Returns: 988

2)


1000000000
{1000,900,800,700,600,500,400,300,200,100}
{701,802,503,604,405,306,107,208,1,1}
Returns: 10869564

3)


12345678
{342,234,65,76,85,734,67,345,70,234}
{45,78,3,10,45,12,45,57,1,230}
Returns: 3086370

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.