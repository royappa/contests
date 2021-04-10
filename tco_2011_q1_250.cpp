bool possibleLiars(vector<int> v, int k)
{
	int n = v.size();
	// if there are k liars, there must be exactly k answers that are > k
	int bigger = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i] > k)
		{
			bigger++;
		}
	}
	return bigger == k;

}
int getMinimum(vector <int> v)
{
	int n = v.size();
	sort(v.begin(), v.end());
	// all 0: then all are honest
	// otherwise, some are liars
	// check each number to see, can there be k liars?
	// if any k is possible, then return smallest
	// else return -1

	int s = accumulate(v.begin(), v.end(), 0);
	if (s == 0)
		return 0; // everybody is honest
	for (int k = 1; k <= n; k++)
	{
		if (possibleLiars(v, k))
		{
			return k;
		}
	}
	return -1;
}

Problem Statement

There is a group of N people numbered from 0 to N-1. Each of them is either an honest person or a liar.
You wish to know how many liars are in the group. To do this, you have asked the same question to every person in the group: "What is the number of liars in this group?".

The people in the group themselves know the exact number of liars, but since you are a foreigner in the group, they have not told it to you exactly.

Instead, the i-th person answered you as follows: "There are at least claim[i] liars in the group." It is known that statements by honest persons are always true.

However, statements by liars are always false.

So, if a liar claims that there are at least X liars in the group, then in fact there are less than X liars.

Now, given a vector <int> claim containing the N answers that you received, you would like to determine the number of liars in the group.

Unfortunately, there's another twist that makes this problem more complicated. The people in the group speak a different language than you, so you might have misunderstood some of their answers.

The answers in claim are how you understood them, but they might not match what the people actually told you.

If you definitely misunderstood at least one of the answers, return -1. Otherwise, assuming that you understood all answers correctly, return the minimum number of liars that could be in the group.

Definition

Class:
MinimumLiars
Method:
getMinimum
Parameters:
vector <int>
Returns:
int
Method signature:
int getMinimum(vector <int> claim)
(be sure your method is public)


Constraints
-
claim will contain between 2 and 50 elements, inclusive.
-
Each element of claim will be between 0 and 100, inclusive.
Examples
0)


{1,1,1,2}
Returns: 1
It would be impossible for all the members of the group to be honest because in that case, all of their answers would be 0.
It is, however, possible that only the last person is a liar and each of the first three persons is honest. Therefore the correct answer is 1.
1)


{7,8,1}
Returns: 2
The first two people claim that there are at least 7 and 8 liars, respectively, which is impossible as the group only has three people. Thus, they must be lying. The third person claims there is at least one liar, and this is definitely true since we have already identified two liars, so this person is honest.
2)


{5,5,5,5,5}
Returns: -1
Everybody agrees that there are at least 5 liars in the group. The group contains exactly 5 people, so in fact all of them claim that everybody is a liar. We can't assume that some person is honest because this person definitely wouldn't have claimed him/herself as being a liar. We also can't assume that all of them are liars because in this case it will appear that all their statements are true. Every scenario we can try leads to a contradiction, so you must have misunderstood at least one of the answers.
3)


{0,0,0,4,3,0}
Returns: 2

4)


{4,7,5}
Returns: 3
Every claim made is impossible. Therefore all three people in the group must be lying.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.