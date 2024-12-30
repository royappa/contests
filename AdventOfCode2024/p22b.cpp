#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;
int debug = 0;


int main(int argc, char *argv[])
{
  if (argc > 1) debug = atoi(argv[1]);
 
  LL sum = 0;
  string line;
  map<LL,unordered_map<string,int>> buyerBest; // buyer's best price for each code
  map<string,set<LL>> codeBuyers;
  set<string> allCodes;
  int num = 0;
  while(getline(cin, line)) {
    LL secret = stoll(line);
    LL cur = secret;
    LL last = secret;
    string s = "";
    for (int i = 0; i < 2000; i++) {
      secret ^= secret * 64; // step 1
      secret %= b; 
      secret ^= secret / 32;// step 2
      secret %= 16777216; 
      secret ^= secret * 2048LL; // step 3
      secret %= 16777216;
    
      // secret = ((((secret << 8)) >> 5) << 11) >> 24;
      int diff = secret%10 - last%10;
      int price = secret%10;
      s += char('A'+diff+9);
      if (s.size() >= 4) {
        string code = s.substr(s.size()-4);
        allCodes.insert(code);
        if (buyerBest[cur].count(code) == 0) {
          buyerBest[cur][code] = price;
          codeBuyers[code].insert(cur);
        }
      }
      last = secret;
    }
    sum += secret;
    if (debug > 10) cout << num++ << endl;
  }
  LL best = -(1LL<<62);
  cout << "Total codes = " << allCodes.size() << endl;
  cout << "Total buyers = " << buyerBest.size() << endl;
  string bestCode = "";
  num = 0;
  for (auto code : allCodes) {
    LL sum = 0;
    for (auto buyer : codeBuyers[code]) {
      sum += buyerBest[buyer][code];
    }
    if (sum > best) {
      best = sum;
      bestCode = code;
    }
    num++;
    if (debug > 10 && num%10 == 0) { cout << num << endl; }
  }
  cout << best << " " << bestCode << endl;  // 2098 is too high
}

