#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

void DONEYES() { cout << "YES" << endl; exit(0); }
void DONENO() { cout << "NO" << endl; exit(0); }

int main()
{
	int n, k;
	cin >> n >> k;

	int s2 = n*2, s4 = n;

	vector<int> v(k);
	for (int i = 0; i < k; i++) {
		cin >> v[i];
	}
	// first fill all four-seats fully packed
	for (int i = 0; i < k; i++) {
		if (v[i] >= 4) {
			int num4 = v[i]/4;
			int can = min(s4, num4);
			v[i] -= can*4;
			s4 -= can;
		}
	}
	// if any fours empty, fill with 3 from same group
	if (s4 > 0) {
		for (int i = 0; i < k; i++) {
			if (v[i] == 3 && s4 > 0) {
				v[i] = 0;
				s4--;
			}
		}
	}
	// if any fours empty, fill with a 2 from one group and a 1 from another group
	if (s4 > 0) {
		int n2 = count(v.begin(), v.end(), 2);
		int n1 = count(v.begin(), v.end(), 1);
		while (s4 > 0) {
			if (n2 > 0 && n1 > 0) {
				s4--;
				n2--;
				n1--;
			}
			else
				break;
		}
		if (n2 == 0 && n1 == 0) DONEYES();
		while (s4 > 0) {
			if (n2 > 0) {
				n2--;
				s4--;
			}
			else if (n1 > 0) {
				n1--;
				s4--;
			}
			else
				break;
		}
		if (n1+n2 <= s2) DONEYES(); else DONENO();
	}
	// only 2 seaters are left and we MAY have any number of people even 4+ in a group
	for (int i = 0; i < k; i++) {
		int need = (v[i]+1)/2;
		if (need > s2) {
			cout << "NO" << endl;
			exit(0);
		}
		s2 -= need;
	}
	cout << "YES" << endl;
	exit(0);
}
