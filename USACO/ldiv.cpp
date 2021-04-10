/*
ID: royappa1
LANG: C++
PROG: ldiv
*/
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

bool siGreaterEqual(string a, string b)
{
	if (a.size() == 0 && b.size() == 0)
		return true;
		
	int ia = 0;
	while (ia < a.size() && a[ia] == '0')
		ia++;
	int ib = 0;
	while (ib < b.size() && b[ib] == '0')
		ib++;
	a = a.substr(ia);
	b = b.substr(ib);
	if (a.size() > b.size())
	{
		return true;
	}
	else if (a.size() == b.size())
	{
		return a[0] > b[0] ? true : 
				a[0] == b[0] ? siGreaterEqual(a.substr(1), b.substr(1))
					: false;
	}
	return false;
}

int dig(char c) { return (int) (c-'0'); }
char ch(int d) { return (char) ('0'+d); }

string siAdd(string a, string b)
{
	int aLen = a.size(), bLen = b.size();
	int diff = abs(aLen-bLen);
	string pad(diff, '0');
	if (aLen < bLen)
	{
		a = pad+a;
	}
	else if (aLen > bLen)
	{
		b = pad+b;
	}
	int m = max(aLen, bLen);
	int carry = 0;
	string c = "";
	for (int i = m-1; i >= 0; i--)
	{
		int da = dig(a[i]), db = dig(b[i]);
		c = ch((da+db+carry)%10)+c;
		carry = (da+db+carry)/10;
	}
	if (carry > 0)
	{
		c = ch(carry)+c;
	}
	return c;
}

// a >= b
string siSub(string a, string b)
{
	if (siGreaterEqual(a, b) && siGreaterEqual(b, a))
		return "0";
	// now a > b
	int aLen = a.size(), bLen = b.size();
	int diff = aLen-bLen;
	string pad(diff, '0');
	if (bLen < aLen)
	{
		b = pad+b;
	}	
	int m = aLen;
	string c = "";
	for (int i = m-1; i >= 0; i--)
	{
		int da = dig(a[i]), db = dig(b[i]);

		if (da < db)
		{
			for (int j = i-1; j >= 0; j--)
			{
				if (a[j] > 0)
				{
					a[j]--;
					break;
				}
			}
			// now we have a borry
			da += 10;
		}
		c = ch(da-db)+c;		
	}
	return c;
}

string siDouble(string a)
{
	return siAdd(a, a);
}
		
string fixup(string s, int places)
{
	int p = s.size()-1;
	while (p >= 0 && s[p] == '0')
		p--;
	s = s.substr(0, p+1);
	while (s.size() < 35)
	{
		s = '0' + s;
	}
	return s;
}

string divide(int num, int den, int places) // num < den
{
	char buf[1000];
	sprintf(buf, "%d", num);
	string siNum = buf;
	int len = siNum.size();
	for (int i = 0; i < places; i++)
	{
		siNum += '0';
	}
	sprintf(buf, "%d", den);
	string siDen = buf;
	
	// compute num = Q*den+R
	/*
	Q = 0;

	while (num > den)
	{
		int f = 1;
		int den2 = den;
		while (num > den2)
		{
			num -= den2;
			Q += f;
			den2 *= 2;
			f *= 2;
		}
	}
	*/
	
	string siQ = "0";

	while (siGreaterEqual(siNum, siDen))
	{
		string siF = "1";
		string siDen2 = siDen;
		while (siGreaterEqual(siNum, siDen2))
		{
			/*
			cout << siNum << " " << siDen << endl;
			cout << siDen2 << endl;
			cout << siQ << " " << siF << endl;
			cout << "-------" << endl;
			*/
			siNum = siSub(siNum, siDen2);
			siQ = siAdd(siQ, siF);
			siDen2 = siDouble(siDen2);
			siF = siDouble(siF);
		}
	}
	return fixup(siQ.substr(0, 35), 35); 
}	
	

main ()
{
    ifstream fin("ldiv.in");
    ofstream fout("ldiv.out");
    
    int num, den;
    fin >> num >> den;
    
    string frac(35, '0');
   	int quo = num/den;
    int rem = num%den;
	if (rem != 0)
	{
		frac = divide(rem, den, 35);
	}

	char buf[1000];
   	sprintf(buf, "%d.%s", quo, frac.c_str());
   	string result = buf;

   	fout << result << endl;
    exit (0);
}
