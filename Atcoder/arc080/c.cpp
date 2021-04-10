#include <bits/stdc++.h>


using namespace std;

typedef long long LL;
typedef pair<LL,LL> pp;

void fail() { cout << "No" << endl; exit(0); }

int main()
{
	int N;
	cin >> N;
	vector<int> v(N);
	vector<int> even, odd, four;
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
		if (v[i]%4 == 0)
			four.push_back(v[i]);
		else if (v[i]%2 == 0)
			even.push_back(v[i]);
		else
			odd.push_back(v[i]);
	}
	int i = 0, j = 0, k = 0;
	int last = -1;
	if (odd.size() > 0) {
		last = odd[k++];
	}
	else if (even.size() > 0) {
		last = even[j++];
	}
	else {
		last = four[i++];
	}
	while (i+j+k < N) {
		if (last%2 == 1) { // last was odd, need a 4
			if (i == four.size()) fail();
			last = four[i++];
		}
		else if (last%4 == 0) { // last was %4==0, so use up an odd
			if (k < odd.size())
				last = odd[k++];
			else if (j < even.size())
				last = even[j++];
			else
				last = four[i++];
		}
		else { // last was even, so use up an even if possible, else a four
			if (j < even.size())
				last = even[j++];
			else if (k < four.size())  // SHOULD HAVE USED "i" here and not "k", but got AC!!
				last = four[k++];
			else
				fail();
		}
	}
	cout << "Yes" << endl;
	exit(0);
}
