#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int debug = 0;
typedef tuple<int,int,int,int,int,int,int> state; // turn, mana, hp, bhp, shield, poison, recharge
typedef pair<int,state> pis;

void dump(pis &p) {
  auto [curCost, curState] = p;
  auto [a,b,c,d,e,f,g] = curState;
  cout << "Cost: " << setw(8) << curCost << ": ";
  cout << setw(4) << a << setw(4) << b << setw(4) << c
      << setw(4) << d << setw(4) << e << setw(4) << f << setw(4) << g << endl; 
}
int main(int argc, char *argv[])
{
  if (argc > 1) { debug = atoi(argv[1]); }
  string line;
  // int startMana = 250, startHp = 10, startBhp = 14, bossDamage = 8;
  int startMana = 500, startHp = 50, startBhp = 58, bossDamage = 9;
  priority_queue<pis,vector<pis>,greater<pis>> pq;
  map<state,int> dist;

  state start = {0, startMana, startHp, startBhp, 0, 0, 0}; // turn, mana, hp, bhp, shield, poison, recharge
  dist[start] = 0; // how much mana to go to a state
  pq.push({0,start});
  map<pis,pis> prev;
  while (!pq.empty()) {
    auto [cost, state] = pq.top();
    pq.pop();
    if (cost > dist[state]) continue;
    auto [turn, mana, hp, bhp, shield, poison, rechrg] = state;
    if (bhp <= 0) { 
      cout << "Cost = " << cost << endl; 
      if (debug) {
        pis cur = {cost, state};
        while (prev.count(cur) != 0) {
          dump(cur);
          cur = prev[cur];
        }
        dump(cur);      
      }
      exit(1); }
    if (hp <= 0) continue;
    vector<pis> v;
    if (turn == 0) {
      if (shield > 0) shield--;
      if (poison > 0) { poison--; bhp -= 3; }
      if (rechrg > 0) { rechrg--; mana += 101; }
      if (mana >= 53)                 { v.push_back({53,  {1-turn, mana-53, hp,   bhp-4, shield, poison, rechrg}}); };
      if (mana >= 73)                 { v.push_back({73,  {1-turn, mana-73, hp+2, bhp-2, shield, poison, rechrg}}); };
      if (shield == 0 && mana >= 113) { v.push_back({113, {1-turn, mana-113,    hp,   bhp,   6,      poison, rechrg}}); };
      if (poison == 0 && mana >= 173) { v.push_back({173, {1-turn, mana-173,    hp,   bhp,   shield, 6,      rechrg}}); };
      if (rechrg == 0 && mana >= 229) { v.push_back({229, {1-turn, mana-229,    hp,   bhp,   shield, poison, 5     }}); };
    }
    else {
      int armor = 0;
      if (shield > 0) { shield--; armor = 7; }
      if (poison > 0) { poison--; bhp -= 3; }
      if (rechrg > 0) { rechrg--; mana += 101; }
      if (bhp > 0) {
        if (armor == 0) { hp -= bossDamage; } else { hp -= max(1, bossDamage-armor); }
      }
      v.push_back({0, {1-turn, mana, hp, bhp, shield, poison, rechrg}});
    }
    for (auto [dcost, nbrState] : v) {
      int newCost = cost + dcost;
      if (dist.count(nbrState) == 0 || newCost < dist[nbrState]) {
        dist[nbrState] = newCost;
        pq.push({newCost, nbrState});
        prev[{newCost, nbrState}] = {cost, state};
      }
    }
  }
  cout << "Fail" << endl;
}
