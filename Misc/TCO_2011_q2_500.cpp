typedef vector<int> vi;

bool ok(string &s, int K, int C, int pos, int t)
{
	int n = s.size();
	if (pos < 0 || pos >= n) return false;
	if (s[pos] == 'K') return t%K != 0;
	else if (s[pos] == 'C') return t%C == 0;
	else return true;
}

int crossTheField(string field, int K, int C)
{
	queue<vi> q;
	map<vi,int> dist;
	vi x(3);
	x[0] = x[1] = x[2] = 0;
	q.push(x);
	dist[x] = 0;
	int n = field.size();
	while (q.size() > 0)
	{
		vi head = q.front();
		q.pop();
		if (head[0] == n-1)
		{
			return dist[head];
		}
		// possible cells from here
		int p = head[0], tk = head[1], tc = head[2];
		for (int pos = p-1; pos <= p+1; pos++)
		{
			if (ok(field, pos, (t+1)%K, (t+1)%C))
			{
				vi next(3);
				next[0] = pos;
				next[1] = (t+1)%K;
				next[2] = (t+1)%C;
				if (dist.count(next) == 0)
				{
					q.push(next);
					dish[next] = dish[head]+1;
				}
			}
		}
	}
	return -1;
}

Problem Statement

You are placed at one end of a field represented by a row of cells. Each cell of the field can be one of the following:
empty: is always passable (represented by a '.');
contains a kind creature (represented by a 'K'): is passable, unless the creature is in a bad mood. This happens if the number of the second at which you enter it is divisible by K;
contains a cruel creature (represented by a 'C'): is impassable, unless the creature in in a good mood. This happens if the number of the second at which you enter it is divisible by C.

You start at the leftmost cell of the field. You have to get to the rightmost cell of the field using a minimal number of seconds. Both leftmost and rightmost cells are empty.

In one second you can move to a cell which is immediately to the left or to the right of the current cell, or stay where you are.

You can not stay in a cell containing kind creature if the number of second is divisible by K, or in a cell containing cruel creature if the number of second is not divisible by C.

The seconds are numbered with consecutive integers, starting with 1.

You are given a string field, where each character represents a cell in the field, from left to right. You are also given ints K and C.

Return the minimal number of seconds which will bring you to the rightmost cell of the field. If you can't get there, return -1.

Definition

Class:
KindAndCruel
Method:
crossTheField
Parameters:
string, int, int
Returns:
int
Method signature:
int crossTheField(string field, int K, int C)
(be sure your method is public)


Constraints
-
field will contain between 2 and 50 characters, inclusive.
-
Each character in field will be '.', 'K' or 'C'.
-
The first and the last characters of field will be '.'.
-
K and C will be between 1 and 50, inclusive.
Examples
0)


"..."
2
5
Returns: 2
There are no creatures on the field, so you just go two cells to the right in two seconds.
1)


".K.C."
3
4
Returns: 5
At second 1, you move to the cell with the kind creature. At second 2, you move right to the empty cell. At second 3, you wait in the empty cell, because you can't enter the cell with the cruel creature yet. At second 4, the cruel creature is in a good mood and you can enter its cell. Finally, at second 5 you enter the rightmost cell.
2)


".CCCC."
3
5
Returns: -1
You can not pass.
3)


".CKKKKCKKKKC.KKKKCKKKKC.CKKKKCKKKKCKKKKCKKKKCKKKK."
5
5
Returns: 60

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.