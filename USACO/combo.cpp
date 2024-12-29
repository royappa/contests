/*
ID: royappa1
LANG: C++
PROG: combo
*/
#include <bits/stdc++.h>

using namespace std;

main ()
{
    ifstream fin("combo.in");
    ofstream fout("combo.out");

	int N;
 	fin >> N;
 	set<vector<int> > s;

 	for (int t = 0; t < 2; t++) {
		int a, b, c;
		fin >> a >> b >> c;

		for (int i = a-2; i <= a+2; i++) {
			for (int j = b-2; j <= b+2; j++) {
				for (int k = c-2; k <= c+2; k++) {
					int ii = ((i%N)+N)%N;
					int jj = ((j%N)+N)%N;
					int kk = ((k%N)+N)%N;
					vector<int> v;
					v.push_back(ii);
					v.push_back(jj);
					v.push_back(kk);
					s.insert(v);
				}
			}
		}
	}

	fout << s.size() << endl;
    exit (0);
}
