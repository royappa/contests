#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;

int prog[] = {2,4,1,1,7,5,1,5,4,3,5,5,0,3,3,0};

int val[16];

LL best = LLONG_MAX;

/*
2,4 B = A%8     bst
1,1 B ^= 1      bxl
7,5 C = A >> B  cdv
1,5 B ^= 5      bxl
4,3 B ^= C      bxc
5,5 OUT B       out
0,3 A = A >> 3  adv
3,0 IFA<>0JMP 0 jnz
*/

void run(int p, int A) {
  int B = (A>>((A%8)^1))^(((A%8)^1)^5);
  if (B%8 != prog[p]) return;
  val[p] = A%8;
  cout << "p = " << p << ": ";
  LL value = A/8;
  for (int i = p; i >= 0; i--) { value = value*8LL+val[i]; cout << val[i]; cout << " ";} cout << "; " << value << endl;
  
  if (p == 15) {
    value = A/8;
    for (int i = 15; i >= 0; i--) { 
        value = value*8LL+val[i];
    }
    best = min(best, value);
    return;
  }
  int high7A = A >> 3;
  int mask = (1<<7)-1;
  for (int newA = 0; newA < (1<<10); newA++) { // last 7 of new should match top 7 of A
    if ((newA&mask) != high7A) continue;
    run(p+1, newA);
  }
}

int main(int argc, char *argv[])
{
  /*
  cout << "test" << endl;
  int A = 38610541, B = 0, C = 0;
  while (A != 0) {
    B = A%8;
    B ^= 1;
    C = A >> B;
    B ^= 5;
    B ^= C;
    B %= 8;
    cout << B << endl;
    A >>= 3;
  }
  cout << "end" << endl;
  */

  for (int lastA = 0; lastA < (1<<10); lastA++) {
    run(0, lastA);
  }
  for (int i = 0; i < 16; i++) {
    cout << val[i] << (i < 15 ? "," : "");
  }  
  cout << endl;
 cout << "best = " << best << endl;

}

