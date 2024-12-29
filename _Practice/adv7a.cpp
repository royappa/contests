#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

vector<string> split_nonre(string s, string sep)
{
	char *sC = (char *) malloc(s.size()+1);
	strcpy(sC, s.c_str());
	char *sepC = (char *) sep.c_str();
	
	char *word;
	vector<string> results;
	while ((word = strtok(sC, sepC)) != NULL)
	{
		results.push_back(word);
		sC = NULL;
	}
	return results;
}

void getInput(vector<string> &v) {
  string line;
  // goddamn c++ returns a \r on the end of line!!!
  while (getline(cin, line)) {
    while (line[line.size()-1] == '\n' || line[line.size()-1] == '\r') 
      line = line.substr(0, line.size()-1);
    v.push_back(line);
  }
  return;
}

const string signs = "23456789TJQKA";
bool has(vector<int> v, vector<int> pat) {
  for (int i = 0; i < pat.size(); i++) {
    auto p = find(v.begin(), v.end(), pat[i]);
    if (p == v.end()) {
      return false;
    }
    v.erase(p);
  }
  return true;
}
int cardType(string a) {
  vector<int> v(13, 0);
  for (char ch : a) {
    int p = signs.find(ch);
    v[p]++;
  }
  if (has(v, {5})) return 7;      // Five of a kind
  if (has(v, {4})) return 6;      // Four of a kind
  if (has(v, {3,2})) return 5;    // Full house
  if (has(v, {3,1,1})) return 4;  // Three of a kind
  if (has(v, {2,2,1})) return 3;  // Two pair
  if (has(v, {2,1,1,1})) return 2;  // Pair
  return 1;
}
bool cardComp(pair<string,int> ca, pair<string,int> cb) {
  string a = ca.first, b = cb.first;
  int t1 = cardType(a), t2 = cardType(b);
  if (t1 != t2) {
    return t1 < t2;
  }
  for (int i = 0; i < 5; i++) {
    int p1 = signs.find(a[i]), p2 = signs.find(b[i]);
    if (p1 != p2) {
      return p1 < p2;
    }
  }
  return false;
}
main() {
  vector<string> v;
  getInput(v);
  int n = v.size();
  vector<pair<string,int>> cards(n);
  transform(v.begin(), v.end(), cards.begin(), 
            [](string s) { vector<string> t = split_nonre(s, " "); return pair {t[0], stoi(t[1])};});  
  
  sort(cards.begin(), cards.end(), cardComp);
  LL res = 0;
  for (int i = 0; i < cards.size(); i++) {
    res += (i+1) * cards[i].second;
  }
  cout << res << endl;
  exit(0);
}
