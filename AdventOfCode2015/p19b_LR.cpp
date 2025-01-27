#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int debug = 0;

vector<string> split_nonre(string s, string sep)  // sep is a list of possible sep characters, not a substring
{
  char* sC = new char[s.size() + 1];
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

vector<string> rulesL;
vector<vector<string>> rulesR;
map<string,set<string>> FIRST, FOLLOW;
int numRules;
set<string> terminals;
int numRed = 0, numTerminalRed = 0;


void arrOut(vector<string> v) { for (auto x : v) cout << x << " "; }
void LR(string start, vector<string> tokens) {
  vector<string> stk;
  int numTokens = tokens.size();
  for (int i = 0; i < numTokens-1; i++) {
    int num = 0;
    stk.push_back(tokens[i]);
    cout << "Shift: " << tokens[i] << endl;
    if (debug) { cout << "Stack: "; arrOut(stk); cout << endl; }
    bool canReduce = false, canShift = false;
    do {
      int numMatches = 0, m = 0;
      for (int j = 0; j < numRules; j++) {
        vector<string> R = rulesR[j];
        if (stk.size() < R.size()) continue;
        vector<string> v(stk.end()-R.size(), stk.end());
        if (rulesL[j] == "e" && tokens[i+1] == "$") {
          v = stk;
        }
        if (debug) { cout << " Try match " << rulesL[j] << " => "; arrOut(rulesR[j]); cout << " to stk: "; arrOut(stk); cout << " LA = " << tokens[i+1] << " " << i << endl;}
        if (v == R && FOLLOW[rulesL[j]].count(tokens[i+1])) {
          if (debug) { cout << "Matched " << rulesL[j] << " => "; arrOut(rulesR[j]); cout << " to stk: "; arrOut(stk); cout << " LA = " << tokens[i+1] << " " << i << endl; }
          numMatches++;
          m = j;
        }
      }
      if (numMatches == 0) {
        bool match = false;
        int k = stk.size();
        for (int j = k-1; j >= 0; j--) {
          for (auto x : FIRST[stk[j]]) {
            for (int r = 0; r < numRules; r++) {
              string L = rulesL[r];
              if (FIRST[rulesR[r][0]].count(x) && FOLLOW[L].count(tokens[i+1])) {
                match = true;
                break;
              }
            }
          }
          if (match) break;
        }
        if (match) {
          canShift = true;
        }
        break;
      }
      if (numMatches > 1) {
        cout << "numMatches > 1" << endl; exit(1);
        break;
      }
      if (debug) { cout << "Reduce: " << rulesL[m] << " => " ; arrOut(rulesR[m]); cout << endl; }
      canReduce = true;
      vector<string> R = rulesR[m];
      stk.erase(stk.end()-R.size(), stk.end());
      stk.push_back(rulesL[m]);
      if (rulesR[m].size() == 1 && terminals.count(rulesR[m][0])) {
        numTerminalRed++;
      }
      numRed++;
      num++;
    } while (canReduce || canShift);
    if (!canReduce && !canShift) {
      cout << "Fail: not able to reduce or shift after token = " << i << " " << tokens[i] << endl;
    }
    if (debug) { cout << "After " << num << " reductions, stack: "; for (auto x : stk) { cout << x << " "; } cout << endl << "***" << endl;}
  }
  if (stk.size() != 1) {
    cout << "Fail, stack is not empty";
    exit(1);
  }
  if (stk[0] != start) {
    cout << "Fail, stack contains " << stk[0] << endl;
    exit(1);
  }
  return;
}

// no epsilons
void calcFIRST() {
  bool added;
  do {
    added = false;
    for (int i = 0; i < numRules; i++) {
      string L = rulesL[i], R = rulesR[i][0]; // R is first symbol on right
      if (L == R) continue;
      if (terminals.count(R) && FIRST[L].count(R) == 0) {
        FIRST[L].insert(R);
        added = true;
      }
      else {
        set<string> t = FIRST[R];
        for (auto x : t) {
          if (FIRST[L].count(x) == 0) {
            FIRST[L].insert(x);
            added = true;
          }
        }
      }
    }
  } while (added);
  return;
}

void calcFOLLOW() {
  bool added;
  do {
    added = false;
    for (int i = 0; i < numRules; i++) {
      int k = rulesR[i].size();
      for (int j = 0; j < k; j++) {
        string X = rulesR[i][j];
        if (terminals.count(X)) continue;
        set<string> f;
        if (j < k-1) {
          f = FIRST[rulesR[i][j+1]];
        }
        else {
          f = FOLLOW[rulesL[i]];
        }
        for (auto t : f) {
          if (FOLLOW[X].count(t) == 0) {
            FOLLOW[X].insert(t);
            if (debug) { cout << "Added FOLLOW of " << X << " = " << t << endl; }
            added = true;
          }
        }  
      }
    }    
  } while (added);
  return;
}

int main(int argc, char *argv[])
{
  if (argc > 1) { debug = atoi(argv[1]); }
  string line;

  vector<string> ruleSet;
  while (getline(cin, line) && line != "") {
    ruleSet.push_back(line);
  }
  string mol;
  getline(cin, mol);

  numRules = 0;
  for (auto rule : ruleSet) {
    string L = rule.substr(0, rule.find(' ')), R = rule.substr(rule.find('>')+2);
    rulesL.push_back(L);
    rulesR.push_back(split_nonre(R, ","));
    numRules++;
  }
  if (debug < 0) {
    cout << numRules << endl;
    for (int i = 0; i < numRules; i++) {
      cout << rulesL[i] << " => ";
      for (auto x : rulesR[i]) {
        cout << x << " ";
      }
      cout << endl;
    }
  }
  for (int i = 0; i < numRules; i++) {
    for (auto x : rulesR[i]) {
      if (find(rulesL.begin(), rulesL.end(), x) == rulesL.end()) {
        terminals.insert(x);
      }
    }
  }
  if (debug) {
    cout << "Terminals: ";
    for (auto x : terminals) { cout << x << " ";} cout << endl;
  }
  for (auto x : terminals) {
    FIRST[x].insert(x);
  }
  calcFIRST();
  if (debug) {
    for (auto x : FIRST) {
      cout << "FIRST of " << x.first << " = ";
      for (auto y : x.second) {
        cout << y << " ";
      }
      cout << endl;
    }
  }
  FOLLOW["e"].insert("$");
  calcFOLLOW();
  if (debug) {
    for (auto x : FOLLOW) {
      cout << "FOLLOW of " << x.first << " = ";
      for (auto y : x.second) {
        cout << y << " ";
      }
      cout << endl;
    }
  } 
  vector<string> tokens = split_nonre(mol, ",");
  tokens.push_back("$");
  LR("e", tokens);
  cout << "numRed = " << numRed << " numTerm = " << numTerminalRed << " diff = " << (numRed-numTerminalRed) << endl;
}
