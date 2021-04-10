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
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

main()	
{
	vector<int> cards(5);
	for (int i = 0; i < 13; i++)
		cards[i] = i;
	long count = 0, total = 0;
	while (next_permutation(cards.begin(), cards.end()))
	{
		for (vector<int>::iterator it = cards.begin(); it != cards.end(); it++)
		{
			cout << (*it)+1 << " ";
		}
		cout << endl;
		/*
		for (int i = 0; i < 13; i++)
		{

			if (cards[i] == i)
			{
				count++;
				break;
			}
		}
		*/
		total++;
		if (total % 10000000 == 0)
			printf("total is %ld\n", total);
	}
	printf("final total is %ld\n", total);
	printf("final count is %ld\n", count);
	printf("probability is %lf\n", (double) count / (double) total);
	return 0;
}
