
typedef pair<int,int> pi;

pii move1(int N, int M, int p)
{
	int n = N/p;
	int m = M%n;
	return make_pair(n, m);
}

pii move2(int N, int M)
{
	return M == 1 ? make_pair(N,N) : make_pair(N,M-1);
}
pii move3(int N, int M)
{
	return M == N ? make_pair(N,1) : make_pair(N,M+1);
}

int getLeast(int N, int M)
{
	deque<pii> q;

	pii h = make_pair(N,M);
	q.push_back(h);
	map<pii,int> dist;


	dist[h] = 0;

	while (q.size() > 0)
	{
		h = q.front();
		q.pop_front();
		N = h.first;
		M = h.second;
		if (M == 1)
			return dist[h];

		for (int d = 2; d*d <= N; d++)
		{
			if (isPrime(d))
			{

			pii x = move1(N, M, p);
			if (dist.count(x) == 0)
			{
				dist[x] = dist[h]+1;
				q.push_back(x);
			}
		}
		pii y = move2(h);
		if (dist.count(y) == 0)
		{
			dist[y] = dist[h]+1;
			q.push_back(y);
		}
		y = move3(h);
		if (dist.count(y) == 0)
		{
			dist[y] = dist[h]+1;
			q.push_back(y);
		}
	}
	return -1;
}

Problem Statement

Manao is playing a game called "Divide and Shift". There is a sequence of N slots in the game numbered from 1 to N. Initially each of them contains an object.

Manao's goal is to obtain the object which is initially in slot M.

At any time of the game, he can only obtain an object that is in slot 1 at that time.  Manao can perform two types of moves.

The first is choosing a prime number p which divides N and dividing the sequence of the slots in p contiguous subsequences, namely the slots from 1 to N/p, the slots from N/p+1 to 2N/p, etc.

Then, Manao keeps the subsequence which contains the desired object and gets rid of the remaining slots.

The length of the chosen subsequence is then assigned to N and the slots in it are renumbered from 1 to the new value of N.

The second type of move is shifting the objects in the slots. Manao can perform a left shift and a right shift. After a left shift, for each i > 1 the object in slot i is moved to slot i-1 and the object in slot 1 is moved to the last slot of the sequence. After a right shift, each object is moved to the slot to the right and the object in the last slot is moved to slot 1.

Determine the least number of moves in which Manao can reach the goal. Taking the object from slot 1 is not considered a move.

Definition

Class:
DivideAndShift
Method:
getLeast
Parameters:
int, int
Returns:
int
Method signature:
int getLeast(int N, int M)
(be sure your method is public)


Notes
-
A positive integer number is called prime if it has exactly two divisors - 1 and itself. For example, 2, 3, 5 and 7 are prime numbers, and 4, 6, 8 and 9 are not prime. By convention, 1 is not considered to be a prime number.
-
A prime number p divides N if the ratio N/p is an integer.
Constraints
-
N will be between 1 and 1,000,000, inclusive.
-
M will be between 1 and N, inclusive.
Examples
0)


56
14
Returns: 3
One possible way to obtain the object in slot 14 is to perform the following operations: 1. Divide by 2. N becomes equal to 28 now. 2. Shift right. The object moves to slot 15. 3. Divide by 2 again. The sequence 15..28 is kept, renumbered as 1..14 and the object appears in slot 1.
1)


49
5
Returns: 2
Manao divides by 7 twice and gets a single slot.
2)


256
7
Returns: 6
Shift left until the object is in slot 1.
3)


6
1
Returns: 0
The object may be in slot 1 right in the beginning.
4)


77777
11111
Returns: 2

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.