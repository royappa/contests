#include <bits/stdc++.h>
// GCJ 2016 R1C, problem A

using namespace std;
typedef long long LL;

typedef pair<int,int> pi;

void emit(int i) { printf(" %c", char('A'+i)); }
void emit2(int i, int j) { printf(" %c%c", char('A'+i), char('A'+j)); }
int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		int N;
		cin >> N;
		vector<pi> v(N);
		int tot = 0;
		for (int i = 0; i < N; i++)
		{
			int p;
			cin >> p;
			v[i] = {p,i};
			tot += p;
		}
		printf("Case #%d:", testCase);
		while (tot > 0)
		{
			sort(v.rbegin(), v.rend());
			int n = v.size();
			if (v[0].first == 1)
			{
				if (n%2 == 1)
				{
					emit(v[n-1].second);
					n--;
				}
				for (int i = 0; i < n; i += 2)
				{
					emit2(v[i].second, v[i+1].second);
				}
				tot = 0;
			}
			else if (v[0].first >= v[1].first+2)
			{
				emit2(v[0].second, v[0].second);
				v[0].first -=2;
				tot -= 2;
			}
			else if (v[0].first == v[1].first+1)
			{
				emit(v[0].second);
				v[0].first--;
				tot--;
			}
			else // v[0].first == v[1].first
			{
				emit2(v[0].second, v[1].second);
				v[0].first--;
				v[1].first--;
				tot -= 2;
			}
		}
		printf("\n");
	}
	return 0;
}
