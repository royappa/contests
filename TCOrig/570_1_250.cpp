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

class RobotHerb {
public:

LL llabs(LL x) { return x < 0 ? -x : x; }

void run(int& d, LL& x, LL& y, vector<int> a)
{
	vector<int> dir = {0,-1, 1,0, 0,1, -1,0};

	for (int i = 0; i < a.size(); i++)
	{
		int dx = dir[2*d], dy = dir[2*d+1];

		x += a[i]*dx;
		y += a[i]*dy;
		d = (d+a[i])%4;
	}
	return;
}

long long getdist(int T, vector<int> a)
{
	LL x = 0, y = 0;
	int d = 0;

	if (T/4 > 0)
	{
		for (int i = 0; i < 4; i++)
		{
			run(d, x, y, a);
		}
		x *= T/4;
		y *= T/4;
	}

	for (int i = 0; i < T%4; i++)
	{
		run(d, x, y, a);
	}
	return llabs(x)+llabs(y);
}

};


double test0() {
	/*
	int T = 1;
	vector<int> a = {1,2,3};

	int T = 570;
	vector<int> a = {2013,2,13,314,271,1414,1732};
	LL res = 4112;

	int T = 1000000000;
	vector<int> a = {100};
	LL res = 100000000000;
	*/

	int T = 5;
	vector<int> a = {1,1,2};
	LL res = 10;

	RobotHerb *obj = new RobotHerb();
	clock_t start = clock();
	LL my_answer = obj->getdist(T, a);
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
Problem Statement for RobotHerb
Problem Statement

Robot Herb is playing on an infinite square grid. At any moment, Herb stands on one of the squares and he faces one of the four cardinal directions. In his memory, Herb has a program. The program is a sequence of commands. For each i, the i-th of these commands has the following form:

First move forward a[i] tiles.
Then turn 90 degrees to the right, a[i] times in a row.
Herb has decided to run the program T times. You are given the int T and the int[] a that describes Herb's program.
Let A be the initial position of Herb and B be his position after the program was executed T times.
Return the Manhattan distance between tiles A and B.

Definition

Class:     RobotHerb
Method:              getdist
Parameters:        int, int[]
Returns:               long
Method signature:           long getdist(int T, int[] a)
(be sure your method is public)


Notes
-              Let's introduce a Cartesian coordinate system on the grid so that each cardinal direction is parallel to one of the axes.
The Manhattan distance between two tiles with centers at points (x1, y1) and (x2, y2) is defined as |x1-x2| + |y1-y2|.
Constraints
-              T will be between 1 and 1,000,000,000, inclusive.
-              a will contain between 1 and 50 elements, inclusive.
-              Each element of a will be between 1 and 10,000,000, inclusive.
Examples
0)

1
{1,2,3}
Returns: 2
Suppose that initially Herb stands on the tile with center at (0, 0) and faces the positive y direction. The program will get executed as follows:
                       tile         direction
After 1st command:     (0, 1)       positive x
After 2nd command:     (2, 1)       negative x
After 3rd command:     (-1, 1)      negative y
The manhattan distance between the initial and the final positions is |-1| + |1| = 2.
1)

100
{1}
Returns: 0
2)

5
{1,1,2}
Returns: 10
3)

1000000000
{100}
Returns: 100000000000
The answer doesn't fit into a 32-bit integer data type.
4)

570
{2013,2,13,314,271,1414,1732}
Returns: 4112
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2010, TopCoder, Inc. All rights reserved.




This problem was used for:
       Single Round Match 570 Round 1 - Division I, Level One
***********************/