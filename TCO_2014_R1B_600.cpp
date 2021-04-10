vector<string> v;
int n, m;

// return the minimum column-fences needed given that "mask" describes the row-fences in place
// we start building a fence after column k, and go as far as we can to the right, keeping the animals segregated

int mask;

int cume[16][16][2];

int f(int k)
{

	int lastc = k-1; // the rightmost column blocked off by the current fence, which is proposed to be after k

	bool seg = true;
	int c = k;
	while (1)
	{
		// check if animals in columns last+1 through j are segregated
		int lastr = 0;
		for (int r = 0; r < n; r++)
		{
			if ((mask & (1<<r)) == 0) continue;
			// cell is (lastr,lastc+1) through (r,k)
			int wc = 0, sc = 0;
			for (int i = lastr; i <= r; i++)
			{
				for (int j = lastc+1; j <= k; j++)
				{
					wc += v[i][j] == 'W';
					sc += v[i][j] == 'S';
				}
			}
			if (wc != sc)
			{
				seg = false;
				goto end;
			}
		}
		c++;
	}
	end:
	if (seg == false)
		return -1;

	if (c == m-1)
		return 0;
	else
		return 1+f(c);
}

int getmin(vector <string> v_)
{
	v = v_;
	n = v.size();
	m = v[0].size();

	memset(cume, 0, sizeof(cume));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cum[i][j][0] = cume[i][j][1] = 0;
			for (int ii = 0; ii <= i; ii++)
			{
				for (int jj = 0; jj <= j; jj++)
				{
					cume[i][j][0] += v[ii][jj] == 'W';
					cume[i][j][1] += v[ii][jj] == 'S';
				}
			}
		}
	}

	int best = 1<<30;
	for (mask = 0; mask < (1<<(n-1)); mask++)
	{
		int rowNeed = __builtin_popcount(mask);
		mast |= (1<<(n-1);
		// the mask i contains fences that separate rows
		// now find out the fewest column-fences that will separate the animals
		int colNeed = f(0);
		if (colNeed < 0)
			continue;
		best = min(best, rowNeed+colNeed);
	}
	return best;

}

00
x
x
x

01
x
-
x
x

10
x
x
-
x

11
x
-
x
-
x




Problem Statement

Farmer John has a huge rectangular pasture for his sheep. The pasture is divided into a grid of unit square cells. The sheep can travel freely between the cells. There is a wall around the pasture, so the sheep cannot leave it.  One day, Farmer John found that wolves have infested the pasture through holes in the wall. Farmer John has fixed those holes, but the damage has been done: there are now some wolves in the pasture. More precisely, some cells of the pasture contain sheep, some contain wolves and some are empty. There are no cells that contain both sheep and wolves, and Farmer John would like to keep it that way. To make sure that the wolves cannot reach his sheep, Farmer John is going to build some fences.  Each new fence has to be placed either between two rows or between two columns of cells. Each fence will start at one end of the pasture and reach all the way to the other end. Neither sheep nor wolves can cross the fences. The new fences must be placed in such a way that none of the wolves will be able to reach a sheep.  You are given a vector <string> field. For each i and j, character j of element i of field represents the cell in row i, column j of the grid. (All indices in the previous sentence are 0-based.) Each character in field will be one of 'S' (a cell with sheep), 'W' (a cell with wolves), and '.' (an empty cell).  Return the smallest number of new fences needed to separate the wolves from the sheep.
Definition

Class:
WolvesAndSheep
Method:
getmin
Parameters:
vector <string>
Returns:
int
Method signature:
int getmin(vector <string> field)
(be sure your method is public)
Limits

Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
field will contain between 1 and 16 elements, inclusive.
-
Each element of field will contain between 1 and 16 characters, inclusive.
-
Each element of field will contain the same number of characters.
-
Each character of each element of field will be 'S', 'W' or '.'.
Examples
0)


{"W.WSS",
 "WW.S.",
 ".SSS.",
 "SSS.S",
 ".SS.S"}
Returns: 2
The optimal solution is to build two fences: one between rows 1 and 2, the other between columns 2 and 3. (All those indices are 0-based.) This will divide the pasture into four smaller rectangles. One of those rectangles (the 2 by 3 rectangle in the top left corner) will contain only wolves, the other three will contain only sheep.
1)


{".....",
 ".....",
 "....."}
Returns: 0
There are no animals, thus we need no fences.
2)


{".SS",
 "...",
 "S..",
 "W.W"}
Returns: 1

3)


{"WWWSWWSSWWW",
 "WWSWW.SSWWW",
 "WS.WSWWWWS."}
Returns: 10

4)


{".W.S.W.W",
 "W.W.S.W.",
 ".S.S.W.W",
 "S.S.S.W.",
 ".S.W.W.S",
 "S.S.W.W.",
 ".W.W.W.S",
 "W.W.S.S."}
Returns: 7

5)


{"W.SSWWSSSW.SS",
 ".SSSSW.SSWWWW",
 ".WWWWS.WSSWWS",
 "SS.WSS..W.WWS",
 "WSSS.SSWS.W.S",
 "WSS.WS...WWWS",
 "S.WW.S.SWWWSW",
 "WSSSS.SSW...S",
 "S.WWSW.WWSWSW",
 ".WSSS.WWSWWWS",
 "..SSSS.WWWSSS",
 "SSWSWWS.W.SSW",
 "S.WSWS..WSSS.",
 "WS....W..WSS."}
Returns: 24

6)


{"WW..SS",
 "WW..SS",
 "......",
 "......",
 "SS..WW",
 "SS..WW"}
Returns: 2

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.