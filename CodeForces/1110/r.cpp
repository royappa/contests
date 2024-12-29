#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int k, n, c, a;
int main(int argc, char **argv)
{
	int b = atoi(argv[1]);
	cout << b << " " << 100000 << endl;
	srand(time(0));
	for (int i = 0; i < 100000; i++) {
		cout << rand()%b;
		if (i != 100000-1) cout << " ";
	}
	cout << endl;
	return 0;
}

