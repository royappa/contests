#include <bits/stdc++.h>
// Yandex 2016 warmup A

using namespace std;
typedef long long LL;

int main()
{
	string x;
	cin >> x;
	string v = "", c = "";
	for (auto z : x)
		if (string("aeiouy").find(z) != -1)
			v += z;
		else
			c += z;
	cout << (v > c ? "Vowel" : "Consonant") << endl;
	return 0;
}
