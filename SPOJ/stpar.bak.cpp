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

main ()
{

   	int D;

   	cin >> D;
   	while (D > 0)
   	{
		int order[1001];
		for (int i = 0; i < D; i++)
		{
			cin >> order[i];
		}

		list<int> stack;
		int last = 0;
		bool ok = true;
		for (int i = 0; i < D; i++)
		{
			int next = order[i];
			if (next == last+1)
			{
				last = next;
				continue;
			}
			while (stack.size() > 0 && stack.front() == last+1)
			{
				stack.pop_front();
				last++;
			}
			if (next == last+1)
			{
				last = next;
				continue;
			}
			if (stack.size() == 0)
			{
				stack.push_front(next);
				continue;
			}
			if (stack.front() < next)
			{
				ok = false;
				break;
			}
			stack.push_front(next);
			cin >> D;
		}
		cout << (ok ? "yes" : "no") << endl;
	}
    exit (0);
}
