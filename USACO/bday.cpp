/*
ID: royappa1
LANG: C++
PROG: bday
*/
// RESOURCES USED: USED A CALENDAR TO FIND OUT THAT JAN. 1, 1800 IS A WEDNESDAY.

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
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int debug = 1;

bool isLeap(int y)
{
	return y % 4 != 0 ? false :
			y % 400 == 0 ? true :
				y % 100 == 0 ? false : true;
}

int daysInMonth(int m, int y)
{
	int d[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	return isLeap(y) && m == 2 ? d[m]+1 : d[m];
}

int dow(int y, int m, int d)
{
	int w = 3; // Jan. 1, 1800 is a Wednesday.

	int yy = 1800, mm = 1, dd = 1;

	while (!(y == yy && m == mm & d == dd))
	{
		dd++;
		w = (w + 1) % 7;
		if (dd > daysInMonth(mm, yy))
		{
			dd = 1;
			mm++;
		}
		if (mm > 12)
		{
			mm = 1;
			yy++;
		}
	}
	return w;
}

main ()
{
    ifstream fin("bday.in");
    ofstream fout("bday.out");

   	int m, d, y;
   	fin >> y >> m >> d;

   	int w = dow(y, m, d);

   	string month = w == 0? "sunday":
   					w == 1? "monday" :
   						w == 2 ? "tuesday" :
   							w == 3 ? "wednesday" :
   								w == 4 ? "thursday" :
   									w == 5 ? "friday" : "saturday";

   	fout << month << endl;
    exit (0);
}


/*
Problem 11: Bovine Birthday [Traditional, 2005]

Bessie asked her friend what day of the week she was born on. She
knew that she was born on 2003 May 25, but didn't know what day it
was. Write a program to help. Note that no cow was born earlier
than the year 1800.

Facts to know:

* January 1, 1900 was on a Monday.

* Lengths of months:
    Jan 31          May 31      Sep 30
    Feb 28 or 29    Jun 30      Oct 31
    Mar 31          Jul 31      Nov 30
    Apr 30          Aug 31      Dec 31

* Every year evenly divisible by 4 is a leap year (1992 = 4*498 so
  1992 will be a leap year, but the year 1990 is not  a leap year)

* The rule above does not hold for century years. Century years
  divisible by 400 are leap years, all other are not. Thus, the
  century years 1700, 1800, 1900 and 2100  are not leap years, but
  2000 is a leap year.

Do not use any built-in date functions in your computer language.

PROBLEM NAME: bday

INPUT FORMAT:

* Line 1: Three space-separated integers that represent respectively
        the year, month (range 1..12), and day of a date.

SAMPLE INPUT (file bday.in):

2003 5 25

INPUT DETAILS:

May 25, 2003

OUTPUT FORMAT:

* Line 1: A single word that is the day of the week of the specified
        date (from the lower-case list: monday, tuesday, wednesday,
        thursday, friday, saturday, sunday).

SAMPLE OUTPUT (file bday.out):

sunday

OUTPUT DETAILS:

      May 2003
Su Mo Tu We Th Fr Sa
             1  2  3
 4  5  6  7  8  9 10
11 12 13 14 15 16 17
18 19 20 21 22 23 24
25 26 27 28 29 30 31
*/
