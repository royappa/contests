#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;

LL best = LLONG_MAX;

typedef pair<int,int> pii;
int debug = 0;

// state = (r3, r2, r1, nums) where
// ri = position of robot i's arm  (robot 3 = closest to me, robot 1 = over numberpad)
// nums = string of numbers emitted so far
// BFS until we reach nums=code

typedef tuple<int, int, int, string> t4;

#define MOVE(arm,action,stepMap) {(arm) = stepMap[(arm)][(action)] != -1 ? stepMap[(arm)][(action)] : (arm);}

int dist(string code,  vector<vector<int>> &arrpad,  vector<vector<int>> &numpad) {
  t4 cur = {'A', 'A', 'A', ""};
  map<t4,int> dist;
  dist[cur] = 0;
  queue<t4> q;
  q.push(cur);
  while (!q.empty()) {
    t4 head = q.front();
    q.pop();
    int L = '<', R = '>', U = '^', D = 'v', A = 'A';
    vector<int> actions = {L, R, U, D, A};
    for (int i = 0; i < actions.size(); i++) {
      auto [arm3k2, arm2k1, arm1np, out] = head; // arm position of robot i on keyboard j
      if (debug) printf("(%c,%c,%c,%s)\n", arm3k2, arm2k1, arm1np, out.c_str());      
      bool valid = true;
      int action = actions[i];
      if (action != A) {
        if (debug) cout << "move arm3k2 " << (char)arm3k2 << " " << (char)action << " = " << (char)arrpad[arm3k2][action] << endl;
        MOVE(arm3k2,action,arrpad);
      }
      else { // I push the action button on k3 (action == A). This presses something on k2 - whatever arm3 is pointing to on k2.
        action = arm3k2;
        if (action != A) {
          if (debug) cout << "move arm2k1 " << (char)arm2k1 << " " << (char)action << " = " << (char)arrpad[arm2k1][action] << endl;
          MOVE(arm2k1, action, arrpad);
        }
        else {
          action = arm2k1;
          if (action != A) {
            if (debug) cout << "move arm1np " << (char)arm1np << " " << (char)action << " = " << (char)numpad[arm1np][action] << endl;
            MOVE(arm1np, action, numpad);
          }
          else {
            // Some numberpad button has been pushed
            int len = out.size();
            if (code[len] != arm1np) {
              valid = false;
            }
            else {
              out += arm1np;
              assert(code.substr(0, out.size()) == out);
            }
          }
        }
      }
      if (valid) {
        t4 nextNode = {arm3k2, arm2k1, arm1np, out};
        if (dist.count(nextNode) == 0) {
          dist[nextNode] = dist[head]+1;
          if (debug) {
            auto [x,y,z,w] = head;
            printf("adding (%c,%c,%c,%s) with distance %d from (%c,%c,%c,%s) based on action %c\n", 
              arm3k2, arm2k1, arm1np, out.c_str(),
              dist[nextNode],
              x, y, z, w.c_str(),
              actions[i]);
          }
          q.push(nextNode);
          if (out == code) {
            return dist[nextNode];
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
  vector<string> codes(5);
  for (int i = 0; i < 5; i++) {
    getline(cin, codes[i]);
  }
  vector<vector<int>> arrpad(256, vector<int>(256, -1));
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
  vector<vector<int>> numpad(256, vector<int>(256, -1));
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

  int res = 0;
  for (auto code : codes) {
    int d = dist(code, arrpad, numpad);
    res += stoi(code) * d;
    cout << d << " * " << stoi(code) << " = " << d*stoi(code) << endl;
    if (debug) break;
  }
  cout << res << endl;
}

