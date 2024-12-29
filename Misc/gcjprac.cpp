
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

class HouseParty {
public:

int maxArea(int R, int W, int D)
{
	for (int w1 = 0; w1 <= R+W+D; w1++)
	{
		for (int w2 = 0; w2 <= R+W+D; w2++)
		{
			for (int w3 = 0; w3 <= R+W+D; w3++)
			{
				for (int w4 = 0; w4 <= R+W+D; w4++)
				{
					best = max
}

};

Problem Statement

We are building a rectangular house using manufactured sections for the walls. Each section is 4 feet long. There are three types of sections: window sections, door sections, and regular sections. We have a fixed assortment of these sections, and want to design the house to have a maximum area, subject to the following rules:
1) A house side must contain no more than one door.
2) The house must have at least one door.
3) A door section may not be at the end of a wall.
4) Each window section must be adjacent to two regular sections, one on each side of it in its wall.
Create a class HouseParty that contains a method maxArea that is given numReg, numWin, and numDoor (the available quantity of each type of section) and that returns the maximum area of a house built from those sections. You are not required to use all the sections. If no house can be built your method should return 0.
Definition

Class:
HouseParty
Method:
maxArea
Parameters:
int, int, int
Returns:
int
Method signature:
int maxArea(int numReg, int numWin, int numDoor)
(be sure your method is public)


Constraints
-
numReg, numWin, and numDoor will each be between 0 and 50 inclusive.
Examples
0)


8
0
0
Returns: 0
No house can be built since you have no door sections.
1)


8
0
1
Returns: 48
One way is to use 3 regular sections for the north wall, one regular section for the east wall and one for the west wall, and to use a door section between 2 regular sections for the south wall. This gives a house that is 12' x 4'. Below is a picture (with door and window sections shown as D and W, and regular sections shown as - or | )

    ---
   |   |
    -D-
2)


9
8
2
Returns: 144
One design is:
    -D-
   |   |
   D   W
   |   |
    -W-
3)


6
23
13
Returns: 48
We are very short of regular sections; one design is:
    -
   | |
   D W
   | |
    -
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.