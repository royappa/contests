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

#define debug 0

using namespace std;

typedef long long LL;

// here, b must be != 0
void eea2(LL a, LL b, LL& x, LL& y)
{
	if (a % b == 0)
	{
		x = 0LL;
		y = 1LL;
	}
	else
	{
		LL m, n;
		eea2(b, a % b, m, n);

		x = n;
		y = m-n*(a / b);
	}
	return;
}

// extended euclidean algorithm: bezout's identity
// given a,b > 0, return m,n s.t. m*a+n*b = gcd(a,b);
// considers gcd(a,0) = 0 = gcd(0, b)
// handles negative numbers, with gcd(a,b) = gcd(+-a, +-b) >= 0
void eea(LL a, LL b, LL& x, LL& y)
{
	if (a < 0 && b < 0)
	{
		eea2(-a, -b, x, y);
		x *= -1LL;
		y *= -1LL;
	}
	else if (a < 0)
	{
		eea2(-a, b, x, y);
		x *= -1LL;
	}
	else if (b < 0)
	{
		eea2(a, -b, x, y);
		y *= -1LL;
	}
	else
	{
		eea2(a, b, x, y);
	}
	return;
}

#define BAD (1LL<<62)

LL gcd(LL a, LL b) { return b == 0 ? a : gcd(b, a % b); }

LL solve(LL xi, LL yi, LL xj, LL yj, LL f)
{

	LL n;
	LL g = gcd(xi, xj);
	if (g == 1)
	{
		/*
			n = yi (mod xi)
			=> n = yi+m*xi

			n = yj (mod xj)

			=> yi+m*xi = yj (mod xj)

			yj-yi = m*xi (mod xj)

			=> m = (yj-yi)/xi (mod xj)
			=> m = (yj-yi)*xii (mod xj), where xii = xi^-1 mod xj

		*/
		LL xii, dum;
		eea(xi, xj, xii, dum);
		xii = ((xii%xj)+xj)%xj;
		LL m = (((yj-yi)*xii % xj)+xj)%xj;
		n = yi+m*xi;
	}
	else
	{
		/*
			n = yi (mod xi)
			=> n = yi+m*xi

			n = yj (mod xj)

			=> yi+m*xi = yj (mod xj)

			=> yi+m*xi = yj+k*xj
			=> yj-yi = m*xi-k*xj
			=>

			yj-yi = m*xi (mod xj)

			=> (yj-yi)-m*xi = k*xj

			=> yj-yi = k*xj+m*xi

			Let g = gcd(xj,xi); divide both sides by g

			(yj-yi)/g = m*(xi/g)+k*(xj/g)

			If (yj-yi)%g != 0, then there is no solution, because the LHS of above must be an integer
			Otherwise, again, we can find m and then calculate n
			xi/g, xj/g are relatively prime

		*/
		if ((yj-yi)%g != 0)
			return f+1;

		LL xgii, dum; // xgii = (xi/g)^-1  (mod xj/g)
		eea(xi/g, xj/g, xgii, dum);  // xgii = (xi/g)^-1 (mod xj/g)
		xgii = ((xgii%(xj/g))+(xj/g))%(xj/g);
		LL m = ((((yj-yi)/g)*xgii%(xj/g))+(xj/g))%(xj/g);
		n = yi+m*xi;
		if (debug) printf("gcd != 1\n");
	}
	LL prod = (xi*xj)/g;  // LCM, because n can be freely adjusted by multiples of the LCM
	n = ((n % prod) + prod) % prod;
	LL mm = yj >? yi;  // the two elevators must meet on a floor that both can reach

if (debug) printf("here1 n=%lld f=%lld yi=%lld xi=%lld yj=%lld xj=%lld\n", n, f, yi, xi, yj, xj);

	if (n >= mm && n < f)
	{
		return n;
	}
if (debug) printf("here2\n");
	int dm = 3;
	if (n < mm)
	{
		LL q = n+((mm-n+prod-1)/prod)*prod; // OVERFLOW HERE?? PROD CAN BE ALMOST 25*10^14
if (debug) printf("here3 q=%lld mm=%lld prod=%lld\n", q, mm, prod);
		for (LL delta = -dm; delta <= dm; delta++)
		{
			if (q+delta*prod >= mm && q+delta*prod < f)
				return q+delta*prod;
		}
		return n;
	}
	else if (n >= f)
	{

		LL q = n-((n-mm)/prod)*prod; // // OVERFLOW HERE?? PROD CAN BE ALMOST 25*10^14; n can be around prod, and mm can be small
if (debug) printf("here4 q=%lld mm=%lld prod=%lld\n", q, mm, prod);
		for (LL delta = -dm; delta <= dm; delta++)
		{
			if (q+delta*prod >= mm && q+delta*prod < f)
				return q+delta*prod;
		}
		return n;
	}

	return n;
}


bool canStep2(int i, int j, LL f, int e, int x[], int y[])
{
	// does there exist n such that:
	// n >= y[i]
	// n >= y[j]
	// n < f
	// n = y[i] (mod x[i])
	// n = y[j] (mod x[j])

	LL xi = x[i], yi = y[i], xj = x[j], yj = y[j];
	LL n = solve(xi, yi, xj, yj, f);
	LL mm = yi >? yj;

	return (n >= mm && n < f);
}

bool canStep(int i, int j, LL f, int e, int x[], int y[])
{
	bool r = canStep2(i, j, f, e, x, y);
	if (debug) printf("can %d %d -> %d %d = %d\n", y[i], x[i], y[j], x[j], r);
	return r;
}

bool canReach(int f, int e, int a, int b, int x[], int y[])
{
	int q[200], qHead = 0, qTail = 0, qNum = 0;
	int visited[200], goal[200];
	memset(visited, 0, sizeof(visited));
	memset(goal, 0, sizeof(goal));

	for (int i = 0; i < e; i++)
	{
		if (b >= y[i] && (b - y[i]) % x[i] == 0)
		{
			goal[i] = 1;
			if (debug) printf("goal %d %d\n", y[i], x[i]);
		}
	}
	for (int i = 0; i < e; i++)
	{
		if (a >= y[i] && (a - y[i]) % x[i] == 0)
		{
			if (debug) printf("start %d %d\n", y[i], x[i]);
			if (goal[i])
				return true;

			// add i to start queue
			q[qTail++] = i;
			qNum++;
			visited[i] = 1;
		}
	}
	while (qNum > 0)
	{
		int k = q[qHead++];
		qNum--;
		for (int i = 0; i < e; i++)
		{
			if (!visited[i] && canStep(k, i, f, e, x, y))
			{
				if (debug) printf("step %d %d -> %d %d\n", y[k], x[k], y[i], x[i]);
				if (goal[i])
					return true;
				visited[i] = 1;
				q[qTail++] = i;
				qNum++;
			}
		}
	}
	return false;
}

main()
{
	int n;

	// sort of unit testing
	srand(2828177+getpid());

	for (int c = 0; c < 1000000; c++)
	{
		LL a = rand()%25000000+25000000;
		LL b = rand()%25000000+25000000+1;
		LL x, y, g = rand()%25000000+1;
		a *= g; b *= g;
		g = gcd(a, b);
		eea2(a, b, x, y);
		//printf("%lld*%lld+%lld*%lld=%lld\n", a, x, b, y, g);
		if (a*x+b*y == g) printf("%lld %lld %lld %lld %lld\n", a, b, x, y, g);
	}
	return 0;
	int c = 0;
	for (int xi = 1; xi <= 22; xi++)
	for (int yi = 0; yi <= 22; yi++)
	for (int xj = 1; xj <= 22; xj++)
	for (int yj = 0; yj <= 22; yj++)
	for (int f = 1;  f <= 60; f++)
	{
		//printf("TRY(%d): %d %d %d %d %d\n", c++, xi, yi, xj, yj, f); fflush(stdout);
		if (c>=1000000 && c%1000000==0) printf("%d\n", c);fflush(stdout); c++;
		LL n = solve(xi, yi, xj, yj, f);
		if (n >= max(yi, yj) && n < f) // solve says "works"
		{
			//printf("OK: %d %d %d %d %d\n", xi, yi, xj, yj, f);
			if ((n-yi)%xi != 0 || (n-yj)%xj != 0)
			{
				printf("BAD1: %d %d %d %d %d\n", xi, yi, xj, yj, f);
			}
		}
		else
		{
			if (n == f+1) { printf("NOT_OK_G: %d %d %d %d %d\n", xi, yi, xj, yj, f); continue; }
			//printf("NOT_OK: %d %d %d %d %d\n", xi, yi, xj, yj, f);
			if ((n-yi)%xi!=0 || (n-yj)%xj != 0)
			{
				printf("BAD2: %d %d %d %d %d\n", xi, yi, xj, yj, f);
			}
		}
	}
	/*
	for (int c = 0; c < 10000000; c++)
	{
		int xi = rand()%50000000+1;
		int yi = rand()%50000000;
		int xj = rand()%50000000+1;
		int yj = rand()%50000000;
		int f = (xi+yi+xj+yj)%50000000;
		LL n = solve(xi, yi, xj, yj, f);
		if (n >= max(yi, yj) && n < f) // solve says "works"
		{
			printf("OK: %d %d %d %d %d\n", xi, yi, xj, yj, f);
			if ((n-yi)%xi != 0 || (n-yj)%xj != 0)
			{
				printf("BAD: %d %d %d %d %d\n", xi, yi, xj, yj, f);
			}
		}
		else
		{
			// how to check this?
		}
	}
	*/
	printf("DONE\n"); fflush(stdout);
	scanf("%d", &n);

	int x[200], y[200];

	while (n-- > 0)
	{
		int f, e, a, b;
		scanf("%d%d%d%d", &f, &e, &a, &b);

		for (int i = 0; i < e; i++)
		{
			scanf("%d%d", &x[i], &y[i]);
		}

		if (canReach(f, e, a, b, x, y))
		{
			printf("It is possible to move the furniture.\n");
		}
		else
		{
			printf("The furniture cannot be moved.\n");
		}
	}
	exit(0);
}
