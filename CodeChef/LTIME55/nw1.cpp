#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	vector<string> dow = {"mon", "tues", "wed", "thurs", "fri", "sat", "sun"};

	while (T-- > 0)
	{
		int W;
		string S;
		cin >> W >> S;
		int cur = find(dow.begin(), dow.end(), S)-dow.begin();
		map<int,int> m;
		for (int i = 0; i < W; i++) {
			m[cur]++;
			cur = (cur+1)%7;
		}
		for (int i = 0; i < 7; i++) {
			cout << m[i];
			if (i != 6) cout << " ";
		}
		cout << endl;
	}
}

