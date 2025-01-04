#include <bits/stdc++.h>
#include <fstream>

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

void transform(vector<vector<string>> &rules, string flip1, string flip2) {
  for (int i = 0; i < rules.size(); i++) {
    if (rules[i][4] == flip1) rules[i][4] = flip2;
    else if (rules[i][4] == flip2) rules[i][4] = flip1;
  }
}

//    rule(xb,    "AND",  yb,   "->", carry1, "fetch");
//    rule(sum1,  "XOR",  ci,  "->", zb,     "match");

bool rule(string in1, string op, string in2, string dummy, string &out1, string need, vector<vector<string>> &rules,
          set<string> &wires, set<string> &safe, bool update, vector<string> &subs) {
  string poss = "";
  for (auto v : rules) {
    string rin1 = v[0], rop = v[1], rin2 = v[2], rout = v[4];
    if (op == rop && ((in1 == rin1 && in2 == rin2) || (in1 == rin2 && in2 == rin1))) {
      if (need == "fetch") {
        out1 = rout; 
        return true;
      }
      else {
        if (out1 == rout) {
          return true;
        }
        else {
          poss = rout;
        }
      }
    }
  }
  if (need == "fetch") {
    cout << "fetch not done " << in1 << " " << op << " " << in2 << endl;
    out1 = "xxx";
    return false;
  }
  else {
    cout << "no match for " << in1 << " " << op << " " << in2 << " -> " << out1 << endl;
    if (!update) {
      out1 = poss;
      return false;
    }
    out1 = poss;
    vector<string> target = {in1, op, in2, dummy, out1};
    for (auto w : wires) {
      if (safe.count(w)) continue;
      for (int i = 0; i < 5; i += 2) {
        if (target[i] != w) {
          vector<vector<string>> subRules = rules;
          cout << "try swap " << target[i] << " " << w << endl;
          transform(subRules, target[i], w);
          auto tmp = out1;
          if (rule(in1, op, in2, dummy, out1, "match", subRules, wires, safe, false, subs)) { // that flip makes things work
            subs.push_back(target[i]);
            subs.push_back(w);
            cout << "swap " << target[i] << " " << w << " co = " << out1 << endl;
            return true; 
          }    
          out1 = tmp;      
        }
      }
    }
  }
  assert(update != true);
  return false;
}

int main(int argc, char *argv[])
{    
  if (argc > 1) debug = atoi(argv[1]);
 
  vector<vector<string>> rules;
  string line;
  getline(cin, line);
  while (line != "") {
    getline(cin, line);
  }
  set<string> wires, safe;
  safe.insert({"x00", "y00", "z00", "rvb", "svq", "z01", "ksr", "qfj", "qkm"});

  while (getline(cin, line)) {
    vector<string> w = split_nonre(line, " ");
    wires.insert({w[0], w[2], w[4]});
    rules.push_back(w);
  }
  /*
  // Full adder for x01, y01, ci (qkm)
  // x01 XOR y01    -> sum1   (rvb)
  // x01 AND y01    -> carry1 (svq)
  // sum1 XOR ci   -> sum     (z01) sum = sum1 XOR ci
  // sum1 AND ci   -> sum2    (ksr) sum2 = sum1 AND ci
  // sum2 OR carry1 -> co     (qfj) co = carry1 OR sum2 = ci for next full adder
  //
  */

  string ci = "qkm";
  vector<string> subs;
  for (int adder = 1; adder <= 44; adder++) {
    char buf[100];
    sprintf(buf, "%02d", adder);
    string xb = string("x")+buf, yb = string("y")+buf, zb = string("z")+buf;
    string sum1, sum2, carry1, co;
    rule(xb,    "XOR",  yb,     "->", sum1,   "fetch", rules, wires, safe, true, subs);   
    rule(xb,    "AND",  yb,     "->", carry1, "fetch", rules, wires, safe, true, subs);
    rule(sum1,  "XOR",  ci,     "->", zb,     "match", rules, wires, safe, true, subs);
    rule(sum1,  "AND",  ci,     "->", sum2,   "fetch", rules, wires, safe, true, subs);
    rule(sum2,  "OR",   carry1, "->", co,     "fetch", rules, wires, safe, true, subs);
    safe.insert({sum1, carry1, zb, sum2, co});
    if (debug) { cout << xb << " " << yb << " " << zb << " co " << co << endl; }
    ci = co;
  }
  for (int i = 0; i < subs.size(); i++) {
    cout << subs[i];
    if (i < (int)subs.size()-1) cout << ",";
  }
  cout << endl;
   // first bad one: ci = ctg from x14,y14
  /*
  x15 XOR y15 -> rjm     sum1
  y15 AND x15 -> mrm     carry1
  rjm XOR ctj -> z15   sum = sum1 XOR ci    actual: ctg XOR rjm -> qnw  (WRONG, qnw and z15 may be swapped)
  sum1 AND ctg -> dnn  sum2 = sum1 AND ci   actual: rjm AND ctg -> dnn  (OK) 
  */
  //cout << res << endl;
  // no match for rjm XOR ctg -> z15, ci = ctg
  // SWAP: qnw, z15

  // no match for msn XOR wrb -> z20, ci = wrb
  // SWAP: cqr, z20

  // no match for ncd XOR trt -> z27, ci = trt
  // SWAP: nfj, ncd

  // no match for dnt XOR fcm -> z37, ci = fcm
  // SWAP: vkg, z37 

}

