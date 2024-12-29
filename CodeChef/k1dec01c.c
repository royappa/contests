#include <stdio.h>
#include <math.h>


//using namespace std;

int px[2001], py[2001];

// algorithm from wikipedia, topcoder forums

typedef double LD;

int N, A, B, C;

#define SQR(x) ((x)*(x))
LD f(LD t)
{
	// Ax+By+C=0
	LD total = 0, x, y;
	if (A != 0)
	{
		// y = t
		// x = (-C-Bt)/A
		y = t;
		x = (-C-B*t)/A;
	}
	else // B != 0
	{
		// x = t
		// y = (-C-At)/B
		x = t;
		y = (-C-A*t)/A;
	}
	int i;
	for (i = 0; i < N; i++)
	{
		total += sqrt(SQR(px[i]-x)+SQR(py[i]-y));
	}
	return total;
}

LD ternary(LD left, LD right)
{
int iter = 0;
	while (right-left >= 1.0e-8)
	{
		LD left3 = left+(right-left)/3.0;
		LD right3 = right-(right-left)/3.0;
		if (f(left3) < f(right3))
			right = right3;
		else
			left = left3;
iter++;
	}
//cout << iter << endl;
    return (left+right)/2;

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
		int i;
		for (i = 0; i < N; i++)
		{
			gets(buf); sscanf(buf, "%d%d", &px[i], &py[i]);
		}
		printf("%.6lf\n", (double) f(ternary(-100e6, 100e6)));
	}
}

