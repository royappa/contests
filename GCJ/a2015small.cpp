#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		int Smax;
		string S;
		cin >> Smax >> S;
		int add = 0, cur = S[0] - '0';
		for (int i = 1; i < S.size(); i++)
		{
			if (cur < i)
			{
				add += i-cur;
				cur = i;
			}
			cur += S[i]-'0';
		}
		printf("Case #%d: %d\n", testCase, add);
	}
	return 0;
}
