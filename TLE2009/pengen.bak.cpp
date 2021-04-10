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


void gen(char last, int len)
{
	cout << (last=='\t' 	? 'T' :
			last==' ' 	? 'S' :
			last=='\n'	? 'N'	:
			last=='\''	? 'Q' :
			last=='.'	? 'D'	:
			last==':'	? 'C' :
			last=='X'	? 'X' :
			last=='_'	? 'U' :
			last=='`'	? 'B'	: 'x');
	cout << " " << len << endl;
}

int main()
{
	std::ifstream fin("pen.txt");

	char buf[1000];

	while (!fin.eof())
	{
		memset(buf, '\0', sizeof(buf));
		fin.getline(buf, sizeof(buf));
		int l = strlen(buf);
		buf[l] = '\n';
		buf[l+1] = '\0';
		string s(buf);

		char last = 0;
		int len = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != last)
			{
				if (last != 0)
				{
					gen(last, len);
				}
				last = s[i];
				len = 1;
			}
			else
			{
				len++;
			}
		}
		gen(last, len);
	}

}
