#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;

typedef pair<string,int> psi;
map<psi,LL> memo;

LL f(string num, int k)  // number of stones if we blink one num k times
{
  if (k == 0) {
    return 1LL;
  }
  psi key = {num, k};
  if (memo.count(key) > 0) {
    return memo[key];
  }
  LL res;
  if (num == "0") {
    res = f("1", k-1);
  }
  else if (num.size()%2 == 0) {
    int len = num.size();
    string left = num.substr(0, len/2);
    string right = num.substr(len/2);
    while (right[0] == '0' && right.size() > 1) right = right.substr(1);
    // cout << num << "=" << left << "|" << right << endl;
    res = f(left, k-1) + f(right, k-1);
  }
  else {
    LL x = atoll(num.c_str())*2024LL;
    char buf[100];
    sprintf(buf, "%lld", x);
    string t(buf);
    res = f(t, k-1);
  }
  memo[key] = res;
  return res;
}

int main(int argc, char *argv[1])
{
  int blinks = atoi(argv[1]);
  
  vector<string> v;
  string num;

  while (cin >> num) {
    v.push_back(num);
    cout << num << endl;
  }
  cout << "*" << endl;
  LL sum = 0;
  for (auto s : v) {
    sum += f(s, blinks);
  }
  cout << sum << endl;
  cout << "*" << endl;
  for (auto s : v) {
    cout << s << " = " << memo[{s,blinks}] << endl;
  }
}

