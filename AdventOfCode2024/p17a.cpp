#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;

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

LL readInt(string s) {
  vector<string> w = split_nonre(s, ":");
  return stoll(w[1]);
}

LL combo(int operand, LL A, LL B, LL C) {
  LL reg[] = {A, B, C};
  return operand < 4 ? operand : reg[operand-4];
}
int main(int argc, char *argv[])
{
  string line;
  getline(cin, line);
  LL A = readInt(line);
  getline(cin, line);
  LL B = readInt(line);
  getline(cin, line);
  LL C = readInt(line);
  getline(cin, line);
  getline(cin, line);
  vector<string> w = split_nonre(line, " ");
  vector<string> w1 = split_nonre(w[1], ",");
  vector<LL> mem;
  for (auto x : w1) {
    mem.push_back(stoll(x));
  }
  if (argc > 1) A = atoll(argv[1]);

  cout << A << " " << B << " " << C << endl;
  int len = mem.size();
  int pc = 0;
  vector<LL> output;
  while (pc < len) {
    // cout << pc << " " << A << " " << B << " " << C << endl;
    LL val;
    int opcode = mem[pc];
    LL operand = mem[pc+1];
    // cout << "opcode: " << opcode << " lit = " << operand << " com = " << combo(operand, A, B, C) << endl;
    switch (opcode) {
      case 0: // adv
        val = combo(operand, A, B, C);
        A >>= val;
        pc += 2;
        break;
      case 1: // bxl
        B ^= operand;
        pc += 2;
        break;
      case 2: // bst
        val = combo(operand, A, B, C);
        B = val % 8;
        pc += 2;
        break;
      case 3: // jnz
        if (A != 0) {
          pc = operand;
        }
        else {
          pc += 2;
        }
        break;
      case 4: // bxc
        B ^= C;
        pc += 2;
        break;
      case 5: // out
        val = combo(operand, A, B, C);
        output.push_back(val%8);
        // cout << "out " << val%8 << endl;
        pc += 2;
        break;
      case 6: // bdv
        val = combo(operand, A, B, C);
        B = A >> val;
        pc += 2;
        break;
      case 7: // cdv
        val = combo(operand, A, B, C);
        C = A >> val;
        pc += 2;
        break;
    }
  }
  //cout << pc << " " << A << " " << B << " " << C << endl;
  for (int i = 0; i < output.size(); i++) {
    cout << output[i];
    if (i+1 < output.size()) cout << ",";
  }
  cout << endl;
  // cout << res << endl;
}

