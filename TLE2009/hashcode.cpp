#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

string f(string a) {
        while (a.size() % 32 != 0)
                a += "IPsecV9";
        string ret = "";
        for (int i = 0; i < 32; i++) {
                unsigned v = 0;
                for (int j = i; j < a.size(); j += 32)
                        v = (v * 7 + a[j]) % 26;
                ret += v + 'A';
        }
        reverse(ret.begin(),ret.end());
        return ret;
}
int main()
{
	string prog1 = "main() { puts(\"";
	string mid = "EWMOBZWJBOXLCOYUABFBBSMLABDPVPYG";
	string prog2 = "\"); }";

	string prog = prog1+mid+prog2;
	string hashs = f(prog);
	int counter = 0;
	while (hashs != mid)
	{
		mid = hashs;
		prog = prog1+mid+prog2;
		hashs = f(prog);
		if (counter % 1000 == 0)
			cout << counter << endl;
		counter++;
	}
	cout << hashs << " " << prog << endl;

}


