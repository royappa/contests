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


class TheNumberGame {
public:

int rev(int x)
{
	if (x < 10)
		return x;
	vector<int> v;
	while (x)
	{
		v.push_back(x%10);
		x /= 10;
	}
	int r = 0;
	for (int i = 0; i < v.size(); i++)
	{
		r = r*10+v[i];
	}
	return r;
}


bool f(int A, int B, int who, int turns)
{
	cout << A << " " << B << " " << who << " " << turns << endl;
	if (A == B)
		return who == 0 ? true : false;
	if (turns == 1000)
		return who == 0 ? false : true;
	if (who == 0)
	{
		int A1 = rev(A), A2 = A/10;
		bool x = f(A1, B, 1-who, turns+1);
		if (!x)
			return true;
		return !f(A2, B, 1-who, turns+1);
	}
	else
	{
		int B1 = rev(B), B2 = B/10;
		bool x = f(A, B1, 1-who, turns+1);
		if (!x)
			return true;
		return !f(A, B2, 1-who, turns+1);
	}
}
string determineOutcome(int A, int B)
{
	return f(A, B, 0, 0) ? "Manao wins" : "Manao loses";
}

};


double test0() {

	int A = 99;
	int B = 123;
	string res = "Manao loses";

	TheNumberGame *obj = new TheNumberGame();
	clock_t start = clock();
	string my_answer = obj->determineOutcome(A, B);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;

	cout <<"Desired answer: " <<endl;
	cout <<"\t" << res <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (res != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main(int argc, char **argv) {
	double time;
	bool errors = false;

	time = test0();
	if (time < 0.0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}



/**************************
Problem Statement for TheNumberGame


Problem Statement
               Manao has recently invented a brand new game called The Number Game. He usually plays this game against his friend.



Initially, Manao has an integer A and his friend has an integer B. Note that neither A nor B contain a zero digit in their base 10 representation. The players make moves alternatively with Manao starting first. In each move, the player can either reverse his current number, or he can divide it by 10 (using integer division). For example, if the current number is 12849, the player can either reverse it to obtain 94821, or he can divide it by 10 to obtain 1284. Note that we always round down when using integer division. Also note that each player is only allowed to change his own number, and not the number of the other player.



If after some move the players' numbers become equal, Manao is declared the winner. If after 1000 moves (that is, 500 moves by Manao and 500 by his friend) Manao has not won, he loses. Given A and B, determine whether Manao would win if both players play optimally. Return "Manao wins" or "Manao loses" accordingly.
Definition

Class:     TheNumberGame
Method:              determineOutcome
Parameters:        int, int
Returns:               String
Method signature:           String determineOutcome(int A, int B)
(be sure your method is public)


Constraints
-              A will be between 1 and 999,999,999, inclusive.
-              B will be between 1 and 999,999,999, inclusive.
-              A and B will not contain a zero digit in base 10 representation.
-              A and B will be distinct.
Examples
0)

45
4
Returns: "Manao wins"
Manao can win in one move by dividing his number by 10.
1)

45
5
Returns: "Manao wins"
There are several possible scenarios this game can follow:

Manao divides by 10 and obtains 4. Now his opponent can reverse his number and obtain 5 again. Obviously, no matter what Manao does in his next 499 moves, his opponent can evade him.
Manao reverses his number and obtains 54. His opponent reverses his 5. Manao divides 54 by 10 and obtains 5, thus making the numbers equal
Manao reverses his number and obtains 54. His opponent divides by 10 and obtains zero. Manao will win in three moves, dividing his number by 10 twice.
Obviously, Manao will not choose to divide by 10 in his first move and will win.
2)

99
123
Returns: "Manao loses"
No matter how Manao plays, the opponent can perform reverse moves until the end of the game.
3)

2356236
5666
Returns: "Manao loses"
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2010, TopCoder, Inc. All rights reserved.




This problem was used for:
       Single Round Match 574 Round 1 - Division I, Level One

*******************/