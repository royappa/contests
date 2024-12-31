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

typedef tuple<string,string,string,int> inType;

int value(string wire, map<string,inType> &inputs) {
  auto [x, op, y, val] = inputs[wire];
  if (val != -1) {
    return val;
  }
  int vx = value(x, inputs);
  int vy = value(y, inputs);
  if (op == "AND") return vx & vy;
  else if (op == "OR") return vx | vy;
  else return vx ^ vy;
}

int main(int argc, char *argv[])
{
  if (argc > 1) debug = atoi(argv[1]);
 
  map<string,inType> inputs;
  string line;
  getline(cin, line);
  while (line != "") {
    vector<string> w = split_nonre(line, ": ");
    inputs[w[0]] = {"_", "_", "_", stoi(w[1])};
    getline(cin, line);
  }
  vector<string> bits;
  while (getline(cin, line)) {
    vector<string> w = split_nonre(line, " ");
    inputs[w[4]] = {w[0], w[1], w[2], -1};
    if (w[4][0] == 'z') {
      bits.push_back(w[4]);
    }
  }
  sort(bits.rbegin(), bits.rend());
  cout << "#bits " << bits.size() << endl;
  LL res = 0;
  for (auto b : bits) {
    res = (res << 1) + value(b, inputs);
  }
  cout << res << endl;
}

