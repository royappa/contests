
int CircleDance::arrangeDancers(vector <int> h) 
{
	int n = h.size();
	sort(h.begin(), h.end());
	deque<int> circ;
	bool left = true;
	for (int i = n-1; i >= 0; i--)
	{
		if (left) 
			circ.push_front(h[i]);
		else
			circ.push_back(h[i]);
		left = !left;
	}
	
	int diff = 0;
	for (int i = 0; i < n; i++)
	{
		int d = circ[i] - circ[ (i==0)?n-1:i-1 ];
		diff = max(diff, d);
	}

	return diff;
}

Problem Statement
    
Given a group of dancers' heights, arrange a circle formation that minimizes the maximum height difference between each pair of neighboring dancers. Write a class CircleDance with a method arrangeDancers that takes a vector <int>, heights, and returns the maximum height difference between neighboring dancers.
Definition
    
Class:
CircleDance
Method:
arrangeDancers
Parameters:
vector <int>
Returns:
int
Method signature:
int arrangeDancers(vector <int> heights)
(be sure your method is public)
    

Constraints
-
heights will contain between 3 and 20 elements inclusive.
-
Each element of heights will be between 150 and 210 inclusive.
Examples
0)

    
{180,183,178,185}
Returns: 5
The dancers may be arranged in a circle like this:
    180
   /   \
185     178
   \   /
    183
Their height differences are shown below:
    180
(5)/   \(2)
185     178
(2)\   /(5)
    183
The maximum difference is 5. Other arrangements may not lead to an optimal solution. For example, the following one has a maximum difference of 7:
    180
(3)/   \(2)
183     178
(2)\   /(7)
    185
1)

    
{170,180,190}
Returns: 20
Any arrangement is equivalent to the following one:
     180
 (10)/ \(10)
  170 - 190
    (20)
So the result is 20.
2)

    
{180,180,180,180,180}
Returns: 0

3)

    
{184,165,175,186,192,200,176,192,194,168,205,201}
Returns: 10

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.