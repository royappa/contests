#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> c(m);
    set<int> s;
    for(int c_i = 0;c_i < m;c_i++){
       cin >> c[c_i];
       s.insert(c[c_i]);
    }
    sort(c.begin(), c.end());
    vector<int> rc = c;
    for (int i = 0; i < n; i++)
    {
    	rc[i] = -rc[i];
    }
    sort(rc.begin(), rc.end());
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
       int dist = 1e9;
       if (s.count(i) == 1) continue;
       auto p = lower_bound(c.begin(), c.end(), i);
       if (p != c.end())

       left = i-(*--p);
       mx = max(mx, min(left, right));
    }
    cout << mx << endl;

    return 0;
}