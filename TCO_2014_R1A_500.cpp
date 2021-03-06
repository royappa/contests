
Problem Statement

Elly is playing Scrabble with her family. The exact rules of the game are not important for this problem. You only need to know that Elly has a holder that contains a row of N tiles, and that there is a single letter on each of those tiles.
(Tiles are small square pieces of wood. A holder is a tiny wooden shelf with room for precisely N tiles placed in a row.)

While Elly waits for the other players, she entertains herself in the following way. She slightly taps the table, causing the tiles on her holder jump a little and some of them switch places.

Formally, suppose that Elly has N tiles.

There are N positions on the holder, we will label them 0 through N-1 from left to right.

When Elly taps the table, the tiles on her holder will form some permutation of their original order.

You are given an int maxDistance with the following meaning: in the permutation that Elly produces by tapping the table, no tile will be more than maxDistance positions away from its original position (in either direction).

For example, suppose that before a tap the letters in Elly's holder formed the string "TOPCODER" when read from left to right. If maxDistance is 3, one possible string after Elly taps the table is "CODTEPOR". This can happen in the following way:
The letter 'T' at position 0 moves three positions to the right (to position 3).
The letter 'O' at position 1 remains on its initial position (position 1).
The letter 'P' at position 2 moves three positions to the right (to position 5).
The letter 'C' at position 3 moves three positions to the left (to position 0).
The letter 'O' at position 4 moves two positions to the right (to position 6).
The letter 'D' at position 5 moves three positions to the left (to position 2).
The letter 'E' at position 6 moves two positions to the left (to position 4).
The letter 'R' at position 7 remains on its initial position (position 7).

Note that the letter 'D' (at position 5) cannot move to position 1, because this would require it to move more than the maximal distance 3.  It turns out that the string "CODTEPOR" is the lexicographically smallest one Elly can get from "TOPCODER" with a single tap and maxDistance = 3.

Now you want to write a program that, given the string letters and the int maxDistance, returns the lexicographically smallest string the girl can get after a single tap.




string getMin(string s, int m)
{
	int n = s.size();
	for (int dist = 1; dist <= m; dist++)
	{

	}

}


Limits

Time limit (s):
2.000
Memory limit (MB):
256
Notes
-
Given two different strings A and B of equal length, the lexicographically smaller one is the one that contains a smaller character at the first position where they differ.
Constraints
-
letters will contain between 1 and 50 characters, inclusive.
-
letters will contain only uppercase letters from the English alphabet ('A'-'Z').
-
maxDistance will be between 1 and 9, inclusive.
Examples
0)


"TOPCODER"
3
Returns: "CODTEPOR"
The example from the problem statement.
1)


"ESPRIT"
3
Returns: "EIPRST"
In this example the letters 'E', 'P', 'R', and 'T' stay on their initial places, and the letters 'S' and 'I' swap. Since the distance between them is exactly 3 (which also happens to be the maximal distance they can move), this is a valid final configuration.
2)


"BAZINGA"
8
Returns: "AABGINZ"
Note that the maximal distance may be greater than the number of letters Elly has. In such cases, the lexicographically smallest result is, obviously, the sorted sequence of letters.
3)


"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
9
Returns: "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
As the input letters are already sorted, we can assume they'll just fall back to their initial places.
4)


"GOODLUCKANDHAVEFUN"
7
Returns: "CADDGAHEOOFLUKNNUV"

5)


"AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD"
6
Returns: "AAAADDEIBWAEUIODWADSBIAJWODIAWDOPOAWDUOSPWW"

6)


"ABRACADABRA"
2
Returns: "AABARACBDAR"
The letter 'A' at position 0 remains on its initial place (position 0).
The letter 'B' at position 1 moves one position to the right (to position 2).
The letter 'R' at position 2 moves two positions to the right (to position 4).
The letter 'A' at position 3 moves two positions to the left (to position 1).
The letter 'C' at position 4 moves two positions to the right (to position 6).
The letter 'A' at position 5 moves two positions to the left (to position 3).
The letter 'D' at position 6 moves two positions to the right (to position 8).
The letter 'A' at position 7 moves two positions to the left (to position 5).
The letter 'B' at position 8 moves one position to the left (to position 7).
The letter 'R' at position 9 moves one position to the right (to position 10).
The letter 'A' at position 10 moves one position to the left (to position 9).
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.