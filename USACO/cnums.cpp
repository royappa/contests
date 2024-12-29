/*
ID: royappa1
LANG: C++
PROG: cnums
*/
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

int t[256];

main ()
{
    ifstream fin("cnums.in");
    ofstream fout("cnums.out");
    
    int a, b;
    fin >> a >> b;
    int count = 0;
    for (int i = 0; i < 256; i++)
    {
    	int c = 0, w = i;
    	while (w > 0)
    	{
    		if (w%2 == 1)
    		{
    			t[i]++;
    		}
    		w /= 2;
    	}
    }
    for (int i = a; i <= b; i++)
    {
    	int c = t[(i&(255<<24))>>24] + t[(i&(255<<16))>>16] + t[(i&(255<<8))>>8] + t[i&255];
    	if (c <= 4)
    	{
    		count++;
    	}
   	}
   	fout << count << endl;
    exit (0);
}
