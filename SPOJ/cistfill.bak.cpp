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

#define MAX_N 50000

int b[MAX_N], h[MAX_N], w[MAX_N], d[MAX_N];

double z(double p, int v, int n, int b[], int h[], int w[], int d[])
{
	double total = 0.0;
	for (int i = 0; i < n; i++)
	{
		if (p >= b[i])
		{
			total += (min(p,double(b[i]+h[i]))-b[i])*double(w[i]*d[i]);
		}
	}
	return total-v;
}

double f(int v, int n, int b[], int h[], int w[], int d[])
{
	double lo = 0.0, hi = 1500000;
	/*
	// define: g(p) = volume in cisterns when water is at height level of p
	// want to find p' such that g(p') = v
	// find root of z(p) = g(p)-v
	// g(p) is a function that looks like this (p is along x axis)
	                ______________ g(p)
				___/
		   ____/      <--- volume v
	      /           ^
	 ____/            p'

	// so z(p) = g(p)-v is negative when p is left of p', positive when p is right of v, and z(p) ends up being constant (and possibly constant at 0)
	// so z(p) may end up being zero
	*/

	double mid;
	for (int i = 0; i < 60; i++)
	{
		mid = (lo+hi)/2.0;
		double zmid = z(mid, v, n, b, h, w, d);
		if (zmid >= 0)
		{
			hi = mid;
		}
		else
		{
			lo = mid;
		}
	}
	return mid;
}

main ()
{

   	int t;

   	scanf("%d", &t);
   	while (t-- > 0)
   	{
		int n;
		scanf("%d", &n);
		int total = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d%d", &b[i], &h[i], &w[i], &d[i]);
			total += h[i]*w[i]*d[i];
		}
		int v;
		scanf("%d", &v);
		if (v > total)
		{
			printf("OVERFLOW\n");
		}	
		else
		{
			printf("%.2lf\n", f(v, n, b, h, w, d));
		}
	}
    exit (0);
}
