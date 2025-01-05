#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
int debug = 0;
vector<string> split_nonre(string s, string sep)
{
  char* sC = new char[s.size() + 1];
  std::strcpy(sC, s.c_str());

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

map<string,int> memo;
map<string,string> gate, lval, rval;

int eval(string wire) {
  if (memo.count(wire)) return memo[wire];

  if (debug > 0) cout << wire << endl;
  if (gate.count(wire) == 0) {
    if (debug > 0) cout << " num = " << stoi(wire) << endl;
    return stoi(wire);
  }
  string op = gate[wire];
  int lv = eval(lval[wire]);
  if (op == "IMM") return memo[wire] = lv;
  if (op == "NOT") return memo[wire] = ~lv;

  int rv = eval(rval[wire]);
  if (op == "AND") return memo[wire] = lv & rv;
  if (op == "OR") return memo[wire] = lv | rv;
  if (op == "LSHIFT") return memo[wire] = lv << rv;
  return memo[wire] = lv >> rv;
}

int main(int argc, char *argv[])
{
  if (argc > 1) debug = atoi(argv[1]);
  string line;
  while (getline(cin, line)) {
    vector<string> w = split_nonre(line, " ");
    if (w[1] == "->") {
      gate[w[2]] = "IMM";
      lval[w[2]] = w[0];
    }
    else if (w[2] == "->") {
      gate[w[3]] = "NOT";
      lval[w[3]] = w[1];
    }
    else {
      gate[w[4]] = w[1];
      lval[w[4]] = w[0];
      rval[w[4]] = w[2];
    }
  }
  // 
  gate["b"] = "IMM";
  lval["b"] = "16076";
  memo.clear();
  cout << eval("a") << endl;
}
