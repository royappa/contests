int count(string s)
{
	int n = s.size();
	int w = 0, b = 0;
	int last = -1, first = -1;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'W')
		{
			last = i;
			w++;
		}
		else if (first == -1)
		{
			first = i;
		}
	}
	b = n-w;
	if (w == n || b == n)
		return 0;
	int num = 0;
cout << first << " " << last << endl;
	while (first < last)
	{
		first++;
		last--;
		num++;
		bool flag = false;
		bool x = false, y = false;
		for (int i = first; i <= last; i++)
		{
			if (s[i] == 'W')
			{
				last = i;
				x = true;
			}
			else if (!flag)
			{
				y = true;
				flag = true;
				first = i;
			}
		}
		if (!x || !y)
			break;
	}
	return num;

}

Problem Statement

Powerful sorceress Camomile has N magical creatures sitting in cages in a row.

Each creature is either black or white. Cages are conveniently numbered from 1 to N.

Camomile's dark twin sister Romashka has shuffled these creatures.

Their order after they have been shuffled is given in the string creatures, where the i-th (1-based) character is 'B' if the creature in cage i is black and 'W' if it is white.

Now Camomile wants to put the creatures back in order.

The creatures are considered to be in order if the white creatures all sit in cages with numbers from 1 to W, where W is the total number of white creatures, and the black creatures all sit in cages with numbers from W+1 to N.

To achieve the necessary order, Camomile can use N different spells, also numbered from 1 to N.

The spell with number i can swap creatures from two cages if the distance between those cages is exactly equal to i.

The distance between cages with numbers a and b is calculated as |a - b|.

She can use each spell at most once and each spell can swap only one pair of creatures.

Return the minimum number of spells that she needs to use in order to put creatures back in order.

If it is impossible, return -1.



Definition

Class:
BlackWhiteMagic
Method:
count
Parameters:
string
Returns:
int
Method signature:
int count(string creatures)
(be sure your method is public)


Constraints
-
creatures will contain between 1 and 50 characters, inclusive.
-
Each character in creatures will be either 'B' or 'W'.
Examples
0)


"WBBW"
Returns: 1
By using the second spell and swapping the creatures in the second and last cages we will obtain the required order: "WWBB".
1)


"WWWWBBBB"
Returns: 0
Here all creatures are already in the required order, so no spells are needed.
2)


"BBWW"
Returns: 2
One possible way is to start with swapping the first and third creatures: BBWW -> [spell 2 on creatures 1 and 3] -> WBBW WBBW -> [spell 1 on creatures 1 and 2] -> BWBW BWBW -> [spell 3 on creatures 1 and 4] -> WWBB  However, a better solution can be obtained if you start with swapping the second and third creatures: BBWW -> [spell 1 on creatures 2 and 3] -> BWBW BWBW -> [spell 3 on creatures 1 and 4] -> WWBB
3)


"BWWWWWWWBBBBBBBW"
Returns: 1

4)


"WBWBWBWBWWBWBWBWBBBWBW"
Returns: 5

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.