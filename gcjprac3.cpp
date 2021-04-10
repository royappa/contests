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

class MSQErr {
public:

double calcErr(vector<int> score, string c, double t)
{
	int n = score.size();

	vector<double> error(n);

	for (int i = 0; i < n; i++)
	{
		char ch = (score[i] < t) ? 'N' : 'C';
		error[i] = (ch == c[i]) ? 0 : (score[i]-t)*(score[i]-t);
	}
	double m = 0.0;
	for (int i = 0; i < n; i++)
	{
		m += error[i];
	}
	return m / n;
}

double fp(vector<int> scores, string c, double x)
{	// f(x) is min when f'(x) == 0
	// f'(x) = limit x0->x of (f(x)-f(x0))/(x-x0)

double minErr(vector <int> score, string cancerous)
{
	double best = -1;
	double B = 0, E = 0;
	for (double t = -1001; t <= 1001; t += 1.0)
	{
		double err = calcErr(score, cancerous, t);
		if (err < best || best == -1)
		{
			//cout << err << " " << t << endl;
			best = err;
			B = t-1;
			E = t+1;
		}
	}
	double fB = fp(scores, cancerous, B);
	double fE = fp(scores, cancerous, E);

	double mid, fMid;
	for (int i = 0; i < 500; i++)
	{
		mid = (B+E)/2.0;
		fMid = fp(score, cancerous, mid);
		if (fB*fMid < 0)
		{
			fE = fMid;
		}
		else
		{
			fB = fMid;
		}
	}
	return calcErr(score, cancerous, mid);
}

};

Problem Statement

A cancer screening protocol is given data about a cell and gives the cell a score.

The protocol also specifies a threshold value. The protocol classifies cells with scores less than the threshold as non-cancerous, and cells with scores greater than or equal to the threshold as cancerous.

The effectiveness of a protocol is calculated by applying it to data about known cells from a test bank.

The "squared_error" for a cell is 0 if the protocol successfully classifies it.

If a cell is misclassified, its squared_error is calculated as the square of the difference between the threshold and the cell's score.

The "mean_squared_error" for the protocol is the average of the squared_errors from all the cells.

We want to choose a threshold that will minimize the mean_squared_error for our protocol.

Create a class MSQErr that contains a method minErr that is given a vector <int> scores giving the scores calculated by the protocol for the test cells, and a string cancerous that indicates for each test cell whether it is cancerous ('C') or non-cancerous ('N').

The method chooses an optimal threshold and returns the resulting minimum mean_squared_error.

The i-th character of cancerous corresponds to the i-th element of scores.

Definition

Class:
MSQErr
Method:
minErr
Parameters:
vector <int>, string
Returns:
double
Method signature:
double minErr(vector <int> score, string cancerous)
(be sure your method is public)


Notes
-
The returned value must be accurate to within a relative or absolute value of 1E-9
Constraints
-
cancerous will contain between 2 and 50 characters inclusive.
-
The number of elements in scores will equal the number of characters in cancerous.
-
Each character in cancerous will be 'N' or 'C'.
-
Each value in scores will be between -1,000 and 1,000 inclusive.
Examples
0)


{3,3,1,8}
"NNNC"
Returns: 0.0
By choosing a threshold of 5, this protocol classifies all of the test cells correctly.
1)


{5,2,3,6}
"CCNC"
Returns: 0.125
By choosing the threshold at 2.5, the cells with scores of 2 and 3 will both be misclassified. This will result in a mean_squared_error of (0 + (2.5-2)^2 + (3-2.5)^2 + 0)/4 = 0.125. This is the only threshold that will give such a low mean_squared_error.
2)


{5,2,3,6,2}
"CCNCN"
Returns: 0.1
The same threshold is best, but now the sum of the squared errors is divided by 5 instead of 4.
3)


{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}
"NNNCNNNCNNNCNCCCCCCC"
Returns: 2.34

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.