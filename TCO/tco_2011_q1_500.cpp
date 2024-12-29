

double x[51][90000];

vector <double> getProbabilities(vector <int> v, int T)
{
	int n = v.size();

	// x[p][T] = probability that song p
	for (int p = 0; p < n; p++)
	{
		x[p][0] = 1.0/n;
	}
	for (int T = 1; T <= 80000; T++)
	{
		int k = 0;
		for (int p = 0; p < n; p++)
		{
			if (T%v[p] == 0)
			{
				x[p][T] = x[p][T-v[p]]*1.0/n;
			}
			else
			{
				x[p][T] = x[p][T-1];
			}
		}
	}
	vector<double> res(n, 0.0);
	for (int p = 0; p < n; p++)
	{
		res[p] = x[p][T];
	}
	return res;
}



Problem Statement

Fox Jiro is going to listen to some music. He has N songs, numbered 0 to N-1, inclusive.

The lengths of the songs are given in the vector <int> length, where the i-th element is the length in seconds of song i.

The music player he uses has a shuffle feature.

Using this feature, he can listen to the songs in random order.

More precisely, first the player chooses one song among all songs with equal probability and plays it.

When the song ends, the player chooses the next song in the same fashion and plays it immediately.

Note that the player may choose the same song more than once in a row.

You are given an int T.

Return a double[] P, where P[i] indicates the probability that the player is playing the i-th song T+0.5 seconds after Jiro starts listening to the music in shuffle mode.

Definition

Class:
FoxListeningToMusic
Method:
getProbabilities
Parameters:
vector <int>, int
Returns:
vector <double>
Method signature:
vector <double> getProbabilities(vector <int> length, int T)
(be sure your method is public)


Notes
-
Each element of the returned array must have an absolute or relative error less than 1e-9.
Constraints
-
length will contain 1 and 50 elements, inclusive.
-
Each element of length will be between 1 and 80,001, inclusive.
-
T will be between 0 and 80,000, inclusive.
Examples
0)


{1, 2}
1
Returns: {0.25, 0.75 }
There are three possible scenarios that lead up to time 1.5:
song 0 -> song 0 (with probability 1/4)
song 0 -> song 1 (with probability 1/4)
song 1 (with probability 1/2)
1)


{1, 10, 100, 1000, 10000}
0
Returns: {0.2, 0.2, 0.2, 0.2, 0.2 }

2)


{5, 8, 4, 7}
10
Returns: {0.1875, 0.3125, 0.1875, 0.3125 }

3)


{10, 1}
9
Returns: {0.9990234375, 9.765625E-4 }

4)


{58, 47, 36, 25, 14, 3}
100
Returns:
{0.32895835374381194, 0.26291497538241776, 0.18463894970453887, 0.1312301113062895,
 0.07518634032025856, 0.017071269542683242 }

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.