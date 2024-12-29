#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;
LL best = LLONG_MAX;
int debug = 0;
typedef vector<vector<int>> vvi;
int nr = 3;

#define MOVE(arm,action,stepMap) {(arm) = stepMap[(arm)][(action)] != -1 ? stepMap[(arm)][(action)] : (arm);}

void update(string& state, int r, char action, string code, vvi &arrpad, vvi &numpad, bool valid) {
  vvi stepMap = r < nr-1 ? arrpad : numpad;
  int L = '<', R = '>', U = '^', D = 'v', A = 'A';
  if (action != A) {
    MOVE(state[r],action,stepMap);
  }
  else {
    if (r == nr-1) {
      int p = state.find('.');
      if (code[p-nr] != state[r]) {
        valid = false;
      }
      else {
        state[p] = state[r];
      }
    }
    else {
      update(state, r+1, state[r], code, arrpad, numpad, valid);
    }
  }
  return;
}

int dist(string code,  vvi &arrpad, vvi &numpad) {
  string cur = string(nr, 'A')+"....";
  map<string,int> dist;
  queue<string> q;
  q.push(cur);
  dist[cur] = 0;
  cout << "here" << endl;
  while (!q.empty()) {
    string head = q.front();
    q.pop();
    int L = '<', R = '>', U = '^', D = 'v', A = 'A';
    vector<int> actions = {L, R, U, D, A};
    if (debug) cout << head << endl;
    for (int i = 0; i < actions.size(); i++) {
      string next = head;
      bool valid = true;
      update(next, 0, actions[i], code, arrpad, numpad, valid);
      if (valid) {
        if (dist.count(next) == 0) {
          dist[next] = dist[head]+1;
          q.push(next);
          if (next.substr(next.size()-4) == code) {
            return dist[next];
          }
        }
      }
    }
  }
  return 0;
}

int main(int argc, char *argv[])
{
  if (argc > 1) debug = 1;
  if (argc > 2) nr = stoi(argv[2]);
  vector<string> codes(5);
  for (int i = 0; i < 5; i++) {
    getline(cin, codes[i]);
  }
  vvi arrpad(256, vector<int>(256, -1));
  int L = '<', R = '>', U = '^', D = 'v', A = 'A';
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

  LL res = 0;
  for (auto code : codes) {
    LL d = dist(code, arrpad, numpad);
    res += stoll(code) * d;
    cout << d << " * " << stoi(code) << " = " << d*stoi(code) << endl;
  }
  cout << res << endl;
}

