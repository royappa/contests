#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;

const LL bigplus = 10000000000000LL;

typedef pair<LL,LL> pLL;

// given a,b > 0, return x,y s.t. x*a+y*b = gcd(a,b);
void eea2(LL a, LL b, LL& x, LL& y)
{
	if (a % b == 0)
	{
		x = 0LL;
		y = 1LL;
	}
	else
	{
		LL x1, y1;
		eea2(b%a, a, x1, y1);
		x = y1 - x1*(b/a);
    y = x1;
	}
	return;
}

LL gcd(LL a, LL b) {
	return b == 0 ? a : gcd(b, a % b);
}

void get2(string s, LL &a, LL &b) {
  regex r(R"((\d+).*?(\d+))");
  smatch m;
  regex_search(s, m, r);
  a = stoll(m[1]);
  b = stoll(m[2]);
}

LL det(LL a1, LL b1, LL a2, LL b2) {
  return a1*b2-a2*b1;
}
LL solve(LL xa, LL ya, LL xb, LL yb, LL xp, LL yp) {
  // a = number of A button pushes
  // b = number of B button pushes
  // Any play consists of a pushes & b pushes, thus
  // a*xa+b*xb = xp
  // a*ya+b*yb = yp
  // find all viable solutions of first equation, filter by those matching second equation, take min.
  LL d = gcd(xa, xb);

  LL D = det(xa, xb, ya, yb);
  LL Da = det(xp, xb, yp, yb);
  LL Db = det(xa, xp, ya, yp);
  if (D == 0 || (Da%D != 0) || (Db%D != 0)) {
    cout << "fail" << endl;
    return 0;
  }
  LL ar = Da/D, br = Db/D;
  return 3*ar+br;

  LL s, t;
  eea2(xa, xb, s, t);
  // cout << "e1: " << xa << " " << xb << "" << xp << endl;
  printf("%lld * %lld + %lld * %lld = %lld\n", s, xa, t, xb, d);
  if (xp%d) {
    cout << "fail" << endl;
    return 0;
  }
  LL h = xp/d;
  printf("h = %lld\n", h);
  LL u = xa / d, v = xb / d;
  printf("(%lld+k*%lld)*%lld + (%lld-k*%lld)*%lld = %lld\n", s, v, xa, t, u, xb, d);
  printf("%lld*(%lld+k*%lld)*%lld + %lld*(%lld-k*%lld)*%lld = %lld*%lld\n", h, s, v, xa, h, t, u, xb, h, d);

  LL minsol = 1LL<<60;
  for (LL k = -10; k <= 10; k++) {
    LL ar = h*(s+k*v), br = h*(t-k*u);
    assert(ar*xa+br*xb == xp);
    printf("%lld*%lld+%lld*%lld = %lld\n", ar, xa, br, xb, xp);
    if (ar < 0 || ar > 100 || br < 0 || br > 100) continue;
    assert(ar*xa+br*xb == xp);
    if (k%10000==0) cout << "*" << endl;
    if (ar*ya + br*yb != yp) continue;
    cout << "found: " << ar << " " << br << endl;
    assert(ar*ya+ar*yb == yp);
    if (3*ar+br < minsol) {
      minsol = 3*ar+br;
    }
  }
  return minsol;

}

int main(int argc, char *argv[])
{

  string line;
  LL res = 0;
  do {
    LL xa, ya, xb, yb, xp, yp;
    getline(cin, line); cout << line << endl;
    get2(line, xa, ya);
    getline(cin, line); cout << line << endl;
    get2(line, xb, yb);
    getline(cin, line); cout << line << endl;
    get2(line, xp, yp);
    xp += bigplus;
    yp += bigplus;
    LL r = solve(xa, ya, xb, yb, xp, yp);
    cout << r << endl;
    res += r;
  } while (getline(cin, line));
  
  cout << "Result: " << res << endl;
}

