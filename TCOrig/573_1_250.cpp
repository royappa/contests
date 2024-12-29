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


class TeamContest {
public:


int worstRank(vector<int> v)
{
	int n = v.size();
	int rank = 1;
	sort(v.begin(), v.begin()+3);
	int s = v[0]+v[2];
	v.erase(v.begin(), v.begin()+3);
	sort(v.rbegin(), v.rend());
	while (v.size() > 0 && v[0]+v[2] > s)
	{
		int p = int(v.size())-1;
		while (v[0]+v[p] <= s)
			p--;
		rank++;
		v.erase(v.begin()+p);
		v.erase(v.begin()+(p-1));
		v.erase(v.begin());
	}
	return rank;
}

};


double test0() {

	vector<int> a = {53,47,88,79,99,75,28,54,65,14,22,13,11,31,43};
	int res = 3;

	TeamContest *obj = new TeamContest();
	clock_t start = clock();
	int my_answer = obj->worstRank(a);
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
Problem Statement for TeamContest


Problem Statement

Your university is holding a programming competition and your team is going to compete.

There are 3*N students in the university. They are numbered from 0 to 3*N-1. Each student has a certain strength which is a positive integer that characterizes his/her programming skills. You are given a int[] strength. The strength of student i is equal to strength[i].

Your team will consist of students 0, 1 and 2. Other 3*N-3 students will form N-1 more teams so that each team has exactly 3 members. The exact composition of other teams is not known yet. Each team has a strength that is calculated as follows: if it consists of members with strengths X, Y and Z, then the team's strength is equal to max{X, Y, Z} + min{X, Y, Z}.

You are interested how your team will rank by strength among the other teams. Formally, the rank of your team is defined as 1 + (the number of other teams that have a strictly greater strength than the strength of your team).

Return the maximum possible rank that your team may have after all students split into teams.
Definition

Class:     TeamContest
Method:     worstRank
Parameters: int[]
Returns:    int
Method signature: int worstRank(int[] strength)
(be sure your method is public)


Constraints
-              strength will contain between 3 and 48 elements, inclusive.
-              The number of elements in strength will be divisible by 3.
-              Each element of strength will be between 1 and 1,000,000, inclusive.
Examples
0)

{5, 7, 3, 5, 7, 3, 5, 7, 3}
Returns: 2
The strength of your team is max{5, 7, 3} + min{5, 7, 3} = 10. It is possible that one of the other teams will be stronger than your team. For example, if it consists of students with strengths 5, 7 and 7, then its strength will be 12. However, it is not possible that both other teams will be stronger than your team.
1)

{5, 7, 3}
Returns: 1
Just your team. No rivals.
2)

{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
Returns: 1
All teams (including yours) will have the same strength: 2.
3)

{3,9,4,6,2,6,1,6,9,1,4,1,3,8,5}
Returns: 3
4)

{53,47,88,79,99,75,28,54,65,14,22,13,11,31,43}
Returns: 3
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2010, TopCoder, Inc. All rights reserved.




This problem was used for:
       Single Round Match 573 Round 1 - Division I, Level One

*******************/