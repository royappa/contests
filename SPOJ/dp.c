#include <stdio.h>
#define MAXTOTAL 10000

// This can be very big... long long may not be enough and
// you may need to use Big Integer
long long nway[MAXTOTAL+1];

// Assume we have 5 different coins here
int coin[5] = { 1 };

void main() {
  int i,j,n,v,c;
  scanf("%d",&n);
  v = 1;
  nway[0] = 1;
  for (i=0; i<v; i++) {
    c = coin[i];
    for (j=c; j<=n; j++)
    {
      nway[j] += nway[j-c];
    }
  }
  printf("%lld\n",nway[n]);
}
