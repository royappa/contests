#include "assert.h"
#include <iostream>

typedef long long int LL;

using namespace std;

LL getNumberOfCardsInFullHouse(LL floors) {
  return 3 * floors * (floors + 1) / 2 - floors;
}

LL solve(LL n) {
  LL res = 0;
  for (LL floors = 1 ; getNumberOfCardsInFullHouse(floors) <= n ; floors++)
    if ((n + floors) % 3 == 0)
      res++;
  return res;
}

int main() {
  LL n; cin >> n;
  cout << solve(n);
}