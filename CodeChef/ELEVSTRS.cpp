//https://www.codechef.com/COOK85/problems/ELEVSTRS
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
bool debug = false;

int main()
{
	int T;
	cin >> T;
	while (T--) {
		double N, V1, V2;
		cin >> N >> V1 >> V2;
		if (V2*V2 < 2*V1*V1) {
			cout << "Stairs";
		}
		else {
			cout << "Elevator";
		}
		cout << endl;
	}
	exit(0);
}

