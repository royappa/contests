#include <bits/stdc++.h>

using namespace std;

int main() {
   vector<int> a(6), b(6);
   map<int,int> all;
   for (int i = 0; i < 6; i++) {
       cin >> a[i];
   }
   for (int i = 0; i < 6; i++) {
       cin >> b[i];
   }
   int bc = 0, bv = 0;
   for (auto x : a) {
       for (auto y : b) {
           all[x+y]++;
       }
   }
   for (auto z : all) {
       if (z.second > bc) {
           bc = z.second;
           bv = z.first;
       }
   }
   cout << bv << endl;
   return 0;
}