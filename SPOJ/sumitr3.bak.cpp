#include <iostream>
using namespace std;
int m[5000],e[5000],r,i,D;int f(int x,int y){int i=(x-1)*x/2+y;return e[i]=(e[i]?e[i]:x-r?m[i]+(f(x+1,y)>?f(x+1,y+1)):m[i]);}main(){cin>>D;while(D-->0){cin>>r;for(i=1;i<=r*(r+1)/2;i++)cin>>m[i],e[i]=0;cout<<f(1,1)<<"\n";}}
