#include <bits/stdc++.h>

using namespace std;
int debug = 1;

bool allSame(string s) {
  set<char> t(s.begin(), s.end());
  return t.size() == 1;
}

bool bad(string s) {
  for (int i = 0; i < s.size(); i++) {
    for (int j = i+2; j < s.size(); j++) {
      for (int k = i+1; k < j; k++) {
        if (s[i] == s[j] && s[k] != s[i]) {
          return true;
        }
      }
    }
  }
  return false;
}
string result() {
  int n;
  cin >> n;
  vector<string> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  // a will be all strings with one unique letter; remove from v
  vector<string> a;
  for (int i = v.size()-1; i >= 0; i--) {
    if (allSame(v[i])) {
      a.push_back(v[i]);
      v.erase(v.begin()+i);
    }
  }
  // if nothing left, glom all strings and return
  if (v.size() == 0) {
    sort(a.begin(), a.end()); // sort to group all aaa, bbb etc. together
    string x = accumulate(a.begin(), a.end(), string(""));
    return x;
  }  
  // attach each single-unique-letter word to anything attachable
  for (int i = a.size()-1; i >= 0; i--) {
    bool found = false;
    for (int j = 0; j < v.size(); j++) {
      if (a[i][0] == v[j].back()) {
        v[j] += a[i];
        found = true;
        break;
      }
      else if (a[i][0] == v[j][0]) {
        v[j] = a[i] + v[j];
        found = true;
        break;
      }
    }
    if (found) {
      a.erase(a.begin()+i);
    }
  }

  // now everything in a does not connect with anything in v

  // everything left in a is distinct strings like aaaa, bbbb which don't or start anything in v
  string x = accumulate(a.begin(), a.end(), string(""));
  for (auto s : v) {
    for (int i = 0; i < s.size(); i++) {
      if (x.find(s[i]) != string::npos) {
        return "IMPOSSIBLE"; // something in v has a letter that occurs in a, which is bad
      }
    }
  }
  string ret = x;  // everything left in a can go on one end
  for (auto s : v) {
    if (bad(s)) {
      return "IMPOSSIBLE"; // one of the strings left in v is itself bad
    }
  }
  // now the things in v are individually good, but need to be pairwise linked
  bool changed;
  vector<string> vNew;
  do {
    changed = false;
    int pl = -1, pr = -1;
    for (int i = 0; i < v.size(); i++) {
      for (int j = i+1; j < v.size(); j++) {
        if (v[i][0] == v[j].back()) {
          changed = true;
          pl = j;
          pr = i;
          goto out;
        }
        else if (v[j][0] == v[i].back()) {
          changed = true;
          pl = i;
          pr = j;
          goto out;
        }
      }
    }
    out:
    if (changed) {
      string x = v[pl] + v[pr];
      if (pl > pr) {
        swap(pl, pr);
      }
      for (int i = v.size()-1; i >= 0; i--) {
        if (i == pl || i == pr) {
          v.erase(v.begin()+i);
        }
      }
      v.push_back(x);
    }   
  } while (changed);
  ret += accumulate(v.begin(), v.end(), string(""));
  // if (debug) cout << ret << endl;
  if (bad(ret)) {
    return "IMPOSSIBLE";
  }
  return ret;
}


int main() {
	int NT;
  cin >> NT;
	for (int testCase = 0; testCase < NT; testCase++) {
		printf("Case #%d: %s\n", testCase+1, result().c_str());
	}
	return 0;
}
