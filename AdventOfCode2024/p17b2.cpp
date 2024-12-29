#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;

// int prog[] = {2,4,1,1,7,5,1,5,4,3,5,5,0,3,3,0};
int prog[] = {7,5,4,3,4,5,3,4,6};
int n;

int val[16];

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
  if (p > n) {
    cout << "done" << endl;
    return;
  }
  LL B = (A>>((A%8)^1))^(((A%8)^1)^5);
  if (B%8 != prog[p]) return;
  val[p] = A%8;
  A >>= 3;
  run(p+1, A);
}

int main(int argc, char *argv[])
{
  n = sizeof(prog) / sizeof(int);

  run(0, 38610541);
  for (int i = 0; i < n; i++) {
    cout << val[i] << (i < n-1 ? "," : "");
  }  
  cout << endl;
  LL value = 0;
  for (int i = n; i >= 0; i--) {
    value = (value << 3) + (LL) val[i];
  }
  cout << value << endl;

}

