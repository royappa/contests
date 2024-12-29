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

int memo[201][201];

double calc(double b, double c, double a)
{
	return (-a*a+b*b+c*c)/(2.0*b*c);
}

int main()
{
	int t;

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int AB, AC, AD, BC, BD, CD;

		scanf("%d%d%d%d%d%d", &AB, &AC, &AD, &BC, &BD, &CD);

		double cosa = calc(AD, BD, AB); // adj,adj,opp
		double cosb = calc(BD, CD, BC);
		double cosc = calc(CD, AD, AC);

		double V = (AD*BD*CD)*sqrt(1+2*cosa*cosb*cosc-cosa*cosa-cosb*cosb-cosc*cosc)/6.0;
		printf("%.4lf\n", V);
	}
	return 0;
}
