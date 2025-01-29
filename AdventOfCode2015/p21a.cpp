#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int debug = 0;
typedef vector<int> vi;
typedef vector<vi> vvi;

// return true if I win on my turn
bool beats(vvi v, int turn) {
  if (debug > 10) printf("%d %d %d vs %d %d %d turn = %d\n", v[turn][0], v[turn][1], v[turn][2], v[1-turn][0], v[1-turn][1], v[1-turn][2], turn);
  if (v[1-turn][0] <= 0) return true; // opponent is dead
  int dam = max(1, max(0, v[turn][1]-v[1-turn][2]));
  v[1-turn][0] -= dam;
  return !beats(v, 1-turn);
}

int main(int argc, char *argv[])
{
  if (argc > 1) { debug = atoi(argv[1]); }
  string line;

  vvi weapons = {
    {8, 4, 0},
    {10, 5, 0},
    {25, 6, 0},
    {40, 7, 0},
    {74, 8, 0}
  };

  vvi armors = {
    {13, 0, 1},
    {31, 0, 2},
    {53, 0, 3},
    {75, 0, 4},
    {102, 0, 5}
  };

  vvi rings = {
      {25, 1, 0},
      {50, 2, 0},
      {100, 3, 0},
      {20, 0, 1},
      {40, 0, 2},
      {80, 0, 3}
  };  

  int best = INT_MAX;
  for (int i = 0; i < weapons.size(); i++) {
    for (int j = 0; j < armors.size()+1; j++) {
      for (int m = 0; m < (1<<rings.size()); m++) {
        if (__builtin_popcount(m) > 2) continue;
        int rcost = 0, rdamage = 0, rarmor = 0;
        for (int k = 0; k < rings.size(); k++) {
          if (m & (1<<k)) {
            rcost += rings[k][0];
            rdamage += rings[k][1];
            rarmor += rings[k][2];
          }
        }
        int cost = weapons[i][0], damage = weapons[i][1], armor = 0;
        if (j != armors.size()) {
          cost += armors[j][0];
          armor += armors[j][2];
        }
        cost += rcost;
        damage += rdamage;
        armor += rarmor;
        if (beats({{100,damage,armor}, {100,8,2}}, 0)) {
          if (cost < best) {
            if (debug) printf("cost: %d, damage: %d (%d), armor: %d (%d), rings: %d\n", cost, damage, i, armor, j, m);
            best = cost;
          }
        }          
      }
    }
  }
  cout << best << endl;  
}
