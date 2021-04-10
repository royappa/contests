// SEE COMMENTS FOR CODE ATTRIBUTIONS (IF ANY)
// CAN'T FIND RULES ABOUT USING CODE FOUND ON WEB
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
#include <string>
#include <cstring>

using namespace std;

int px[2001], py[2001];

// ternary search algorithm from wikipedia, topcoder forums

typedef double LD;

int N, A, B, C;

LD cx, cy, dx, dy;

#define SQR(x) ((x)*(x))

// taken from http://www.dreamincode.net/code/snippet244.htm
double heronsqrt(double val)  {

        int dig=0;
        int n = (int) val;
        while((n >>= 1) > 0)            // count binary digits
                dig++;
        n = 2 << (dig >> 1);    // initialize at 2^(D/2)
        double err;
        double x = n;
        LD e;
        do {
                err = x;
                x = (x + val/x ) /2;
                e = err-x;
                //if (e < 0) e = -e;
        }
        while (e >= 0 ? e >= 1.0e-8 : -e >= 1.0e-8);
        //while (fabs(err-x)>=1.0e-8);

        return x;
}

//#define sqrt heronsqrt

LD f(LD t)
{
	// Ax+By+C=0
	LD total = 0, x, y;
	x = cx+t*dx;
	y = cy+t*dy;
	for (int i = 0; i < N; i++)
	{
		total += sqrt(SQR(px[i]-x)+SQR(py[i]-y));
	}
	return total;
}

LD ternary(LD left, LD right, LD eps)
{
int iter = 0;
	LD fl = f(left), fr = f(right);
	while (fabs(fl-fr) >= eps)
	{
		LD third = (right-left)/3.0;
		LD left3 = left+third;
		LD right3 = right-third;
		LD fr3 = f(right3);
		LD fl3 = f(left3);
		if (fl3 < fr3)
		{
			right = right3;
			fr = fr3;
		}
		else
		{
			left = left3;
			fl = fl3;
		}
//printf("%.6lf %.6lf %.6lf\n", left, right, fabs(fl-fr));
iter++;
	}
//cout << iter << endl;
    return (left+right)/2;

}

void g(LD x0, LD y0, LD &x1, LD &y1, LD &dx, LD &dy, LD &t)
{

	LD x2, y2; // second point on the line
	if (A == 0) // line is horizontal
	{
		LD y = -C/(LD)B;
		x1 = 0;
		y1 = y;
		x2 = 1;
		y2 = y;
	}
	else if (B == 0) // line is vertical
	{
		LD x = -C/(LD)A;
		x1 = x;
		y1 = 0;
		x2 = x;
		y1 = 1;
	}
	else
	{
		// y axis intercept
		x1 = 0;
		y1 = -C/(LD) B;
		// x axis intercept
		x2 = -C/(LD) A;
		y2 = 0;
	}
	dx = x2 - x1;
	dy = y2 - y1;
	t = ((x0 - x1) * dx + (y0 - y1) * dy) / (dx * dx + dy * dy);
}

LD newton(LD x0)
{
	// x(n+1) = x(n)-f1(x(n))/f2(x(n))

	LD x1 = x0;
	LD z;
	do
	{
		x0 = x1;

		LD e = 1.0e-4;
		LD f1 = (f(x0+e)-f(x0-e))/(2*e);
		LD f2 = (f(x0-e)-2*f(x0)+f(x0+e))/(e*e);
		x1 = x0-f1/f2;
		z = f(x1)-f(x0);
	} while (z >= 0 ? z >= 1.0e-8 : -z >= 1.0e-8);
	return x1;
}

int main()
{
	int T;
	char buf[1024];
	gets(buf); sscanf(buf, "%d", &T);
	while (T-- > 0)
	{
		gets(buf); sscanf(buf, "%d", &N);
		gets(buf); sscanf(buf, "%d%d%d", &A, &B, &C);
//printf("%d %d %d %d\n", N, A, B, C);
		LD t1, t2;
		for (int i = 0; i < N; i++)
		{
			gets(buf); sscanf(buf, "%d%d", &px[i], &py[i]);
			LD t;
			g(px[i], py[i], cx, cy, dx, dy, t);
			if (i == 0)
			{
				t1 = t2 = t;
			}
			if (t < t1)
				t1 = t;
			if (t > t2)
				t2 = t;
		}

		cout << t1-1 << " " << t2+1 << endl;
		printf("%.6lf\n", (LD) f(ternary(t1-1, t2+1, 1.0e-7)));

		//printf("%.6lf\n", (LD) f(newton(ternary(-100e6, 100e6, 1))));
	}
}

