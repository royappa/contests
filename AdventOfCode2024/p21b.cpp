#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;
LL best = LLONG_MAX;
int debug = 0;
typedef vector<vector<int>> vvi;
typedef vector<vector<string>> vvs;
typedef vector<vector<set<string>>> vvst;

typedef tuple<int,string> t2;
map<t2,LL> memo;
const int L = '<', R = '>', U = '^', D = 'v', A = 'A';

// number of keystrocks for the stack to type on the BACK robot's keyboard to make the NEAREST robot type these things
// the NEAREST robot's arm is at cur
// N is the number of BACK robots
LL numKeys(int N, string instructions, vvst &arrpaths)
{
  if (N == 0) { // there are no BACK robots, just punch the keys to move the current arm from C to T
    return instructions.size();
  }
  t2 key = {N, instructions};
  if (memo.count(key) > 0) {
    return memo[key];
  }
  // the BACK robot needs 
  LL result = 0;
  int cur = A;
  for (int i = 0; i < instructions.size(); i++) {
    LL best = 1LL<<62;
    for (auto path : arrpaths[cur][instructions[i]]) {
      best = min(best, numKeys(N-1, path+char(A), arrpaths));
    }
    result += best;
    cur = instructions[i];
  }
  return memo[key] = result;
}

string path(map<int,int> &prev, int last, vvi &numpad) {
  string p = string(1, char(last));
  while (prev[last] != -1) {
    p += char(prev[last]);
    last = prev[last];
  }
  reverse(p.begin(), p.end());
  string s = "";
  for (int i = 0; i < (int)p.size()-1; i++) {
    int dir[] = {L,R,U,D};
    for (auto d : dir) {
      if (numpad[p[i]][d] == p[i+1]) {
        s += char(d);
        break;
      }
    }
  }
  return s;
}
string getPath(int cur, int target, vvi &numpad) {
  queue<int> q;
  q.push(cur);
  map<int,int> prev;
  prev[cur] = -1;
  while (!q.empty()) {
    int head = q.front();
    q.pop();
    int dir[] = {L,R,U,D};
    for (auto d : dir) {
      int next = numpad[head][d];
      if (next != -1 && prev.count(next) == 0) {
        prev[next] = head;
        q.push(next);
        if (next == target) {
          string s = path(prev, next, numpad);
          if (debug > 10) {cout << "path from " << (char)cur << " to " << (char)target << " is " << s << endl;}
          return s;
        }
      }
    }
  }
  return "";
}

bool valid(int cur, int next, string path, vvi &numpad) {
  int n = path.size();
  for (int i = 0; i < n; i++) {
    if (numpad[cur][path[i]] == -1) {
      return false;
    }
    cur = numpad[cur][path[i]];
  }
  return cur == next;
}

set<string> getInstructions(string code, vvi &numpad) {
  vector<set<string>> pieces(4);
  int cur = A;
  for (int i = 0; i < 4; i++) {
    string path = getPath(cur, code[i], numpad);
    sort(path.begin(), path.end());
    do {
      if (valid(cur, code[i], path, numpad)) {
        pieces[i].insert(path);
      }
      else {
        if (debug > 10) { cout << "Not valid " << char(cur) << " " << code[i] << " " << path << endl;}
      }
    } while (next_permutation(path.begin(), path.end()));
    cur = code[i];
  }
  set<string> s;
  for (auto x : pieces[0]) {
    for (auto y : pieces[1]) {
      for (auto z : pieces[2]) {
        for (auto w : pieces[3]) {
          string a = string(1, char(A));
          s.insert(x+a+y+a+z+a+w+a);
        }
      }
    }
  }
  return s;
}

int main(int argc, char *argv[])
{
  if (argc > 1) debug = atoi(argv[1]);
  vector<string> codes(5);
  for (int i = 0; i < 5; i++) {
    getline(cin, codes[i]);
  }
  vvi arrpad(256, vector<int>(256, -1));
  vvi arrdist(256, vector<int>(256, -1));
  arrpad[U][R] = A;
  arrpad[U][D] = D;
  arrpad[A][L] = U;
  arrpad[A][D] = R;
  arrpad[L][R] = D;
  arrpad[D][L] = L;
  arrpad[D][U] = U;
  arrpad[D][R] = R;
  arrpad[R][L] = D;
  arrpad[R][U] = A;
  arrdist[A][U] = arrdist[A][R] = arrdist[U][A] = arrdist[R][A] = 1;
  arrdist[A][D] = arrdist[D][A] = 2;
  arrdist[A][L] = arrdist[L][A] = 3;
  arrdist[U][D] = arrdist[D][U] = 1;
  arrdist[U][L] = arrdist[U][R] = arrdist[L][U] = arrdist[R][U] = 2;
  arrdist[D][L] = arrdist[D][R] = arrdist[L][D] = arrdist[R][D] = 1;
  arrdist[A][A] = arrdist[D][D] = arrdist[L][L] = arrdist[R][R] = arrdist[U][U] = 0;
  vvi numpad(256, vector<int>(256, -1));
  numpad['7'][R] = '8';
  numpad['7'][D] = '4';
  numpad['8'][L] = '7';
  numpad['8'][R] = '9';
  numpad['8'][D] = '5';
  numpad['9'][L] = '8';
  numpad['9'][D] = '6';
  numpad['4'][U] = '7';
  numpad['4'][R] = '5';
  numpad['4'][D] = '1'; 
  numpad['5'][U] = '8';
  numpad['5'][R] = '6';
  numpad['5'][D] = '2';
  numpad['5'][L] = '4';  
  numpad['6'][U] = '9';
  numpad['6'][L] = '5';
  numpad['6'][D] = '3';
  numpad['1'][U] = '4';
  numpad['1'][R] = '2';    
  numpad['2'][U] = '5';
  numpad['2'][R] = '3';
  numpad['2'][D] = '0';
  numpad['2'][L] = '1'; 
  numpad['3'][U] = '6';
  numpad['3'][L] = '2';
  numpad['3'][D] = 'A';
  numpad['0'][U] = '2';
  numpad['0'][R] = 'A';
  numpad['A'][U] = '3';
  numpad['A'][L] = '0';

/*
    +---+---+
    | ^ | A |
+---+---+---+
| < | v | > |
+---+---+---+
*/
  vvst arrpaths(256, vector<set<string>>(256));
  arrpaths[A][L].insert("v<<"); // arrpaths[A][L].insert("<v<"); 
  arrpaths[L][A].insert(">>^"); // arrpaths[L][A].insert(">^>");
  arrpaths[A][U].insert("<");   
  arrpaths[U][A].insert(">");
  arrpaths[A][R].insert("v");   
  arrpaths[R][A].insert("^");
  arrpaths[A][D].insert("<v"); arrpaths[A][D].insert("v<");   
  arrpaths[D][A].insert("^>"); arrpaths[D][A].insert(">^");
  arrpaths[U][L].insert("v<"); 
  arrpaths[L][U].insert(">^");
  arrpaths[U][D].insert("v");   
  arrpaths[D][U].insert("^");
  arrpaths[U][R].insert("v>"); arrpaths[U][R].insert(">v");  
  arrpaths[R][U].insert("<^"); arrpaths[R][U].insert("^<");
  arrpaths[D][L].insert("<");   
  arrpaths[L][D].insert(">");
  arrpaths[D][R].insert(">");   
  arrpaths[R][D].insert("<");
  arrpaths[L][R].insert(">>");  
  arrpaths[R][L].insert("<<");
  arrpaths[A][A].insert("");
  arrpaths[L][L].insert("");
  arrpaths[U][U].insert("");
  arrpaths[R][R].insert("");
  arrpaths[D][D].insert("");

  int numRobots = 0;
  if (argc > 2) numRobots = stoi(argv[2]);
  if (numRobots < 1) { cout << "Numrobots must be >= 1" << endl; exit(1); }
  // there are N robots, each with one arm and one keyboard
  // we have some instructions to type on the nearest robot keyboard
  // these instructions are typed by a stack of N-1 robots
  // behind the furthest back of these N-1 robots is just us, pushing on a keyboard of the furthest back robot
  // Initially all the robots' arms are on A
  // LL res = numKeys(numRobots-1, instructions, arrpaths);
  // cout << "Tot = " << res << endl;
  // exit(1);

  LL res = 0;
  for (auto code : codes) {
    set<string> iset = getInstructions(code, numpad);
    LL best = 1LL<<62;
    for (auto instructions : iset) {
      if (debug > 0) { cout << code << " " << instructions << endl; }
      memo.clear();
      LL d = numKeys(numRobots-1, instructions, arrpaths);
      if (d < best) {
        best = d;
      }
    }
    res += stoll(code) * best;
    cout << best << " * " << stoi(code) << " = " << best*stoi(code) << endl;
  }
  cout << res << endl;
}

