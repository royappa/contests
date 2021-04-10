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


double nextAgree(string t, string skew, int gain)
{
	int th, tm, ts, sh, sm, ss;

	sscanf(t.c_str(), "%d:%d:%d", &th, &tm, &ts);
	sscanf(skew.c_str(), "%d:%d:%d", &sh, &sm, &ss);

//cout << th << " " << tm << " " << ts << endl;
//cout << ss << " " << sm << " " << ss << endl;
	int tt = th*3600+tm*60+ts;
	int st = sh*3600+sm*60+ss;

	if (gain > 0)
	{
		int diff = (st <= tt) ? tt-st : (12*3600-st+tt);
		//cout << diff << endl;
		return (double) diff/(double) gain;
	}
	else
	{
		int diff = (st <= tt) ? st+(12*3600-tt) : st-tt;
		//cout << diff << endl;
		return (double) diff/(double) abs(gain);
	}
}

int main()
{
cout << string::npos << endl;

	cout << 0 << endl << nextAgree(
"07:07:07",
"07:07:07",
1776) << endl;


	cout << 1 << endl << nextAgree(
	"11:59:58",
	"12:03:28",
-3) << endl;

	cout << 2 << endl << nextAgree(
"12:03:28",
"11:59:58",
3) << endl;

	cout << 3 << endl << nextAgree(
"03:03:02",
"03:01:47",
5	) << endl;

	cout << 4 << endl << nextAgree(
"03:03:02",
"03:01:47",
-5	) << endl;

	cout << 5 << endl << nextAgree(

"07:08:09",
"09:08:07",
-321
) << endl;


	return 0;
}

/*
Problem Statement

According to Lewis Carroll, a clock that has stopped is more accurate than one that is five minutes behind. He argues that the former is right twice a day, whereas the latter never shows the correct time. Then again, a clock that is always five minutes behind is in a sense perfectly accurate, and therefore an extraordinary specimen. More usually, a clock is ahead or behind because it runs at the wrong rate, so that its absolute discrepancy from the true time is steadily changing. If left unregulated, such a clock will show the true time at regular but perhaps lengthy intervals.
You are given two Strings of the form "hh:mm:ss". The first represents exactly the true time, while the second is exactly the time shown by an ill-tuned clock. This is an analog clock whose hour, minute, and second hands sweep continuously around the dial at a speed that is too fast or too slow by a constant factor. Both times are given in the North American style, where the hour ranges between 1 and 12, inclusive. Given an int specifying the non-zero number of seconds that the clock gains every hour, calculate the number of hours that elapse before it agrees with the true time. Your answer, a double, must be correct with either absolute or relative precision of 1.0e-9 (one billionth).
Definition

Class:
BadClock
Method:
nextAgreement
Parameters:
String, String, int
Returns:
double
Method signature:
double nextAgreement(String trueTime, String skewTime, int hourlyGain)
(be sure your method is public)


Notes
-
If hourlyGain is negative, the clock falls behind by a fixed number of seconds every hour.
-
It is not the case that the clock makes discrete jumps every so often. Rather, the hands of the clock are moving smoothly and continuously at a constant rate that is too slow or too fast relative to the true time.
Constraints
-
trueTime and skewTime each contain exactly eight characters in the format "hh:mm:ss", where the substring "hh" is a zero-padded integer between 1 and 12, inclusive, and "mm" and "ss" are zero-padded integers between 0 and 59, inclusive
-
hourlyGain is either between -1800 and -1, inclusive, or between 1 and 3600, inclusive
Examples
0)


"07:07:07"
"07:07:07"
1776
Returns: 0.0
The clock is already showing the true time.
1)


"11:59:58"
"12:03:28"
-3
Returns: 70.0
This clock loses three seconds every hour, and will catch up with the true time in exactly 70 hours.
2)


"12:03:28"
"11:59:58"
3
Returns: 70.0
This clock gains three seconds per hour.
3)


"03:03:02"
"03:01:47"
5
Returns: 15.0

4)


"03:03:02"
"03:01:47"
-5
Returns: 8625.0

5)


"07:08:09"
"09:08:07"
-321
Returns: 22.42367601246106

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.*/
