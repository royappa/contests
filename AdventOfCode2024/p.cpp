#include <bits/stdc++.h>
#include <fstream>
using namespace std;


int main(int argc, char *argv[])
{
  cout << "test" << endl;
  int A = 38610541, B = 0, C = 0;
  cout << "A (start) = " << A << endl;
  while (A != 0) {
    B = (A>>((A%8)^1))^(((A%8)^1)^5); cout << "B = " << B << endl;
    /*
    B = A%8; cout << "B = " << B << endl;
    B ^= 1;  cout << "B = " << B << endl;
    C = A >> B; cout << "C = " << C << endl;
    B ^= 5; cout << "B = " << B << endl;
    B ^= C; cout << "B = " << B << endl;
    */
    cout << B%8 << endl;
    A /= 8; cout << "A = " << A << endl;
  }
  cout << "end" << endl;

   
}