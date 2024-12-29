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

class Alphabet {
public:

int choices(string decree)
{
	int num[ch][i];
}

};

Problem Statement

The government of a small but important country has decided that the alphabet needs to be streamlined and reordered. Uppercase letters will be eliminated. They will issue a royal decree in the form of a String of 'B' and 'A' characters. The first character in the decree specifies whether 'a' must come ('B')Before 'b' in the new alphabet or ('A')After 'b'. The second character determines the relative placement of 'b' and 'c', etc. So, for example, "BAA" means that 'a' must come Before 'b', 'b' must come After 'c', and 'c' must come After 'd'.
Any letters beyond these requirements are to be excluded, so if the decree specifies k comparisons then the new alphabet will contain the first k+1 lowercase letters of the current alphabet.

Create a class Alphabet that contains the method choices that takes the decree as input and returns the number of possible new alphabets that conform to the decree. If more than 1,000,000,000 are possible, return -1.
Definition

Class:
Alphabet
Method:
choices
Parameters:
String
Returns:
int
Method signature:
int choices(String decree)
(be sure your method is public)


Constraints
-
decree contains between 1 and 25 characters inclusive.
-
Each character in decree is the upper case letter 'B' or 'A'.
Examples
0)


"BAA"
Returns: 3
a before b, b after c, and c after d have been decreed, so possibilities are adcb, dacb, dcab
1)


"AAAA"
Returns: 1
edcba is the only alphabet that conforms
2)


"BABABABABABABABABABABABAB"
Returns: -1
More than 1,000,000,000 alphabets conform to this decree
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.