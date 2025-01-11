#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int debug = 0;

vector<string> split_subseq(const string &s, const string &sep) {
    vector<string> result;
    int start = 0;
    int sep_pos;

    if (sep.empty()) {
        result.push_back(s);
        return result;
    }
    // Find the separator in the string and split
    while ((sep_pos = s.find(sep, start)) != string::npos) {
        result.push_back(s.substr(start, sep_pos - start));
        start = sep_pos + sep.size(); // Move past the separator
    }

    // Add the last segment (or the entire string if no separator was found)
    result.push_back(s.substr(start));
    return result;
}

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(int argc, char *argv[])
{
  if (argc > 1) { debug = atoi(argv[1]); }
  
  map<string,int> pat;
  pat["children"] = 3;
  pat["cats"] = 7;
  pat["samoyeds"] = 2;
  pat["pomeranians"] = 3;
  pat["akitas"] = 0;
  pat["vizslas"] = 0;
  pat["goldfish"] = 5;
  pat["trees"] = 3;
  pat["cars"] = 2;
  pat["perfumes"] = 1;

  for (int i = 1; i <= 500; i++) {
    string line;
    getline(cin, line);
    vector<string> w = split_subseq(line.substr(line.find(':')+2), ", ");
    bool all = true;
    for (auto s : w) {
      vector<string> v = split_subseq(s, ": ");
      if (debug) cout << i << " s = ("  << s << ") v0 = (" << v[0] << ") v1 = (" << v[1] << ")" << endl;
      string key = v[0];
      int val = stoi(v[1]);
      if ( ((key == "cats" || key == "trees") && pat.count(key) && !(val > pat[key])) ||
           ((key == "pomeranians" || key == "goldfish") && pat.count(key) && !(val < pat[key])) ||
           ((key == "samoyeds" || key == "children" || key == "akitas" || key == "vizslas" || key == "cars" || key == "perfumes") && pat.count(key) && pat[key] != val) ) {
        if (debug) cout << i << " fails key = " << key << " val = " << val << " should be " << pat[key] << endl;
        all = false;
        break;
      }
    }
    if (all) {
      cout << i << endl;
      exit(1);
    }
  }
  cout << "oops" << endl;
}
