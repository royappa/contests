
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

// REMOVE BEFORE SUBMIT!

class Mountain {

public:
double measure2(double sx, double sy, double fx, double fy, int c)
{
	if (sx == fx || sy == fy)
		return pow(1.0-0.05, c);
	return pow(1.0-0.05, c*sqrt(2.0));
}


double measure(double sx, double sy, double fx, double fy)
{
	return pow(1-0.05, 80);
}

};

class DensityImaging {
public:

double sample[4][110][110]; // 0=left-right, 1=up-down, 2=diag, 3=antidiag
double result[110][110];
double result2[110][110];

vector <double> image(vector <string> s, double costPerMeasurement)
{
	Mountain mountain;

	double p, m, d;
	int count, r, c;
	memset(sample, 0, sizeof(sample));

	for (int t = 0; t < 101; t++)
	{
		// left-right

		p = t+0.5;
		count = 0;
		for (c = 0; c < 101; c++)
		{
			if (s[t][c] == 'X')
				count++;
		}
		if (count > 0)
		{
			m = Mountain::measure(0.0, p, 101.0, p);
			d = 1.0-pow(m, 1.0/count);
			for (c = 0; c < 101; c++)
			{
				if (s[t][c] == 'X')
					sample[0][t][c] = d;
			}
		}
		// top-down
		count = 0;
		for (r = 0; r < 101; r++)
		{
			if (s[r][t] == 'X')
				count++;
		}
		if (count > 0)
		{
			m = mountain.measure(p, 0.0, p, 101.0);
			d = 1.0-pow(m, 1.0/count);
			for (r = 0; r < 101; r++)
			{
				if (s[r][t] == 'X')
					sample[1][r][t] = d;
			}
		}
	}

	double s2 = sqrt(2.0);
	// diagonals: r-c = constant (t)
	r = 100;
	c = 0;
	for (int t = 100; t >= -100; t--)
	{
		//printf("---\n");
		count = 0;
		int len = 101-abs(t);
		for (int i = 0; i < len; i++)
		{
			if (s[r+i][c+i] == 'X')
				count++;
		}
		if (count > 0)
		{
			m = mountain.measure(r, c, r+len, c+len);
			d = 1.0-pow(m, 1.0/(s2*count));
			for (int i = 0; i < len; i++)
			{
				if (s[r+i][c+i] == 'X')
				{
					sample[2][r+i][c+i] = d;
					//printf("[%d,%d] t=%d %lf %lf r=%d c=%d i=%d len=%d\t(%d %d -> %d %d)\n", r+i, c+i, t, d, m, r, c, i, len, r, c, r+len, c+len);
				}
			}
		}
		r = max(r-1, 0);
		c = max(r-(t-1), 0);
	}

	// antidiagonals: r+c = constant (t)
	r = 0;
	c = 0;
	for (int t = 0; t <= 200; t++)
	{
		//printf("---\n");
		count = 0;
		int len = (t<100?t+1:200-t+1);
		for (int i = 0; i < len; i++)
		{
			if (s[r-i][c+i] == 'X')
				count++;
		}
		if (count > 0)
		{
			m = mountain.measure(r+1, c, r+1-len, c+len);
			d = 1.0-pow(m, 1.0/(s2*count));
			for (int i = 0; i < len; i++)
			{
				if (s[r-i][c+i] == 'X')
				{
					sample[2][r-i][c+i] = d;
					//printf("[%d,%d] t=%d %lf %lf r=%d c=%d i=%d len=%d\t(%d %d -> %d %d)\n", r-i, c+i, t, d, m, r, c, i, len, r+1, c, r+1-len, c+len);
				}
			}
		}
		r = min(r+1, 100);
		c = t < 100 ? 0: t+1-r;
	}

	// an "average" solution.. but unlikely to receive an "average" score..  :-)
	memset(result, 0, sizeof(result));
	for (r = 0; r < 101; r++)
	{
		for (c = 0; c < 101; c++)
		{
			if (s[r][c] != 'X')
				continue;

			long double sum = 0.0;
			for (int i = 0; i < 4; i++)
			{
				sum += sample[i][r][c];
			}
			result[r][c] = double(sum / 4);
		}
	}

	int radius = 2;
	memset(result2, 0, sizeof(result2));
	for (int r = 0; r < 101; r++)
	{
		for (int c = 0; c < 101; c++)
		{
			if (s[r][c] != 'X') continue;

			count = 0;
			long double sum = 0.0;
			for (int i = -radius; i <= radius; i++)
			{
				for (int j = -radius; j <= radius; j++)
				{
					int dr = r+i, dc = c+j;
					if (dr < 0 || dr >= 101 || dc < 0 || dc >= 101)
						continue;
					sum += result[dr][dc];
					count++;
				}
			}
			result2[r][c] = double(sum / count);
		}
	}

	for (int r = 0; r < 101; r++)
	{
		for (int c = 0; c < 101; c++)
		{
			if (s[r][c] != 'X') continue;

			count = 0;
			long double sum = 0.0;
			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++)
				{
					if (abs(i)+abs(j) != 1)
						continue;
					int dr = r+i, dc = c+j;
					if (dr < 0 || dr >= 101 || dc < 0 || dc >= 101)
						continue;
					if (s[dr][dc] != 'X')
						continue;
					sum += 0.25*result2[dr][dc];
					count++;
				}
			}
			sum += result2[r][c];
			count++;
			result[r][c] = double(sum / count);
		}
	}

	vector<double> ret;
	for (r = 0; r < 101; r++)
	{
		for (c = 0; c < 101; c++)
		{
			if (s[r][c] == 'X')
			{
				ret.push_back(result2[r][c]);
			}
		}
	}
	return ret;
}

};


int main()
{
	char buf[1000];

	vector<string> s;

	DensityImaging d;

	for (int i = 0; i < 101; i++)
	{
		gets(buf);
		buf[strlen(buf)-1] = '\0';
		s.push_back(buf);
	}

	vector<double> r = d.image(s, 0.01);
	for (int i = 0; i < r.size(); i++)
	{
		cout << r[i] << endl;
	}

	return 0;

}

