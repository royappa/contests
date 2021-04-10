#include <bits/stdc++.h>
// GCJ 2017 R1B, problem A

using namespace std;
typedef long long LL;

typedef pair<LL,LL> pp;

bool check(double speed, vector<int> &pos, vector<int> &vel, int D) {
	int N = pos.size();
	for (int i = 0; i < N; i++) {
		if (double(vel[i])*D < speed*(D-pos[i]))
			return false;
	}
	return true;
}

void f(vector<int> &pos, vector<int> &vel, int D) {
	// find the highest constant speed at which we do not pass anybody else

	double lo = 0.0; // at this speed we will not pass anybody else
	double hi = 1e20;

	for (int i = 0; i < 2000; i++) {
		double mid = (lo+hi)/2.0;
		if (check(mid, pos, vel, D)) {
			lo = mid;
		}
		else {
			hi = mid;
		}
	}
	printf("%.6lf\n", lo);
	return;
}
int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		printf("Case #%d: ", testCase);

		int D, N;
		cin >> D >> N;
		vector<int> pos(N), vel(N);
		for (int i = 0; i < N; i++) {
			cin >> pos[i] >> vel[i];
		}
		f(pos, vel, D);
	}
	return 0;
}
