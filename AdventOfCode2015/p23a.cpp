#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int debug = 0;

int main(int argc, char *argv[])
{
  if (argc > 1) { debug = atoi(argv[1]); }
  vector<int> reg(2, 0);

  vector<string> prog;
  string line;
  while (getline(cin, line)) {
    prog.push_back(line);
  }
  int n = prog.size();
  int pc = 0;
  while (pc >= 0 && pc < n) {
    string code = prog[pc];
    int r = code[4]-'a';
    if (debug) { cout << "pc: " << setw(3) << pc << " " << setw(12) << code << " a = " << setw(4) << reg[0] << " b = " << setw(4) << reg[1] << " | "; }
    if (code[0] == 'h') { reg[r] /= 2; pc++; }
    else if (code[0] == 't') { reg[r] *= 3; pc++; }
    else if (code[0] == 'i') { reg[r]++; pc++; }
    else if (code[1] == 'm') {
      int offset = stoi(code.substr(5));
      if (code[4] == '-') offset = -offset;
      pc += offset;
    }
    else {
      int offset = stoi(code.substr(8));
      if (code[7] == '-') offset -= offset;
      if (code[2] == 'o' && reg[r] == 1) pc += offset;
      else if (code[2] == 'e' && reg[r]%2 == 0) pc += offset;
      else pc++;
    }
    if (debug) { cout << " pc : " << setw(3) << pc << setw(6) << reg[0] << setw(6) << reg[1] << endl; }
  }
  cout << reg[1] << endl;
}
